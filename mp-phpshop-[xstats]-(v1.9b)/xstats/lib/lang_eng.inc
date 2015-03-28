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


$module_topmenu         = MODROOT."templates/topmenu.ihtml";
$module_leftmenu        = MODROOT.$modulename."/html/leftmenu.ihtml";
$module_menu            = MODROOT.$modulename."/html/leftmenu.ihtml";




## this is the top and bottom of every box on every page.
function print_box_top($title)
{?>
      <table width="100%" border="0" cellspacing="0" cellpadding="1" bgcolor="#000033">
        <tr> 
          <td align=center> <font color="#FFFFFF" size=+2><b><?php echo $title; ?></b></font> 
            <table width="100%" border="0" cellspacing="0" cellpadding="15" bgcolor="#FFFFCC">
              <tr valign="top" align=center> 
                <td><?
}

function print_box_bottom()
{?>
                </td>
              </tr>
            </table>
          </td>
        </tr>
      </table>
      <br><?
}




# Some labels
$xstats_lbl["stats"]		= "Statistics";

$xstats_lbl["stats_menu"]	= "Stats Menu";
$xstats_lbl["graph_menu"]	= "Graph Menu";

$xstats_lbl["main"]		= "Main Stats";
$xstats_lbl["recent"]		= "Recent Visitors";
$xstats_lbl["show"]		= "Show Visitors";
$xstats_lbl["top_products"]	= "Top Products";
$xstats_lbl["top_pages"]	= "Top Pages";
$xstats_lbl["top_entry"]	= "Top Entry Pages";
$xstats_lbl["top_exit"]		= "Top Exit Pages";
$xstats_lbl["top_refer"]	= "Top Referers";
$xstats_lbl["top_addr"]		= "Top IP Addresses";
$xstats_lbl["top_browser"]	= "Top Browsers";
$xstats_lbl["top_os"]		= "Top Operating Systems";

$xstats_lbl["graph_daily"]	= "Daily Graph";
$xstats_lbl["graph_weekly"]	= "Weekly Graph";
$xstats_lbl["graph_monthly"]	= "Monthly Graph";
$xstats_lbl["graph_yearly"]	= "Yearly Graph";

$xstats_lbl["visits_today"]		= "Todays Visits";
$xstats_lbl["visits_yesterday"]	= "Yesterdays Visits";
$xstats_lbl["visits_week"]		= "This Weeks Visits";
$xstats_lbl["visits_last_week"]	= "Last Weeks Visits";
$xstats_lbl["visits_month"]		= "This Months Visits";
$xstats_lbl["visits_last_month"]	= "Last Months Visits";
$xstats_lbl["visits_year"]		= "This Years Visits";
$xstats_lbl["visits_last_year"]	= "Last Years Visits";

$xstats_lbl["visit_detail"]	= "Visitor Details";
$xstats_lbl["action"]		= "Action";
$xstats_lbl["chat"]		= "Chat to Shopper";
$xstats_lbl["visit_pages"]	= "Pages Viewed";
$xstats_lbl["start_time"]	= "Start Time";
$xstats_lbl["end_time"]		= "End Time";
$xstats_lbl["visit_time"]	= "Visit Length";
$xstats_lbl["av_page_time"]	= "Average Time Per Page";
$xstats_lbl["last_page_time"] = "Last Page Loaded";
$xstats_lbl["addr"]		= "IP Address";
$xstats_lbl["browser"]		= "Browser";
$xstats_lbl["os"]			= "Operation System";
$xstats_lbl["product"]		= "Product Name";
$xstats_lbl["referer"]		= "Referer";
$xstats_lbl["page"]		= "Page";
$xstats_lbl["module_page"]	= "Module/Page";
$xstats_lbl["visit_time"]	= "Average Visit Length";
$xstats_lbl["page_time"]	= "Average Page Time";
$xstats_lbl["first_visit"]	= "First Visit";
$xstats_lbl["pages"]		= "Page Views";
$xstats_lbl["hits"]		= "Hits";
$xstats_lbl["exits"]		= "Exits";
$xstats_lbl["last30days"]	= "Last 30 Days Only";
$xstats_lbl["today"]		= "Today Only";
$xstats_lbl["total"]		= "Total";
$xstats_lbl["totals"]		= "TOTALS";

?>