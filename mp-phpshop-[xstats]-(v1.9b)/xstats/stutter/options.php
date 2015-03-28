<?php
 include("common.php");
 if ($option == "logoff") {
  stutterSendMessage(addslashes(strOut("HasLeft", "", $user)), $room, "*");
  setcookie("StutterUser", "");
  $onload = "onLoad=\"parent.close();\"";
 }
 if ($option == "help") {
  stutterSendMessage(addslashes(strOut("Help")), $room, "-");
 }
 if ($option == "online") {
  $online = usersOnline($room);
  if (is_array($online)) {
   $message = "<ul>\n";
   while (list($key, $val) = each($online)) {
    $message .="<li>$val\n";
   }
   $message .= "</ul>\n";
  }
  else { $message = $online; }
  stutterSendMessage(addslashes(strOut("UsersOnline", $message)), $room, "-");
 }
 touchUser()
?>

<html>
<head>
 <title>Stutter Options</title>
 <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
 <meta HTTP-EQUIV="Refresh" CONTENT="<?php echo $timeout/2?>;URL=<?php echo basename($PHP_SELF)?>?room=<?php echo URLEncode($room)?>">
 <style type="text/css">
  <!--
   p,td,li {  font-family: Arial, Helvetica, sans-serif}
  -->
 </style>
</head>

<body bgcolor="#FFFFFF" <?php echo $onload?>>
<p><font size="-1">
<a href="nph-output.php?room=<?php echo URLEncode($room)?>" target="output"><?php echo strOut("RefreshLink")?></a> |
<a href="<?php echo basename($PHP_SELF)?>?room=<?php echo URLEncode($room)?>&option=help"><?php echo strOut("HelpLink")?></a> |
<a href="<?php echo basename($PHP_SELF)?>?room=<?php echo URLEncode($room)?>&option=online"><?php echo strOut("OnlineLink")?></a> |
<a href="<?php echo basename($PHP_SELF)?>?room=<?php echo URLEncode($room)?>&option=logoff"><?php echo strOut("LogoffLink")?></a>
</font></p>
</body>
</html>
