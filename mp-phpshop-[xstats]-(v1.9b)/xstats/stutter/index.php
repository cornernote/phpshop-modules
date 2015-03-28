<?php
 $user = ereg_replace(" ", "_", $user);
 $user = strip_tags($user);
 if ($user == "-") { $user = ""; }
 if ($user == "*") { $user = ""; }
 if ($user) {
  setcookie("StutterUser", $user);
 }
 include("common.php");
?>
<html>
<head>
<title><?php echo $room?> Chat</title>
<meta http-equiv="Content-Type" content="text/html; charset=<?php echo $stsr["charset"]?>">
</head>

<?php if (!$room) { $room = "Stutter"; } ?>

<?php if (!$user):?>

<form action="<?php basename($PHP_SELF)?>" method=POST>
<?php echo strOut("AskForNick")?><br>
<input name="user">
<input type="hidden" name="room" value="<?php echo $room?>">
<input type="Submit" value="<?php echo strOut("AskForNickButton")?>">
</form>


<?php else:?>

<?php
 stutterSendMessage(addslashes(strOut("HasEntered", "", $user)), $room, "*");
?>

<frameset rows="*,60"> 
  <frameset rows="*,40"> 
    <frame name="output" src="nph-output.php?room=<?php echo URLEncode($room)?>">
    <frame name="options" src="options.php?room=<?php echo URLEncode($room)?>" scrolling="NO">
  </frameset>
  <frame name="input" scrolling="NO" noresize src="input.php?room=<?php echo URLEncode($room)?>">
</frameset>
<noframes><body bgcolor="#FFFFFF">
<?php echo strOut("NoFrames")?>
</body></noframes>

<?php endif;?>

</html>
