<?php
// ----------------------------------------------------------------------
// Newsletter for phpShop
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

/*
*************************************************************************/
class newsletter_email {
  var $classname = "newsletter_email";

  /**************************************************************************
  ** name: validate_add()
  ***************************************************************************/
    function validate_add(&$d) {
    $db = new ps_DB;

    if (!$d["email_name"]) {
      $d["error"] = "ERROR:  You must enter your name to be on our newsletter.";
      return False;
    }
    if (!$d["email_address"]) {
      $d["error"] = "ERROR:  You must enter your email address to be on our newsletter.";
      return False;
    }
    // Check for duplicate entry
    $q  = "SELECT * from newsletter_email WHERE email_address='";
    $q .= $d["email_address"] . "'";
    $db->query($q);
    if ($db->next_record()) {
      $d["error"]  = "ERROR: This email address is already on our newsletter. ";
      return False;
    }
    else {
      return True;
    }
  }

  /**************************************************************************
  ** name: validate_delete()
  ***************************************************************************/
    function validate_delete(&$d) {

    $db = new ps_DB;

    if (!$d["email_id"]) {
      $d["error"] = "ERROR:  No email ID was selected to delete.";
      return False;
    }

    // Check if it's in there
    $q  = "SELECT * FROM newsletter_email WHERE email_id='";
    $q .= $d["email_id"] . "'";
    $db->query($q);
    if (!$db->next_record()) {
      $d["error"]  = "ERROR: That email ID is not in our database. ";
      return False;
    }

    return True;
  }


  /**************************************************************************
  ** name: add()
  ***************************************************************************/
  function add(&$d) {
    $db = new ps_DB;

    $email_id = md5(uniqid("BrettODonnellIsCool"));

    if ($this->validate_add($d)) {
      $q = "INSERT INTO newsletter_email (email_id, email_name, email_address) ";
      $q .= "VALUES ('";
      $q .= $email_id . "','";
      $q .= $d["email_name"] . "','";
      $q .= $d["email_address"] . "')";
      $db->query($q);
      $d["error"] = "Your name and email has been added to our database.";
    }else {
      return False;
    }
  }


  /**************************************************************************
  ** name: delete()
  ***************************************************************************/
  function delete(&$d) {
    $db = new ps_DB;

    if (!$this->validate_delete($d)) {
      return False;
    }

    $q="DELETE FROM newsletter_email WHERE email_id='" . $d["email_id"] . "'";
    $db->query($q);

    return True;
  }


}
?>