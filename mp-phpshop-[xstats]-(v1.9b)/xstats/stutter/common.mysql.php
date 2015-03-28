<?php 

 // Configuration Section

 $db_host		= "localhost";
 $db_user		= "dbuser";
 $db_password	= "dbpass";
 $db_name		= "dbname";

 $db_table		= "stutter";

 mysql_pconnect($db_host,$db_user,$db_password);
 mysql_select_db($db_name);

 function stutterSendMessage ($message, $room, $private="") {
  global $user, $db_table, $shm_id;
  if ($user) {
   $st = "INSERT INTO $db_table (username, room, message, private) VALUES ('$user', '$room', '$message', '$private')";
   $rc = mysql_query($st);
   if ($shm_id) { $shm_bytes_written = shm_write($shm_id, mysql_insert_id($rc), 0); }
  }
 }

 function stutterGetChat ($room) {
  global $timeout, $db_table, $shm_id;

  $st = "DELETE FROM $db_table WHERE room = '$room' AND date < DATE_SUB(NOW(),INTERVAL $timeout SECOND)";
  $rc = mysql_query($st);

  $st = "SELECT * FROM $db_table WHERE room = '$room' ORDER BY date DESC";
  $rc = mysql_query($st);
  $data = mysql_fetch_array($rc);
  $data = mysql_fetch_array($rc);
  $lastid = $data["id"];

  while (1) {
   $nextline=0;
   if ($shm_id) { $shm_data = shm_read($shm_id, 0, 50); }
   else { $shm_data = $lastid+1; }
   if ($shm_data > $lastid) {
    $st = "SELECT * FROM $db_table WHERE id > '$lastid' AND room = '$room'";
    $rc = mysql_query($st);
    for ($i=0; $i<mysql_num_rows($rc); $i++) {
     unset($data);
     $data = mysql_fetch_array($rc);
     $lastid = stutterDisplayChat($room, $data);
    }
   }
   $idle++;
   if ($idle > $timeout) {
    $idle = 0;
    if (!isOnline($user, $room)) {
     stutterSendMessage(addslashes(strOut("HasLeft", "", $user)), $room, "*");
     exit;
    }
   }
   flush();				// Send the output immediately.
   mysql_freeresult($rc);
   if ($shm_id) { $sleep = 0.5; }
   else { $sleep = 2; }
   sleep($sleep);			// Sleep to save the CPU
  }
 }

 function isOnline($val, $room) {
  global $db_table, $timeout;
  $st = "SELECT * FROM $db_table WHERE username = '$val' AND room = '$room' AND UNIX_TIMESTAMP(date) > UNIX_TIMESTAMP()-$timeout";
  $rc = mysql_query($st);
  if (mysql_numrows($rc) > 0) { return 1; }
  else { return 0; }
 }

 function usersOnline($room) {
  global $db_table, $timeout;
  $st = "SELECT DISTINCT username FROM $db_table WHERE room = '$room' AND UNIX_TIMESTAMP(date) > UNIX_TIMESTAMP()-$timeout";
  $rc = mysql_query($st);
  for ($i=0; $i<mysql_numrows($rc); $i++) {
   $data = mysql_fetch_array($rc);
   $online[]=$data["username"];
  }
  return $online;
 }

?>