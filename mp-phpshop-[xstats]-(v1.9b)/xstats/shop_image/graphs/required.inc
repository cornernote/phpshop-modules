<?php
// +----------------------------------------------------------------------+
// | X-Stats                                                              |
// | Copyright (c) 2001 BrettODonnell.com. All rights reserved.           |
// +----------------------------------------------------------------------+
// | The contents of this file are subject to the Mozilla Public License  |
// | Version 1.1 (the "License"); you may not use this file except in     |
// | compliance with the License. You may obtain a copy of the License at |
// | http://www.mozilla.org/MPL/                                          |
// |                                                                      |
// | Software distributed under the License is distributed on an "AS IS"  |
// | basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See  |
// | the License for the specific language governing rights and           |
// | limitations under the License.                                       |
// |                                                                      |
// | The Original Code is X-Stats.                                        |
// |                                                                      |
// | The Initial Developer of the Original Code is BrettODonnell.com.     |
// | Portions created by BrettODonnell.com are Copyright (C) 2001         |
// | BrettODonnell.com. All Rights Reserved.                              |
// +----------------------------------------------------------------------+


//YOU MUST SET THIS!
$base_dir = "/home/sites/site78/web/winecabinets/phpshop/"; 
$fileformat = "gif";


//SOME STUFF TO CHANGE THE LOOK OF THE GRAPHS
$plottype = "linepoints";  // can be bars, lines, points or linepoints
$background_color = array(255,255,236);
$grid_color = "black";
$lightgrid_color = array(222,222,222);
$line_width = "2"; // for lines & linepoints
$line_style = "solid"; // for dashed or solid
$plot_bg_color = array(222,222,222);
$text_color = "black";
$tick_color = "black";
$data_color1 = array("orange","blue");
$data_color2 = array("green","yellow");


//DO NOT CHANGE BELOW HERE
require($base_dir. "etc/phpshop.cfg");
require($base_dir . "db/db_mysql.inc");

require($base_dir . "modules/xstats/lib/ps_xstats.inc");
$ps_xstats = new ps_xstats;

require("./phplot.inc");

?>