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




## esto es la cima y el fondo de cada caja en cada página. 
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
$xstats_lbl["stats"]		= "Estadísticas";

$xstats_lbl["stats_menu"]	= "Menú de Stats";
$xstats_lbl["graph_menu"]	= "Menú Gráfico";

$xstats_lbl["main"]		    = "Stats Principal";
$xstats_lbl["recent"]		= "Visitantes Recientes";
$xstats_lbl["show"]		    = "Muestre Visitantes";
$xstats_lbl["top_products"]	= "Productos Superior";
$xstats_lbl["top_pages"]	= "Paginas Superior";
$xstats_lbl["top_entry"]	= "Paginas Superiores De Entrada";
$xstats_lbl["top_exit"]		= "Paginas Superiores De Salida";
$xstats_lbl["top_refer"]	= "Refierencias Superior";
$xstats_lbl["top_addr"]		= "Dirección IP Superior";
$xstats_lbl["top_browser"]	= "Superiores Browsers";
$xstats_lbl["top_os"]		= "Sistema Operativo Superior";

$xstats_lbl["graph_daily"]	= "Gráfico Diario";
$xstats_lbl["graph_weekly"]	= "Gráfico Semanal";
$xstats_lbl["graph_monthly"]= "Gráfico Mensual";
$xstats_lbl["graph_yearly"]	= "Gráfico Annual";

$xstats_lbl["visits_today"]		= "Visistas de Hoy";
$xstats_lbl["visits_yesterday"]	= "Visitas De Ayer";
$xstats_lbl["visits_week"]		= "Visitas De Esta Semana";
$xstats_lbl["visits_last_week"]	= "Visitas De la Semana Pasada";
$xstats_lbl["visits_month"]		= "Visitas De Este Mes";
$xstats_lbl["visits_last_month"]= "Visitas Del Mes Pasado";
$xstats_lbl["visits_year"]		= "Visitas De Este Año";
$xstats_lbl["visits_last_year"]	= "Visitas Del Año Pasado";

$xstats_lbl["visit_detail"]	  = "Detalles Del Visitante";
$xstats_lbl["action"]		  = "Acción";
$xstats_lbl["chat"]		      = "Charla con el Comprador";
$xstats_lbl["visit_pages"]	  = "Páginas Considera";
$xstats_lbl["start_time"]	  = "Tiempo De Comienso";
$xstats_lbl["end_time"]		  = "Tiempo De Termino";
$xstats_lbl["visit_time"]	  = "Duración De la Visita";
$xstats_lbl["av_page_time"]	  = "El Tiempo Medio Por Página";
$xstats_lbl["last_page_time"] = "Ultima Página Visitada";
$xstats_lbl["addr"]	          = "Dirección IP";
$xstats_lbl["browser"]        = "Browser";
$xstats_lbl["os"]	          = "Sistema Operativo";
$xstats_lbl["product"]		  = "Nombre Del Producto";
$xstats_lbl["referer"]		  = "Refierencia";
$xstats_lbl["page"]		      = "Página";
$xstats_lbl["module_page"]	  = "Módulo/Página";
$xstats_lbl["visit_time"]	  = "Duración Mediana De la Visita";
$xstats_lbl["page_time"]	  = "Duración Mediana De la Página";
$xstats_lbl["first_visit"]	  = "Primera Visita";
$xstats_lbl["pages"]		  = "Páginas Considera";
$xstats_lbl["hits"]		      = "Golpes";
$xstats_lbl["exits"]          = "Salidas";
$xstats_lbl["last30days"]	  = "Último 30 Días Solamente";
$xstats_lbl["today"]		  = "Hoy Solamente";
$xstats_lbl["total"]		  = "Total";
$xstats_lbl["totals"]		  = "TOTALES";

?>