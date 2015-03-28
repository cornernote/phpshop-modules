<?php
// ----------------------------------------------------------------------
// DB Backup
// ----------------------------------------------------------------------
// Module designed by Mr PHP
// W: www.mrphp.com.au
// E: info@mrphp.com.au
// P: +61 418 436 690
// ----------------------------------------------------------------------
// LICENSE
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License (GPL)
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// To read the license please visit http://www.gnu.org/copyleft/gpl.html
// ----------------------------------------------------------------------

class backup_db {
  var $classname="backup_db";


  /**************************************************************************
  ** name: send_backup_database()
  **************************************************************************/

  function send_backup_database()
  {
    $db=new ps_DB;

    $crlf="\n";
    // doing some DOS-CRLF magic...
    if (!isset($HTTP_USER_AGENT))
    {
      if (!empty($HTTP_SERVER_VARS) && isset($HTTP_SERVER_VARS['HTTP_USER_AGENT']))
        $HTTP_USER_AGENT = $HTTP_SERVER_VARS['HTTP_USER_AGENT'];
      else
        $HTTP_USER_AGENT = getenv('HTTP_USER_AGENT');
    }

    $client = $HTTP_USER_AGENT;
    if(ereg('[^(]*\((.*)\)[^)]*',$client,$regs))
    {
      $os = $regs[1];
      // this looks better under WinX
      if (eregi("Win",$os))
        $crlf="\r\n";
    }

    $db->query("SHOW TABLES");
    if($db->num_rows()==0){ $backup_db .= "ERROR: NO TABLES FOUND"; }
    else
    {
      $backup_db .= "# BrettODonnell.com Backup Wizard MySQL-Dump$crlf";
      $backup_db .= "# http://www.brettodonnell.com$crlf";
      $backup_db .= "#$crlf";
      $backup_db .= "# Database: ". DB_NAME ."$crlf";
      $backup_db .= "#$crlf$crlf$crlf";

      while($db->next_record())
      {
        $table = $db->f(0);
        $backup_db .= "#$crlf";
        $backup_db .= "# Table Structure For Table: '$table' $crlf";
        $backup_db .= "#$crlf";
        $backup_db .= $crlf;
        $backup_db .= $this->get_table_def($table, $crlf)." $crlf$crlf";

        if($table!="session_stats"){
          $backup_db .= "#$crlf";
          $backup_db .= "# Dumping Data For Table '$table'$crlf";
          $backup_db .= "#$crlf";
          $backup_db .= $crlf;
          $backup_db .= $this->get_table_content($table, $crlf)." $crlf$crlf";
        }
      }
    }

    header("Content-disposition: filename=". DB_NAME .".sql");
    header("Content-type: application/octetstream");
    header("Pragma: no-cache");
    header("Expires: 0");
    echo $backup_db;
        exit;
  }


  /**************************************************************************
  ** name: get_table_content()
  **************************************************************************/

  function get_table_content($table,$crlf)
  {
    $db=new ps_DB;
    $db->query("SELECT * FROM $table");
    while($db->next_record())
    {
      @set_time_limit(60); // HaRa

      $schema_insert .= "INSERT INTO $table VALUES (";

      for($j=0; $j<$db->num_fields(); $j++)
      {
        if($db->f($j) != "")
        {
          $dummy = "";
          $srcstr = $db->f($j);
          for($xx=0; $xx < strlen($srcstr); $xx++)
          {
            $yy = strlen($dummy);
            if($srcstr[$xx] == "\\") $dummy .= "\\\\";
            if($srcstr[$xx] == "'") $dummy .= "\\'";
            if($srcstr[$xx] == "\"") $dummy .= "\\\"";
            if($srcstr[$xx] == "\x00") $dummy .= "\\0";
            if($srcstr[$xx] == "\x0a") $dummy .= "\\n";
            if($srcstr[$xx] == "\x0d") $dummy .= "\\r";
            if($srcstr[$xx] == "\x08") $dummy .= "\\b";
            if($srcstr[$xx] == "\t") $dummy .= "\\t";
            if($srcstr[$xx] == "\x1a") $dummy .= "\\Z";
            if(strlen($dummy) == $yy) $dummy .= $srcstr[$xx];
          }
          $schema_insert .= " '".$dummy."',";
        }
        else
          $schema_insert .= " '',";
      }
      $schema_insert = ereg_replace(",$", "", $schema_insert);
      $schema_insert .= "); $crlf";
    }
    return $schema_insert;
  }


  /**************************************************************************
  ** name: get_table_def()
  **************************************************************************/

  function get_table_def($table, $crlf)
  {
    $schema_create .= "DROP TABLE IF EXISTS $table;$crlf";
    $schema_create .= "CREATE TABLE $table ($crlf";

    $db=new ps_DB;
    $db->query("SHOW FIELDS FROM $table");
    while($db->next_record())
    {
      $schema_create .= "   " . $db->f("Field") . "  " . $db->f("Type");
      if($db->f("Default"))
      {
        $schema_create .= " DEFAULT '" . $db->f("Default") . "'";
      }
      if($db->f("Null") != "YES")
      {
        $schema_create .= " NOT NULL";
      }
      if($db->f("Extra") != "")
      {
        $schema_create .= " " . $db->f("Extra");
      }
      $schema_create .= ",$crlf";
    }

    $schema_create = ereg_replace(",".$crlf."$", "", $schema_create);

    $db->query("SHOW KEYS FROM $table");
    while($db->next_record())
    {
      $kname=$db->f("Key_name");
      $comment=$db->f("Comment");
      if(($kname != "PRIMARY") && ($db->f("Non_unique") == 0))
        $kname="UNIQUE|$kname";
      if($comment=="FULLTEXT")
        $kname="FULLTEXT|$kname";
      if(!isset($index[$kname]))
        $index[$kname] = array();
      $index[$kname][] = $db->f("Column_name");
    }

    while(list($x, $columns) = @each($index))
    {
      $schema_create .= ",$crlf";
      if($x == "PRIMARY")
        $schema_create .= "   PRIMARY KEY (";
      elseif (substr($x,0,6) == "UNIQUE")
        $schema_create .= "   UNIQUE " .substr($x,7)." (";
      elseif (substr($x,0,8) == "FULLTEXT")
        $schema_create .= "   FULLTEXT ".substr($x,9)." (";
      else
        $schema_create .= "   KEY $x (";
      $schema_create .= implode($columns,", ") . ")";
    }

    $schema_create .= "$crlf);";
    if(get_magic_quotes_gpc()) {
      return (stripslashes($schema_create));
    } else {
      return ($schema_create);
    }
  }


} // end class

?>