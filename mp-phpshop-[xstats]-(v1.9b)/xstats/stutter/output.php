<?php include("common.php")?>
<html>
<head>
 <title>Stutter Output</title>
 <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
 <style type="text/css">
  <!--
   p,td,li {  font-family: Arial, Helvetica, sans-serif}
  -->
 </style>
</head>

<body bgcolor="#FFFFFF">
<p><b>Welcome to <?php echo $room?> Chat</b></p>

0:00 /usr/sbin/mysqld --basedir=/ --datadir=/var/lib/mysq
11157 ?        SN     0:02 /usr/sbin/mysqld --basedir=/ --datadir=/var/lib/mysq
11160 ?        SN     0:00 /usr/sbin/mysqld --basedir=/ --datadir=/var/lib/mysq
11248 ?        SN     0:00 /usr/sbin/mysqld --basedir=/ --datadir=/var/lib/mysq
11424 ?        SN     0:00 /usr/sbin/mysqld --basedir=/ --datadir=/var/lib/mysq
11726 ?        SN     0:00 /usr/sbin/mysqld --basedir=/ --datadir=/var/lib/mysq
11730 ?        SN     0:00 /usr/sbin/mysqld --basedir=/ --datadir=/var/lib/mysq
11782 ?        S      0:00 httpd
11803 ?        SN     0:00 /usr/sbin/mysqld --basedir=/ --datadir=/var/lib/mysq
11959 ?        SN     0:00 /usr/sbin/mysqld --basedir=/ --datadir=/var/lib/mysq
12023 pts/22   S      0:00 -/bin/bash
12085 ?        S      0:00 httpd
12091 ?        S      0:01 httpd
12092 ?        S      0:00 httpd
12114 ?        S      0:00 httpd
<br>
<br>

<?php flush();?>

<?php
 while ($x < 10) {
  sleep(3);
  $st = "SELECT * FROM $db_table WHERE date > '$lastdate' AND room = '$room'";
  $x++; echo "$x - $st\n<br>\n<br>\n"; flush();
  $rc = mysql_query($st);
  for ($i=0; $i<mysql_num_rows($rc); $i++) {
   unset($data);
   $data = mysql_fetch_array($rc);
   $lastdate = $data["date"];
   if ($data["private"] == $user) {
    echo "<b>$data[user]</b> whispered: $data[message]\n<br>\n";
   }
   if (!$data["private"]) {
    echo "&lt;<b>$data[user]</b>&gt; $data[message]<br>\n<br>\n";
   }
  }
  flush();
  sleep(3);
 }

?>

</body>
</html>
