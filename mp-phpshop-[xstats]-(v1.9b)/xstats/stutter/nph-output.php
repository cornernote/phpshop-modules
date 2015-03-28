<?php include("common.php")?>
<html>
<head>
 <title>Stutter Output</title>
 <meta http-equiv="Content-Type" content="text/html; charset=<?php echo $stsr["charset"]?>">
 <style type="text/css">
  <!--
   body {  font-family: Arial, Helvetica, sans-serif; font-size: 10pt }
   p {  font-family: Arial, Helvetica, sans-serif }
  -->
 </style>
</head>

<SCRIPT Language="JavaScript">
<!--
 function i(p) {
 remote = window.open(p,"outside");
  outside.focus();
 }
// -->
</SCRIPT>

<body bgcolor="#FFFFFF">
<p><b>Welcome to <?php echo $room?> Chat</b></p>

<?php
 flush();
 stutterGetChat($room);
?>

</body>
</html>
