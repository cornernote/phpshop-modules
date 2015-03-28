<html>
 <head><title>Who's On <?php echo $room?></title></head>
 <body>
<?php

require("common.php");

echo "<h1>$room</h1>";

$on = usersOnline("Stutter");

if (is_array($on)) {
 echo "<ul>";
 foreach ($on as $username) {
  echo "<li>$username\n";
 }
 echo "</ul>";
}
else {
 echo "No Users Online";
}
?>

 </body>
</html>
