<?php 

 // Configuration Section

 $timeout = 180;		// User Timeout Value
 $db_type = "mysql";	// currently supported databases: mysql|pgsql
 $language = "english";	// current translations: english|spanish|french
 $shm = FALSE;			// Turn shared memory support on/off (probably doesn't work anyway)

 $version = "1.31";

 include("strings.$language.php");
 include("common.$db_type.php");

 if ($StutterUser) {
  $user = $StutterUser;
 }

 if ($shm) { $shm_id = shm_open(0xff3, "c", 0644, 100); }

 function strOut($val, $message = "", $from = "") {
  global $room, $user, $str;
  $translated = $str["$val"];
  $translated = ereg_replace("\%u",$user,$translated);
  $translated = ereg_replace("\%f",$from,$translated);
  $translated = ereg_replace("\%r",$room,$translated);
  $translated = ereg_replace("\%m",$message,$translated);
  return $translated;
 }

 function stutterDisplayChat ($room, $data) {   
  global $user, $HTTP_USER_AGENT, $str;
  
  if (eregi("Macintosh",$HTTP_USER_AGENT)) { $scroll = 11; }
  else { $scroll = 100; }

  $lastid = $data["id"];
  if ($data["message"]) {
   if ($data["private"] == "*") {
    echo strOut("toAll",$data["message"], $data["username"]);
    $nextline++;
   } 
   if (($data["private"] == "-") && ($data["username"] == $user)) {
    echo strOut("toSelf",$data["message"], $data["username"]);
    $nextline++;
   }
   if ($data["private"] == $user) {
    echo strOut("Whispered", $data["message"], $data["username"]);
    $nextline++;
   }
   if (!$data["private"]) {
    $me=$str["me"];
    if (eregi("^/$me ", $data["message"])) {
     $data["message"] = eregi_replace("^/$me ", "", $data["message"]);
     echo strOut("Emote", $data["message"], $data["username"]);
    }
    else {
     echo strOut("Public", $data["message"], $data["username"]);
    }
    $nextline++;
   }
   if ($nextline) {
    echo "<SCRIPT LANGUAGE='JavaScript'>window.scrollBy(0, $scroll); </SCRIPT>\n";
    echo "\n<br>\n";
   }
  } 
  return $lastid;
 }

 function touchUser() {
  global $room;
  stutterSendMessage("", $room);
 }

?>
