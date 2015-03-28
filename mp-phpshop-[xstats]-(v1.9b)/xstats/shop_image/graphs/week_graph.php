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

require("./required.inc");

$graph = new PHPlot;
$db=new ps_DB;

$graph->SetPrintImage(0);


if(!$back){$back=0;}
$i=0;
while($i<7)
{
  $i++;
  $count = "SELECT COUNT(*) as num, COUNT(DISTINCT(sid)) as numsid FROM session_stats ";
  $names = "SELECT DAYNAME(start_time) as dayname FROM session_stats ";
  $q= "WHERE WEEK(start_time)=(WEEK(NOW())-$back) ";
  $q.= "AND YEAR(start_time)=YEAR(NOW()) ";
  $q.= "AND DAYOFWEEK(start_time)=$i ";
  $db->query($names . $q);
  $db->next_record();
  $dayname=$db->f("dayname");

  $db->query($count . $q);
  $db->next_record();

  $graph_data[$i]=array($dayname,$db->f("numsid"),$db->f("num"));
  if($db->f("num")>$biggest){ $biggest=$db->f("num"); }
}


$graph->SetFileFormat($fileformat);
$graph->SetPlotType($plottype);
$graph->SetDataColors($data_color1,$data_color2);
$graph->SetBackgroundColor($background_color);
$graph->SetGridColor($grid_color);
$graph->SetLightGridColor($lightgrid_color);
$graph->SetLineWidth($line_width);
$graph->SetLineStyles($line_style);
$graph->SetPlotBgColor($plot_bg_color_color);
$graph->SetTextColor($text_color);
$graph->SetTickColor($tick_color);

$graph->SetPlotAreaWorld(1,0,8,$biggest);
$graph->SetVertTickPosition('plotleft');
$graph->SetSkipBottomTick(1);
$graph->SetDataValues($graph_data);
$graph->SetDrawYGrid(0);
$graph->SetDrawDataLabels('1');
$graph->SetLabelScalePosition('1');
$graph->SetMarginsPixels(50,50,50,50);
$graph->SetLegend(array('Site Hits','Pages Viewed')); //Lets have a legend
$graph->SetLegendWorld(1,$biggest); //Lets have a legend position

$graph->SetXLabel("Day of Week");
$graph->SetYLabel("");



//Draw it
$graph->DrawGraph();
$graph->PrintImage();
?>