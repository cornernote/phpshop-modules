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




## esto es la cima y el fondo de cada caja en cada p�gina. 
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




# Algunas etiquetas
$xstats_lbl["stats"]		= "Estad�sticas";

$xstats_lbl["stats_menu"]	= "Men� de Stats";
$xstats_lbl["graph_menu"]	= "Men� Gr�fico";

$xstats_lbl["main"]		    = "Stats Principal";
$xstats_lbl["recent"]		= "Visitantes Recientes";
$xstats_lbl["show"]		    = "Muestre Visitantes";
$xstats_lbl["top_products"]	= "Productos Superior";
$xstats_lbl["top_pages"]	= "Paginas Superior";
$xstats_lbl["top_entry"]	= "Paginas Superiores De Entrada";
$xstats_lbl["top_exit"]		= "Paginas Superiores De Salida";
$xstats_lbl["top_refer"]	= "Refierencias Superior";
$xstats_lbl["top_addr"]		= "Direcci�n IP Superior";
$xstats_lbl["top_browser"]	= "Superiores Browsers";
$xstats_lbl["top_os"]		= "Sistema Operativo Superior";

$xstats_lbl["graph_daily"]	= "Gr�fico Diario";
$xstats_lbl["graph_weekly"]	= "Gr�fico Semanal";
$xstats_lbl["graph_monthly"]= "Gr�fico Mensual";
$xstats_lbl["graph_yearly"]	= "Gr�fico Annual";

$xstats_lbl["visits_today"]		= "Visistas de Hoy";
$xstats_lbl["visits_yesterday"]	= "Visitas De Ayer";
$xstats_lbl["visits_week"]		= "Visitas De Esta Semana";
$xstats_lbl["visits_last_week"]	= "Visitas De la Semana Pasada";
$xstats_lbl["visits_month"]		= "Visitas De Este Mes";
$xstats_lbl["visits_last_month"]= "Visitas Del Mes Pasado";
$xstats_lbl["visits_year"]		= "Visitas De Este A�o";
$xstats_lbl["visits_last_year"]	= "Visitas Del A�o Pasado";

$xstats_lbl["visit_detail"]	  = "Detalles Del Visitante";
$xstats_lbl["action"]		  = "Acci�n";
$xstats_lbl["chat"]		      = "Charla con el Comprador";
$xstats_lbl["visit_pages"]	  = "P�ginas Considera";
$xstats_lbl["start_time"]	  = "Tiempo De Comienso";
$xstats_lbl["end_time"]		  = "Tiempo De Termino";
$xstats_lbl["visit_time"]	  = "Duraci�n De la Visita";
$xstats_lbl["av_page_time"]	  = "El Tiempo Medio Por P�gina";
$xstats_lbl["last_page_time"] = "Ultima P�gina Visitada";
$xstats_lbl["addr"]	          = "Direcci�n IP";
$xstats_lbl["browser"]        = "Browser";
$xstats_lbl["os"]	          = "Sistema Operativo";
$xstats_lbl["product"]		  = "Nombre Del Producto";
$xstats_lbl["referer"]		  = "Refierencia";
$xstats_lbl["page"]		      = "P�gina";
$xstats_lbl["module_page"]	  = "M�dulo/P�gina";
$xstats_lbl["visit_time"]	  = "Duraci�n Mediana De la Visita";
$xstats_lbl["page_time"]	  = "Duraci�n Mediana De la P�gina";
$xstats_lbl["first_visit"]	  = "Primera Visita";
$xstats_lbl["pages"]		  = "P�ginas Considera";
$xstats_lbl["hits"]		      = "Golpes";
$xstats_lbl["exits"]          = "Salidas";
$xstats_lbl["last30days"]	  = "�ltimo 30 D�as Solamente";
$xstats_lbl["today"]		  = "Hoy Solamente";
$xstats_lbl["total"]		  = "Total";
$xstats_lbl["totals"]		  = "TOTALES";

?>