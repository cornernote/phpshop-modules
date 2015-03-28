<?php  include("common.php"); ?>
<html>
<head>
 <title>Stutter Input</title>
 <meta http-equiv="Content-Type" content="text/html; charset=<?php echo $stsr["charset"]?>">
 <style type="text/css">
  <!--
   p,td,li {  font-family: Arial, Helvetica, sans-serif}
  -->
 </style>
</head>

<?php
 if ($message) {
  if (eregi("^/msg ",$message)) {	// Send a private message
   list($command, $private, $message) = explode(" ", $message, 3);
   stutterSendMessage(strip_tags($message), $room, $private);
  }
  else {							// Send a public message
   stutterSendMessage(strip_tags($message), $room);
  }
 }
?>

<body bgcolor="#FFFFFF" onLoad=document.form.message.focus();>

<form name="form" action="<?php echo basename($PHP_SELF)?>" method=POST>
  <input type="hidden" name="room" value="<?php echo $room?>">
  <input type="text" name="message" size="28" STYLE="width: 100%">
  <!--
  <input type="submit" name="Submit" value="<?php echo strOut("InputButton")?>">
  -->
</form>
</body>
</html>
