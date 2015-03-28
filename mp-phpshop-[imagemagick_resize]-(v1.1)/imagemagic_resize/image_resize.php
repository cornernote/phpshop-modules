<?php
// ----------------------------------------------------------------------
// Image Magick Image Resize
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


// Define the $base_dir
$base_dir = "/home/brownseq/phpshop/";



// Grab the phpshop config file
require($base_dir. "etc/phpshop.cfg");
$temp_dir = WEBROOT."shop_image/resized/";

// Get image and size
$image = $_GET["image"];
$size = $_GET["size"]; //maximum width or height

// Some error reporting
if(!$image) $error .= "<b>ERROR:</b> no image specified<br>";
if(!$size) $error .= "<b>ERROR:</b> no size specified<br>";
if($error){ echo $error; die; }

// Set the temp filename
$pieces = explode(".", $image);
$ext = $pieces[count($pieces)-1];
$temp_file = md5($image)."-".$size.".".$ext;

// Set the header type
if ($ext=="jpg" || $ext=="jpeg")
  $content_type="image/jpeg";
elseif ($ext=="gif")
  $content_type="image/gif";
else{ echo "<b>ERROR:</b> unknown file type<br>"; die; }

// Load image properties into an array
$image_attr = getimagesize($image);

// Get the percentage required to resize the image
if ($image_attr[0] > $image_attr[1])
  $percentage = ($size / $image_attr[0]);
else
  $percentage = ($size / $image_attr[1]);

// Get the new image size
$width = round($image_attr[0] * $percentage);
$height = round($image_attr[1] * $percentage);


// Create the output file if it does not exist
if(!is_file($temp_dir.$temp_file))
  exec(IMAGEMAGICK_PATH."convert -resize ".$width."x".$height." ".$image." ".$temp_dir.$temp_file);


//DEBUG
if($debug){
  print "IMAGEMAGICK COMMAND: ".IMAGEMAGICK_PATH."convert -resize ".$width."x".$height." ".$image." ".$temp_dir.$temp_file."<br>";
  print "IMAGE: $image<br>";
  print "SIZE: $size<br>";
  print "IMAGE ATTR: "; print_r($image_attr); print "<br>";
  print "PERCENTAGE: $percentage<br>";
  print "WIDTH: $width<br>";
  print "HEIGHT: $height<br>";
}

// Output the image
header("Content-type: ".$content_type);
readfile($temp_dir.$temp_file);

?>