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
$xstats_lbl["stats"]		= "Statistiken";

$xstats_lbl["stats_menu"]	= "Statistik Menü";
$xstats_lbl["graph_menu"]	= "Grafisches Menü";

$xstats_lbl["main"]		= "Hauptstatistik";
$xstats_lbl["recent"]		= "Neue Besucher";
$xstats_lbl["show"]		= "Alle Besucher";
$xstats_lbl["top_products"]	= "Top Produkte";
$xstats_lbl["top_pages"]	= "Top Seiten";
$xstats_lbl["top_entry"]	= "Top Eingangsseiten";
$xstats_lbl["top_exit"]		= "Top Ausgangsseiten";
$xstats_lbl["top_refer"]	= "Top Verweise";
$xstats_lbl["top_addr"]		= "Top IP Adressen";
$xstats_lbl["top_browser"]	= "Top Browser";
$xstats_lbl["top_os"]		= "Top Betriebssysteme";

$xstats_lbl["graph_daily"]	= "Tagesgrafik";
$xstats_lbl["graph_weekly"]	= "Wochengrafik";
$xstats_lbl["graph_monthly"]	= "Monatsgrafik";
$xstats_lbl["graph_yearly"]	= "Jahresgrafik";

$xstats_lbl["visits_today"]	= "Besucher Heute";
$xstats_lbl["visits_yesterday"]	= "Besucher Gestern";
$xstats_lbl["visits_week"]	= "Besucher dieser Woche";
$xstats_lbl["visits_last_week"]	= "Besucher letzte Woche";
$xstats_lbl["visits_month"]	= "Besucher diesen Monats";
$xstats_lbl["visits_last_month"]= "Besucher letzen Monats";
$xstats_lbl["visits_year"]	= "Besucher diesen Jahres";
$xstats_lbl["visits_last_year"]	= "Besucher letzten Jahres";

$xstats_lbl["visit_detail"]	= "Details über Besucher";
$xstats_lbl["action"]		= "Aktion";
$xstats_lbl["chat"]		= "Mit Käufer Chatten";
$xstats_lbl["visit_pages"]	= "Seiten gesichtet";
$xstats_lbl["start_time"]	= "Anfangszeit";
$xstats_lbl["end_time"]		= "Abschlusszeit";
$xstats_lbl["visit_time"]	= "länge des Besuches";
$xstats_lbl["av_page_time"]	= "Durchschnittliche Zeit der Seite";
$xstats_lbl["last_page_time"]   = "letzte geladene Seite";
$xstats_lbl["addr"]		= "IP Adresse";
$xstats_lbl["browser"]		= "Browser";
$xstats_lbl["os"]		= "Betriebssystem";
$xstats_lbl["product"]		= "Produktname";
$xstats_lbl["referer"]		= "Herkunft";
$xstats_lbl["page"]		= "Seite";
$xstats_lbl["module_page"]	= "Modul/Seite";
$xstats_lbl["visit_time"]	= "Durchschnittliche Zeit pro Besuch";
$xstats_lbl["page_time"]	= "Durchschnittliche Zeit pro Seite";
$xstats_lbl["first_visit"]	= "Erster Besuch";
$xstats_lbl["pages"]		= "Seitenansichten";
$xstats_lbl["hits"]		= "Zugriffe";
$xstats_lbl["exits"]		= "Ausgang";
$xstats_lbl["last30days"]	= "Nur die letzten 30 Tage";
$xstats_lbl["today"]		= "Nur Heute";
$xstats_lbl["total"]		= "Gesamt";
$xstats_lbl["totals"]		= "INSGESAMT";

?>