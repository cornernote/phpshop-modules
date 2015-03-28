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
class newsletter_letter {
  var $classname = "newsletter_letter";


  /**************************************************************************
  ** name: validate_add()
  ***************************************************************************/
    function validate_add(&$d) {
    $db = new ps_DB;

    if (!$d["letter_subject"]) {
      $d["error"] = "ERROR:  You must enter some a subject for the newsletter.";
      return False;
    }
    if (!$d["letter_detail"]) {
      $d["error"] = "ERROR:  You must enter some detail for the newsletter.";
      return False;
    }
    // Check an open letter
    $q  = "SELECT * from newsletter_letter WHERE letter_done='0'";
    $db->query($q);
    if ($db->next_record()) {
      $d["error"]  = "ERROR: There is already a letter waiting to be sent. ";
      return False;
    }

    return True;

  }


  /**************************************************************************
  ** name: validate_update()
  ***************************************************************************/
    function validate_update(&$d){
    $db = new ps_DB;

    if (!$d["letter_id"]) {
      $d["error"] = "ERROR:  No letter ID was selected to update.";
      return False;
    }
    if (!$d["letter_subject"]) {
      $d["error"] = "ERROR:  You must enter a subject for the newsletter.";
      return False;
    }
    if (!$d["letter_detail"]) {
      $d["error"] = "ERROR:  You must enter some detail for the newsletter.";
      return False;
    }
    // Check if it's been sent already
    $q  = "SELECT * FROM newsletter_letter WHERE letter_id='";
    $q .= $d["letter_id"] . "' AND letter_done='1'";
    $db->query($q);
    if ($db->next_record()) {
      $d["error"]  = "ERROR: That letter has already been sent. ";
      return False;
    }

    return True;
  }


  /**************************************************************************
  ** name: validate_delete()
  ***************************************************************************/
    function validate_delete(&$d) {

    $db = new ps_DB;

    if (!$d["letter_id"]) {
      $d["error"] = "ERROR:  No letter ID was selected to delete.";
      return False;
    }

    // Check if it's been sent already
    $q  = "SELECT * FROM newsletter_letter WHERE letter_id='";
    $q .= $d["letter_id"] . "' AND letter_done='1'";
    $db->query($q);
    if ($db->next_record()) {
      $d["error"]  = "ERROR: That letter has already been sent. ";
      return False;
    }

    return True;
  }


  /**************************************************************************
  ** name: validate_letter_send()
  ***************************************************************************/
  function validate_letter_send(&$d) {

    $db = new ps_DB;

    // Check if there is a letter to send
    $q  = "SELECT * FROM newsletter_letter WHERE letter_done='0'";
    $db->query($q);
    if (!$db->next_record()) {
      $d["error"]  = "ERROR: There is no letter to send. ";
      return False;
    }

    return True;
  }


  /**************************************************************************
  ** name: add()
  ***************************************************************************/
  function add(&$d) {
    $db = new ps_DB;

    if ($this->validate_add($d)) {
      $db->query("UPDATE newsletter_email SET email_done='0'");
      $q = "INSERT INTO newsletter_letter (letter_subject, letter_detail) ";
      $q .= "VALUES ('";
      $q .= $d["letter_subject"] . "', '";
      $q .= $d["letter_detail"] . "')";
      $db->query($q);
      $d["error"] = "Your letter is now ready to send.";
      return True;
    }else {
      return False;
    }
  }


  /**************************************************************************
  ** name: update()
  ***************************************************************************/
  function update(&$d) {
    $db = new ps_DB;

    if ($this->validate_update($d)) {
      $q = "UPDATE newsletter_letter SET ";
      $q .= "letter_subject = '". $d["letter_subject"] ."' ";
      $q .= "letter_detail = '". $d["letter_detail"] ."' ";
      $q .= "WHERE letter_id = '". $d["letter_id"] ."' ";
      $db->query($q);
      $d["error"] = "Your letter is now ready to send.";
      return True;
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

    $q="DELETE FROM newsletter_letter WHERE letter_id='" . $d["letter_id"] . "'";
    $db->query($q);

    return True;
  }


  /**************************************************************************
  ** name: letter_send()
  ***************************************************************************/
  function letter_send(&$d) {
    $db = new ps_DB;
    $db1 = new ps_DB;
    $db2 = new ps_DB;

    if (!$this->validate_letter_send($d)) {
      return False;
    }

    $q = "SELECT * from vendor";
    $db->query($q);
    $db->next_record();
    $vendor_name = $db->f("vendor_name");
    $vendor_email = $db->f("contact_email");


    $db->query("SELECT * FROM newsletter_letter WHERE letter_done='0'");
    $db->next_record();
    $letter_subject=$db->f("letter_subject");
    $letter_detail=$db->f("letter_detail");

    $q="SELECT * FROM newsletter_email WHERE email_done='0'";
    $db1->query($q);
    while($db1->next_record()){

      $email_id=$db1->f("email_id");
      $remove_link="<a href=".URL."?page=shop/index&func=newsletterEmailDelete&email_id=$email_id>CLICK HERE TO UNSUBSCRIBE</a>";

      mail($db1->f("email_address"), "[$vendor_name Newsletter] - $letter_subject", "Hello ". $db1->f("email_name").", \n\n". $letter_detail ."\n\n". $remove_link, "From: $vendor_name <$vendor_email>");
      $db2->query("UPDATE newsletter_email SET email_done='1' WHERE email_id='$email_id'");
      echo "Letter sent to ". $db1->f("email_name") ." &lt;". $db1->f("email_address") ."&gt;.<br>";

    }

    $db->query("UPDATE newsletter_letter SET letter_done='1' WHERE letter_done='0'");
    return True;
  }



}
?>