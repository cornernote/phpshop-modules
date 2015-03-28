<?
// ----------------------------------------------------------------------
// WYSIWYG Product Editor
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

$url_path_editor = SECUREURL;
$abs_path_editor = $base_dir;

// Mirem quin navegador es fa servir:
if( strstr($_SERVER["HTTP_USER_AGENT"],'IE')!= false || strstr($_SERVER["HTTP_USER_AGENT"],'MS')!= false || strstr($_SERVER["HTTP_USER_AGENT"],'EXPLORER')!= false ){
	$navegador = "IE";
}
else
{
	$navegador = "NS";
}

if( !isset($idi_edit) ){
	$idi_edit = 'eng';
}

$noset = 0;
if( !isset($nom_editor) ){
    $noset = 1;
    $nom_editor = "tbCE";
    echo "<HTML><HEAD><TITLE>Editor DHTML</TITLE><style type=\"text/css\">";
	 echo "td { font-family:Arial; font-size:9pt; color:darkred; bold:true; }";
	 echo "th { font-family:Arial; font-size:7pt; color:darkred; bold:true; }";
	echo "</style>";
	echo "<script>";
	if( !strcmp($navegador,"NS") || 1==1 ){ // De moment, per a tots els navegadors igual:
		echo "\n function salvar_html(codi){ ";
		$mesg1['cat'] = "Aquesta és la funció que has d'adaptar a les teves necessitats.";
		$mesg1['esp'] = "Esta es la función que tienes que adaptar a tus necesidades.";
		$mesg1['eng'] = "This is the function you have to adapt to your needs.";
		echo "\n alert(\"".$mesg1[$idi_edit]."\");";
		$mesg1['cat'] = "El codi generat és:\\n\\n";
		$mesg1['esp'] = "El código generado es:\\n\\n";
		$mesg1['eng'] = "The generated code is:\\n\\n";
		echo "\n alert(\"".$mesg1[$idi_edit]."\"+codi);";
		echo "\n return true ";
		echo "\n } ";
	}
	else // Explorer & Co.
	{
        // Es podria posar la següent funció, que guarda en local,
        // però només funciona amb el DHTML i no amb el DHMTLSafe !!
        /*
        echo "\n function salvar_html(codi){ ";
		echo "\n if ( document.".$nom_editor.".CurrentDocumentPath != \"\") { ";
		    echo "\n 	var path; ";

		    echo "\n 	path = document.".$nom_editor.".CurrentDocumentPath; ";

		    echo "\n 	if (path.substring(0, 7) == \"http://\" || path.substring(0,7) == \"file://\"){ ";
		      echo "\n 		document.".$nom_editor.".SaveDocument(\"\", true); ";
		    echo "\n 	}else{ ";
		      echo "\n 		document.".$nom_editor.".SaveDocument(".$nom_editor.".CurrentDocumentPath, false); ";
		    echo "\n } ";
		echo "\n }else{ ";
		    echo "\n document.".$nom_editor.".SaveDocument(\"\", true); ";
		echo "\n } ";
		echo "\n} ";
		*/
	}
	echo "</script>";
	echo "<body bgcolor=beige >";
}

if( !isset($content_inicial) ){
	$content_inicial = '';
}

if( !isset($funcio_save) ){
	$funcio_save = '';
	if( $noset == 1 ){
		$funcio_save = 'salvar_html(codi);';
	}

}

if( !isset($action_submit) ){
	$action_submit = '';
}

if( !isset($document_complet) ){
	$document_complet = 1;
}

if( !isset($editor_height) ){
	$editor_height = 400;
}

if( !isset($editor_width) ){
	$editor_width = 700;
}

// Funció per redactar el codi JS d'accés a les propietats de l'editor de forma diferent segons el navegador: IE o NS.
if( !isset($insertat_editor) ){
	include $abs_path_editor."modules/product/lib/PropAcce_string.inc";
}

// Col·lecció de missatges trilingües:
$mesg1['cat'] = "Si genera un nou document perdrà els canvis no guardats del document actual.\\nSegur que desitja continuar?";
$mesg1['esp'] = "Si genera un nuevo documento perderá los cambios no guardados del documento actual.\\nSeguro que desea continuar?";
$mesg1['eng'] = "If you open a new blank document you will loose the unsaved changes of the current document.\\nAre you sure you want to continue?";
$mesg2['cat'] = "Està segur que desitja crear un nou document i perdre els canvis no guardats del document actual ?";
$mesg2['esp'] = "Está seguro que desea crear un nuevo documento y perder los cambios no guardados del documento actual ?";
$mesg2['eng'] = "Are you sure you want to open a blank document and loose the unsaved changes of the current document?";
$mesg3['cat'] = "Degut a problemes amb el codi HTML de la pàgina no es pot executar aquesta comanda.";
$mesg3['esp'] = "Debido a problemas con el código HTML de la pàgina no se puede ejecutar esta acción.";
$mesg3['eng'] = "Due to problems with the HTML code of the page it is not possible to execute this action.";
$mesg4['cat'] = "No es pot crear la taula perquè:";
$mesg4['esp'] = "No se puede crear la tabla porque:";
$mesg4['eng'] = "Table can´t be created due to:";
$mesg5['cat'] = "El numero de files ha de ser un enter positiu.";
$mesg5['esp'] = "El numero de filas debe ser un entero positivo.";
$mesg5['eng'] = "The number of rows must be a positive integer.";
$mesg6['cat'] = "El numero de columnes ha de ser un enter positiu.";
$mesg6['esp'] = "El numero de columnas debe ser un entero positivo.";
$mesg6['eng'] = "The number of columns must be a positive integer.";
$mesg7['cat'] = "Posa el valors dels paràmetres i prem OK:";
$mesg7['esp'] = "Pon los valores de los parámetros i pulsa OK:";
$mesg7['eng'] = "Give values for the parameters and press OK:";
$mesg8['cat'] = "No hi ha cap funció de guardat disponible ni cap url per enviar el codi generat.";
$mesg8['esp'] = "No hay ninguna funció de salvado del documento disponible ni ninguna url para enviar el código generado.";
$mesg8['eng'] = "There aren´t any save function available nor any url to submit the HTML source of the page.";
$mesg9['cat'] = "Nou document";
$mesg9['esp'] = "Nuevo documento";
$mesg9['eng'] = "New document";
$mesg10['cat'] = "Guardar";
$mesg10['esp'] = "Guardar";
$mesg10['eng'] = "Save";
$mesg11['cat'] = "Tallar";
$mesg11['esp'] = "Cortar";
$mesg11['eng'] = "Cut";
$mesg12['cat'] = "Copiar";
$mesg12['esp'] = "Copiar";
$mesg12['eng'] = "Copy";
$mesg13['cat'] = "Enganxar";
$mesg13['esp'] = "Pegar";
$mesg13['eng'] = "Paste";
$mesg14['cat'] = "Desfer";
$mesg14['esp'] = "Deshacer";
$mesg14['eng'] = "Undo";
$mesg15['cat'] = "Refer";
$mesg15['esp'] = "Hacer de nuevo";
$mesg15['eng'] = "Redo";
$mesg16['cat'] = "Cercar";
$mesg16['esp'] = "Buscar";
$mesg16['eng'] = "Find";
$mesg17['cat'] = "Insertar enllaç";
$mesg17['esp'] = "Insertar enlace";
$mesg17['eng'] = "Insert link";
$mesg18['cat'] = "Insertar imatge";
$mesg18['esp'] = "Insertar imagen";
$mesg18['eng'] = "Insert image";
$mesg19['cat'] = "Color de fons del document";
$mesg19['esp'] = "Colro de fondo del document";
$mesg19['eng'] = "Document background´s colour";
$mesg20['cat'] = "Insertar taula";
$mesg20['esp'] = "Insertar tabla";
$mesg20['eng'] = "Insert table";
$mesg21['cat'] = "Insertar fila";
$mesg21['esp'] = "Insertar fila";
$mesg21['eng'] = "Insert row";
$mesg22['cat'] = "Eliminar fila";
$mesg22['esp'] = "Eliminar fila";
$mesg22['eng'] = "Delete row";
$mesg23['cat'] = "Insertar columna";
$mesg23['esp'] = "Insertar columna";
$mesg23['eng'] = "Insert column";
$mesg24['cat'] = "Eliminar columna";
$mesg24['esp'] = "Eliminar columna";
$mesg24['eng'] = "Delete column";
$mesg25['cat'] = "Insertar cel·la";
$mesg25['esp'] = "Insertar celda";
$mesg25['eng'] = "Inser cell";
$mesg26['cat'] = "Eliminar cel·la";
$mesg26['esp'] = "Eliminar celda";
$mesg26['eng'] = "Delete cell";
$mesg27['cat'] = "Combinar cel·les";
$mesg27['esp'] = "Combinar celdas";
$mesg27['eng'] = "Merge cells";
$mesg28['cat'] = "Dividir cel·les";
$mesg28['esp'] = "Dividir celdas";
$mesg28['eng'] = "Split cells";
$mesg29['cat'] = "Negreta";
$mesg29['esp'] = "Negrita";
$mesg29['eng'] = "Bold";
$mesg30['cat'] = "Cursiva";
$mesg30['esp'] = "Cursiva";
$mesg30['eng'] = "Italic";
$mesg31['cat'] = "Subratllat";
$mesg31['esp'] = "Subrayado";
$mesg31['eng'] = "Underline";
$mesg32['cat'] = "Color de font";
$mesg32['esp'] = "Color de fuente";
$mesg32['eng'] = "Font colour";
$mesg33['cat'] = "Color de fons de text";
$mesg33['esp'] = "Color de fondo de texto";
$mesg33['eng'] = "Text background's colour";
$mesg34['cat'] = "Alinear a l´esquerra";
$mesg34['esp'] = "Alinear a la izquierda";
$mesg34['eng'] = "Align to left";
$mesg35['cat'] = "Centrar";
$mesg35['esp'] = "Centrar";
$mesg35['eng'] = "Center";
$mesg36['cat'] = "Alinear a la dreta";
$mesg36['esp'] = "Alinear a la derecha";
$mesg36['eng'] = "Align to right";
$mesg37['cat'] = "Llista numerada";
$mesg37['esp'] = "Lista numerada";
$mesg37['eng'] = "Numbered list";
$mesg38['cat'] = "Llista no numerada";
$mesg38['esp'] = "Lista no numerada";
$mesg38['eng'] = "Bulleted list";
$mesg39['cat'] = "Deindentar";
$mesg39['esp'] = "Deindentar";
$mesg39['eng'] = "Deindent";
$mesg40['cat'] = "Indentar";
$mesg40['esp'] = "Indentar";
$mesg40['eng'] = "Indent";
$mesg41['cat'] = "Sel. Tipus Font";
$mesg41['esp'] = "Sel. Tipo Fuente";
$mesg41['eng'] = "Sel. Font type";
$mesg42['cat'] = "Sel. Tamany Font";
$mesg42['esp'] = "Sel. Tamaño Fuente";
$mesg42['eng'] = "Sel. Font size";

// Funcions i paràmetres Javascript: s'inserten només un cop (menys la funció guardar, el primer cop que s'inserta l'editor en una pàgina, peró si s'inserta més d'un cop a una pàgina només es tornen a insertar els objectes <embed ...> i les toolbars.
if( !isset($insertat_editor) ){
	echo "\n <!-- Paràmetres del DHTML editor --> ";
	echo "\n <script language=javascript > ";
	echo "\n // Esta información corresponde al archivo Dhtmled.js ";
	echo "\n // DHTML Editing Component Constants for JavaScript ";
	echo "\n // ";
	echo "\n // Command IDs ";
	echo "\n // ";
	echo "\n DECMD_BOLD =                      5000 ";
	echo "\n DECMD_COPY =                      5002 ";
	echo "\n DECMD_CUT =                       5003 ";
	echo "\n DECMD_DELETE =                    5004 ";
	echo "\n DECMD_DELETECELLS =               5005 ";
	echo "\n DECMD_DELETECOLS =                5006 ";
	echo "\n DECMD_DELETEROWS =                5007 ";
	echo "\n DECMD_FINDTEXT =                  5008 ";
	echo "\n DECMD_FONT =                      5009 ";
	echo "\n DECMD_GETBACKCOLOR =              5010 ";
	echo "\n DECMD_GETBLOCKFMT =               5011 ";
	echo "\n DECMD_GETBLOCKFMTNAMES =          5012 ";
	echo "\n DECMD_GETFONTNAME =               5013 ";
	echo "\n DECMD_GETFONTSIZE =               5014 ";
	echo "\n DECMD_GETFORECOLOR =              5015 ";
	echo "\n DECMD_HYPERLINK =                 5016 ";
	echo "\n DECMD_IMAGE =                     5017 ";
	echo "\n DECMD_INDENT =                    5018 ";
	echo "\n DECMD_INSERTCELL =                5019 ";
	echo "\n DECMD_INSERTCOL =                 5020 ";
	echo "\n DECMD_INSERTROW =                 5021 ";
	echo "\n DECMD_INSERTTABLE =               5022 ";
	echo "\n DECMD_ITALIC =                    5023 ";
	echo "\n DECMD_JUSTIFYCENTER =             5024 ";
	echo "\n DECMD_JUSTIFYLEFT =               5025 ";
	echo "\n DECMD_JUSTIFYRIGHT =              5026 ";
	echo "\n DECMD_LOCK_ELEMENT =              5027 ";
	echo "\n DECMD_MAKE_ABSOLUTE =             5028 ";
	echo "\n DECMD_MERGECELLS =                5029 ";
	echo "\n DECMD_ORDERLIST =                 5030 ";
	echo "\n DECMD_OUTDENT =                   5031 ";
	echo "\n DECMD_PASTE =                     5032 ";
	echo "\n DECMD_REDO =                      5033 ";
	echo "\n DECMD_REMOVEFORMAT =              5034 ";
	echo "\n DECMD_SELECTALL =                 5035 ";
	echo "\n DECMD_SEND_BACKWARD =             5036 ";
	echo "\n DECMD_BRING_FORWARD =             5037 ";
	echo "\n DECMD_SEND_BELOW_TEXT =           5038 ";
	echo "\n DECMD_BRING_ABOVE_TEXT =          5039 ";
	echo "\n DECMD_SEND_TO_BACK =              5040 ";
	echo "\n DECMD_BRING_TO_FRONT =            5041 ";
	echo "\n DECMD_SETBACKCOLOR =              5042 ";
	echo "\n DECMD_SETBLOCKFMT =               5043 ";
	echo "\n DECMD_SETFONTNAME =               5044 ";
	echo "\n DECMD_SETFONTSIZE =               5045 ";
	echo "\n DECMD_SETFORECOLOR =              5046 ";
	echo "\n DECMD_SPLITCELL =                 5047 ";
	echo "\n DECMD_UNDERLINE =                 5048 ";
	echo "\n DECMD_UNDO =                      5049 ";
	echo "\n DECMD_UNLINK =                    5050 ";
	echo "\n DECMD_UNORDERLIST =               5051 ";
	echo "\n DECMD_PROPERTIES =                5052 ";
	echo "\n ";
	echo "\n // ";
	echo "\n // Enums ";
	echo "\n // ";
	echo "\n ";
	echo "\n // OLECMDEXECOPT   ";
	echo "\n OLECMDEXECOPT_DODEFAULT =         0  ";
	echo "\n OLECMDEXECOPT_PROMPTUSER =        1 ";
	echo "\n OLECMDEXECOPT_DONTPROMPTUSER =    2 ";
	echo "\n ";
	echo "\n // DHTMLEDITCMDF ";
	echo "\n DECMDF_NOTSUPPORTED =             0  ";
	echo "\n DECMDF_DISABLED =                 1  ";
	echo "\n DECMDF_ENABLED =                  3 ";
	echo "\n DECMDF_LATCHED =                  7 ";
	echo "\n DECMDF_NINCHED =                  11 ";
	echo "\n ";
	echo "\n // DHTMLEDITAPPEARANCE ";
	echo "\n DEAPPEARANCE_FLAT =               0 ";
	echo "\n DEAPPEARANCE_3D =                 1  ";
	echo "\n ";
	echo "\n // OLE_TRISTATE ";
	echo "\n OLE_TRISTATE_UNCHECKED =          0 ";
	echo "\n OLE_TRISTATE_CHECKED =            1 ";
	echo "\n OLE_TRISTATE_GRAY =               2 ";

	// Paràmetre bàsic:
	echo "\n var obj_editor = 0 ; ";
	//echo "\n var ".$nom_editor." = 0 ;"; // Per poder saber, des de IE si l'objecte ja ha estat creat

	// Funcions Javascript
	echo "\n // Per canvis de gifs a la barra d'icones: ";
	echo "\n function canvi_imatge(nom_img,graf){ ";
		echo "\n document.images[nom_img].src = graf; ";
		echo "\n return true; ";
	echo "\n } ";
	echo "\n ";
	echo "\n // Utilitats auxiliars per paletes de colors: ";
	echo "\n ";
	echo "\n function MakeArray(n) ";
	echo "\n { ";
	   echo "\n this.length=n ";
	   echo "\n for(var j=1; j<=n; j++){ ";
	      echo "\n this[n]=0 ";
	   echo "\n } ";
	   echo "\n return this ";
	echo "\n } ";


	echo "\n colors= new MakeArray(140); ";
	echo "\n colors[0]='aliceblue' ";
	echo "\n colors[1]='antiquewhite' ";
	echo "\n colors[2]='aqua' ";
	echo "\n colors[3]='aquamarine' ";
	echo "\n colors[4]='azure' ";
	echo "\n colors[5]='beige' ";
	echo "\n colors[6]='bisque' ";
	echo "\n colors[7]='black' ";
	echo "\n colors[8]='blanchedalmond' ";
	echo "\n colors[9]='blue' ";
	echo "\n colors[10]='blueviolet' ";
	echo "\n colors[11]='brown' ";
	echo "\n colors[12]='burlywood' ";
	echo "\n colors[13]='cadetblue' ";
	echo "\n colors[14]='chartreuse' ";
	echo "\n colors[15]='chocolate' ";
	echo "\n colors[16]='coral' ";
	echo "\n colors[17]='cornflower' ";
	echo "\n colors[18]='cornsilk' ";
	echo "\n colors[19]='crimson' ";
	echo "\n colors[20]='cyan' ";
	echo "\n colors[21]='darkblue' ";
	echo "\n colors[22]='darkcyan' ";
	echo "\n colors[23]='darkgoldenrod' ";
	echo "\n colors[24]='darkgray' ";
	echo "\n colors[25]='darkgreen' ";
	echo "\n colors[26]='darkkhaki' ";
	echo "\n colors[27]='darkmagenta' ";
	echo "\n colors[28]='darkolivegreen' ";
	echo "\n colors[29]='darkorange' ";
	echo "\n colors[30]='darkorchid' ";
	echo "\n colors[31]='darkred' ";
	echo "\n colors[32]='darksalmon' ";
	echo "\n colors[33]='darkseagreen' ";
	echo "\n colors[34]='darkslateblue' ";
	echo "\n colors[35]='darkslategray' ";
	echo "\n colors[36]='darkturquoise' ";
	echo "\n colors[37]='darkviolet' ";
	echo "\n colors[38]='deeppink' ";
	echo "\n colors[39]='deepskyblue' ";
	echo "\n colors[40]='dimgray' ";
	echo "\n colors[41]='dodgerblue' ";
	echo "\n colors[42]='firebrick' ";
	echo "\n colors[43]='floralwhite' ";
	echo "\n colors[44]='forestgreen' ";
	echo "\n colors[45]='fuchia' ";
	echo "\n colors[46]='gainsboro' ";
	echo "\n colors[47]='ghostwhite' ";
	echo "\n colors[48]='gold' ";
	echo "\n colors[49]='goldenrod' ";
	echo "\n colors[50]='gray' ";
	echo "\n colors[51]='green' ";
	echo "\n colors[52]='greenyellow' ";
	echo "\n colors[53]='honeydew' ";
	echo "\n colors[54]='hotpink' ";
	echo "\n colors[55]='indianred' ";
	echo "\n colors[56]='indigo' ";
	echo "\n colors[57]='ivory' ";
	echo "\n colors[58]='khaki' ";
	echo "\n colors[59]='lavender' ";
	echo "\n colors[60]='lavenderblush' ";
	echo "\n colors[61]='lawngreen' ";
	echo "\n colors[62]='lemonchiffon' ";
	echo "\n colors[63]='lightblue' ";
	echo "\n colors[64]='lightcoral' ";
	echo "\n colors[65]='lightcyan' ";
	echo "\n colors[66]='lightgoldenrodyellow' ";
	echo "\n colors[67]='lightgreen' ";
	echo "\n colors[68]='lightgrey' ";
	echo "\n colors[69]='lightpink' ";
	echo "\n colors[70]='lightsalmon' ";
	echo "\n colors[71]='lightseagreen' ";
	echo "\n colors[72]='lightskyblue' ";
	echo "\n colors[73]='lightslategray' ";
	echo "\n colors[74]='lightsteelblue' ";
	echo "\n colors[75]='lightyellow' ";
	echo "\n colors[76]='lime' ";
	echo "\n colors[77]='limegreen' ";
	echo "\n colors[78]='linen' ";
	echo "\n colors[79]='magenta' ";
	echo "\n colors[80]='maroon' ";
	echo "\n colors[81]='mediumaquamarine' ";
	echo "\n colors[82]='mediumblue' ";
	echo "\n colors[83]='mediumorchid' ";
	echo "\n colors[84]='mediumpurple' ";
	echo "\n colors[85]='mediumseagreen' ";
	echo "\n colors[86]='mediumslateblue' ";
	echo "\n colors[87]='mediumspringgreen' ";
	echo "\n colors[88]='mediumturquoise' ";
	echo "\n colors[89]='mediumvioletred' ";
	echo "\n colors[90]='midnightblue' ";
	echo "\n colors[91]='mintcream' ";
	echo "\n colors[92]='mistyrose' ";
	echo "\n colors[93]='moccasin' ";
	echo "\n colors[94]='navajowhite' ";
	echo "\n colors[95]='navy' ";
	echo "\n colors[96]='oldlace' ";
	echo "\n colors[97]='olive' ";
	echo "\n colors[98]='olivedrab' ";
	echo "\n colors[99]='orange' ";
	echo "\n colors[100]='orangered' ";
	echo "\n colors[101]='orchid' ";
	echo "\n colors[102]='palegoldenrod' ";
	echo "\n colors[103]='palegreen' ";
	echo "\n colors[104]='paleturquoise' ";
	echo "\n colors[105]='palevioletred' ";
	echo "\n colors[106]='papayawhip' ";
	echo "\n colors[107]='peachpuff' ";
	echo "\n colors[108]='peru' ";
	echo "\n colors[109]='pink' ";
	echo "\n colors[110]='plum' ";
	echo "\n colors[111]='powderblue' ";
	echo "\n colors[112]='purple' ";
	echo "\n colors[113]='red' ";
	echo "\n colors[114]='rosybrown' ";
	echo "\n colors[115]='royalblue' ";
	echo "\n colors[116]='saddlebrown' ";
	echo "\n colors[117]='salmon' ";
	echo "\n colors[118]='sandybrown' ";
	echo "\n colors[119]='seagreen' ";
	echo "\n colors[120]='seashell' ";
	echo "\n colors[121]='sienna' ";
	echo "\n colors[122]='silver' ";
	echo "\n colors[123]='skyblue' ";
	echo "\n colors[124]='slateblue' ";
	echo "\n colors[125]='slategray' ";
	echo "\n colors[126]='snow' ";
	echo "\n colors[127]='springgreen' ";
	echo "\n colors[128]='steelblue' ";
	echo "\n colors[129]='tan' ";
	echo "\n colors[130]='teal' ";
	echo "\n colors[131]='thistle' ";
	echo "\n colors[132]='tomato' ";
	echo "\n colors[133]='turquoise' ";
	echo "\n colors[134]='violet' ";
	echo "\n colors[135]='wheat' ";
	echo "\n colors[136]='white' ";
	echo "\n colors[137]='whitesmoke' ";
	echo "\n colors[138]='yellow' ";
	echo "\n colors[139]='yellowgreen' ";

	echo "\n 	function taula_colors(){ ";
	 	echo "\n var t=0,taco ";
	 	echo "\n taco='<center><br><br><table border=1 cellspacing=0 cellpadding=0>'; ";
	 	echo "\n while(t<140){ ";
	 		echo "\n if(t%16==0){ ";
				echo "\n if(t!=0){ ";
					echo "\n taco+='</tr>' ";
				echo "\n } ";
				echo "\n taco+='<tr>' ";
			echo "\n } ";
			echo "\n taco+='<td bgcolor=\"'+colors[t]+'\" ><a href=javascript:canvi(\"'+colors[t]+'\"); ><img src=\"".$url_path_editor."shop_image/wysiwyg/trans.gif\" border=0 width=18 height=18 alt=\"'+colors[t]+'\"></a></td>'; ";
			echo "\n t++ ";
 		echo "\n } ";
		echo "\n taco+='</tr></table></center>' ";
 		echo "\n return taco ";
	echo "\n } ";

	echo "\n function paleta_colors(ruta_funct){ ";
	  echo "\n var pal_col, k, tc ";
	  echo "\n pal_col=window.open(\"\",\"paleta_colors\",\"screenX=80,screenY=80,width=360,height=250\") ";
	  echo "\n pal_col.document.open() ";
	  echo "\n k=pal_col.document; ";
	  echo "\n k.writeln(\"<html><head><style> td,body { font-family:Arial; font-size:8pt; } </style> <script> function canvi(hexa) { \"+ruta_funct+\"(hexa); window.close(); }</\"+\"script></head><body bgcolor=white ><center>\") ";
	  echo "\n k.writeln(\"<font color=black face=arial size=-1 ><b> Fes click a sobre del color escollit:</b></font>\") ";
	  echo "\n tc=taula_colors() ";
	  echo "\n k.writeln(tc) ";
	  echo "\n k.writeln(\"</center></body></html>\") ";
	  echo "\n k.close() ";
	  echo "\n pal_col.focus() ";
	echo "\n } ";

	// Funcions per ús auxiliar des de l'aplicació en la que s'empotri el editor.

	echo "\n function contingut_html(nom_editor) { ";
	if( !strcmp($navegador,"NS") ){
	    echo "\n var obj_ed = eval(nom_editor); ";
	}else{
	    echo "\n var obj_ed = eval(\"document.\" + nom_editor); ";
	}
		echo "\n var cont = ".PropAcce_string("Get","obj_ed","DocumentHTML","0")."; ";
		echo "\n var texto = \"\" + cont ";
		echo "\n var complet = eval(nom_editor + '_doc_complet');";
		echo "\n if(!complet){ ";
		echo "\n	texto = strip_body(texto); ";
		echo "\n } ";
		echo "\n return texto ";
	echo "\n } ";

	echo "\n function posa_contingut_html(nom_editor,contingut) { ";
    if( !strcmp($navegador,"NS") ){
	   echo "\n var obj_ed = eval(nom_editor); ";
	}else{
	   echo "\n var obj_ed = eval(\"document.\" + nom_editor); ";
	}
		echo "\n ".PropAcce_string("Set","obj_ed","DocumentHTML","contingut").";";
	echo "\n } ";

	echo "\n function strip_body(cont) { ";
		echo "\n var  ini_cos = cont.search(/<BODY/i); ";
		echo "\n if( ini_cos == -1 ){ ";
		echo "\n 	return cont; ";
		echo "\n } ";
		// Cal cercar on es tanca el tag <body :
		echo "\n var  lon = cont.length ";
		echo "\n var  fi = false ";
		echo "\n var prob = false ";
		echo "\n var  i = ini_cos + 5 ";
		echo "\n while( !fi ){ ";
			echo "\n car = cont.charAt(i); ";
	        echo "\n if( car == '>' ){ ";
	        	echo "\n ini_cos = i + 1  ";
	        	echo "\n fi = true ";
	        echo "\n } ";
	        echo "\n if( car == '\"' || car == \"'\" ){ ";
				echo "\n fi_com = false ";
				echo "\n i++ ";
				echo "\n if( i >= lon ){ ";
					echo "\n fi = true; ";
					echo "\n prob = true; ";
					echo "\n fi_com = true; ";
	    		echo "\n } ";
				echo "\n while( !fi_com ){ ";
					echo "\n car_aux = cont.charAt(i); ";
					echo "\n if( car_aux == car ){ ";
						echo "\n fi_com = true ";
					echo "\n } ";
					echo "\n else ";
					echo "\n { ";
						echo "\n i++; ";
					echo "\n } ";
					echo "\n if( i >= lon ){ ";
						echo "\n fi = true; ";
						echo "\n prob = true; ";
						echo "\n fi_com = true; ";
	    			echo "\n } ";
				echo "\n } ";
	        echo "\n } ";
	    	echo "\n i++; ";
	    	echo "\n if( i >= lon ){ ";
				echo "\n fi = true; ";
				echo "\n prob = true; ";
	    	echo "\n } ";
	    echo "\n } ";
	    echo "\n if( prob == true ){ ";
			echo "\n alert('".$mesg3[$idi_edit]."'); ";
	    echo "\n } ";
	    echo "\n else ";
	    echo "\n { ";
	    	echo "\n var fi_cos = cont.search(/<\/BODY/i); ";
			echo "\n var aux = cont.substring(ini_cos,fi_cos)";
			echo "\n cont = aux ";
		echo "\n } ";
		echo "\n return cont;";
	echo "\n }";

	// Primera barra d'eines:

	echo "\n function nou_doc(){ ";
		echo "\n if( confirm('".$mesg1[$idi_edit]."') && confirm('".$mesg2[$idi_edit]."') ){ ";
			echo "\n obj_editor.NewDocument(); ";
		echo "\n } ";
	echo "\n } ";

	echo "\n function cortar() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_CUT,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function copiar() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_COPY,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function pegar(){ ";
	  echo "\n obj_editor.ExecCommand(DECMD_PASTE,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function desfer() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_UNDO,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function refer() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_REDO,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function cercar() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_FINDTEXT,OLECMDEXECOPT_PROMPTUSER); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function fer_link() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_HYPERLINK,OLECMDEXECOPT_PROMPTUSER); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function ins_img() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_IMAGE,OLECMDEXECOPT_PROMPTUSER); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	// Només pòsem bgcolor si estem editant un document complet:
	if( $document_complet == 1 ){
		echo "\n function mostra_pal_doc_bgcolor(){ ";
			echo "\n paleta_colors('opener.doc_bgcolor_posa') ";
			echo "\n return true; ";
		echo "\n } ";

		echo "\n function doc_bgcolor_posa(hexa_color) { ";
			echo "\n var content = ".PropAcce_string("Get","obj_editor","DocumentHTML","0").";";
			echo "\n var codi, noucodi, lon, loc, k, car, car_aux, a, codi_result ";
			echo "\n codi = new String(content); ";
		    echo "\n lon = codi.length ";
		    echo "\n loc = codi.search(/<BODY/i); ";
		    // A partir de 'loc' cerquem 'BGCOLOR=' o 'bgcolor=' o bé '>' i posem el color. En parsejar cal considerar si estem dins de cometes o no i si hem arribat al final o no.
		    echo "\n fi = false; ";
		    echo "\n prob = false; ";
		    echo "\n i = loc + 5; ";
		    echo "\n loc_bg = i ";
		    echo "\n loc_bg_fi = i ";
		    echo "\n while( !fi ){ ";
				echo "\n car = codi.charAt(i); ";
		        echo "\n if( car == '>' ){ ";
		        	echo "\n loc_bg = i  ";
		        	echo "\n loc_bg_fi = i ";
		        	echo "\n fi = true ";
		        echo "\n } ";
		        echo "\n if( codi.substr(i,8) == 'BGCOLOR=' ){ ";
					echo "\n loc_bg = i + 8; ";
					echo "\n // Cal trobar el fi del valor de l'atribut ";
					echo "\n while( codi.charAt(i) != ' ' ){ ";
						echo "\n i++; ";
					echo "\n } ";
					echo "\n loc_bg_fi = i; ";
					echo "\n fi = true; ";
		        echo "\n } ";
		        echo "\n if( codi.substr(i,8) == 'bgcolor=' ){ ";
					echo "\n loc_bg = i + 8; ";
					echo "\n fi = true; ";
		        echo "\n } ";
		        echo "\n if( car == '\"' || car == \"'\" ){ ";
					echo "\n fi_com = false ";
					echo "\n i++ ";
					echo "\n if( i >= lon ){ ";
						echo "\n fi = true; ";
						echo "\n prob = true; ";
						echo "\n fi_com = true; ";
		    		echo "\n } ";
					echo "\n while( !fi_com ){ ";
						echo "\n car_aux = codi.charAt(i); ";
						echo "\n if( car_aux == car ){ ";
							echo "\n fi_com = true ";
						echo "\n } ";
						echo "\n else ";
						echo "\n { ";
							echo "\n i++; ";
						echo "\n } ";
						echo "\n if( i >= lon ){ ";
							echo "\n fi = true; ";
							echo "\n prob = true; ";
							echo "\n fi_com = true; ";
		    			echo "\n } ";
					echo "\n } ";
		        echo "\n } ";
		    	echo "\n i++; ";
		    	echo "\n if( i >= lon ){ ";
					echo "\n fi = true; ";
					echo "\n prob = true; ";
		    	echo "\n } ";
		    echo "\n } ";

		    echo "\n if( prob == true ){ ";
				echo "\n alert('".$mesg3[$idi_edit]."'); ";
		    echo "\n } ";
		    echo "\n else ";
		    echo "\n { ";
		    	echo "\n codi_result = \"\" + codi.substring(0,loc_bg)  ";
		    	echo "\n if( loc_bg == loc_bg_fi ){ ";
					echo "\n codi_result += ' BGCOLOR=\"' + hexa_color + '\" '  ";
		    	echo "\n } ";
		    	echo "\n else ";
		    	echo "\n { ";
		            echo "\n codi_result += '\"' + hexa_color + '\" ' ";
		    	echo "\n } ";
		    	echo "\n codi_result += codi.substring(loc_bg_fi,lon); ";
		    	echo "\n //alert(codi_result); ";
		    	echo "\n ".PropAcce_string("Set","obj_editor","DocumentHTML","codi_result")."; ";
		    echo "\n } ";
			echo "\n return true; ";
		echo "\n } ";
    } // Fi de if( $document_complet == 1 )

	echo "\n function mostra_insert_table() { ";
	if( !strcmp($navegador,"NS") ){
	  echo "\n var pVar = ObjTableInfo; ";
	}else{
	  echo "\n var pVar = document.ObjTableInfo; ";
	}
	  // Display table information dialog
	  echo "\n var NR = ".PropAcce_string("Get","pVar","NumRows","0")."; ";
	  echo "\n var NC = ".PropAcce_string("Get","pVar","NumCols","0")."; ";
	  echo "\n var TA = ".PropAcce_string("Set","pVar","TableAttrs","'\"border=1 width=100% cellpadding=5 cellspacing=2\"'")."; ";
	  echo "\n var CA = ".PropAcce_string("Get","pVar","CellAttrs","0")."; ";

	  echo "\n var funct = 'opener.inserta_table' ";

	  echo "\n var par_tab, k, tc ";
	  echo "\n par_tab=window.open(\"\",\"param_tables\",\"screenX=80,screenY=80,width=400,height=215\") ";
	  echo "\n par_tab.document.open() ";
	  echo "\n k=par_tab.document ";
	  echo "\n k.writeln('<HTML><HEAD><TITLE>Definició de Taula</TITLE>') ";
	  echo "\n k.writeln('<STYLE TYPE=\"text/css\">')  ";
	  echo "\n k.writeln(\" td,body { font-family:Arial; font-size:9pt; font-weight:bold; } \") ";
	  echo "\n k.writeln('</STYLE>') ";
	  echo "\n k.writeln(\"<script> function comprova_valors() { \") ";
	  echo "\n k.writeln(\"           var nf, nc, at, ac, tit, nerr=0 , avis\") ";
	  echo "\n k.writeln(\"           avis = '\\\\n".$mesg4[$idi_edit]."' \") ";
	  echo "\n k.writeln(\"           nf = document.info_table.NumRows.value\") ";
	  echo "\n k.writeln(\"           nc = document.info_table.NumCols.value\") ";
	  echo "\n k.writeln(\"           at = document.info_table.TableAttrs.value\") ";
	  echo "\n k.writeln(\"           ac = document.info_table.CellAttrs.value\") ";
	  echo "\n k.writeln(\"           tit = document.info_table.Caption.value\") ";
	  echo "\n k.writeln(\"           if( nf != parseInt(nf) || nf < 0 ){ \") ";
	  echo "\n k.writeln(\"               nerr++\") ";
	  echo "\n k.writeln(\"               avis += '\\\\n\\\\n-".$mesg5[$idi_edit]."'\") ";
	  echo "\n k.writeln(\"           }\") ";
	  echo "\n k.writeln(\"           if( nc != parseInt(nc) || nc < 0 ){ \") ";
	  echo "\n k.writeln(\"               nerr++\") ";
	  echo "\n k.writeln(\"               avis += '\\\\n\\\\n-".$mesg6[$idi_edit]."'\") ";
	  echo "\n k.writeln(\"           }\") ";
	  echo "\n k.writeln(\"           if( nerr == 0){ \") ";
	  echo "\n k.writeln(\"               \"+funct+\"(nf,nc,at,ac,tit) \") ";
	  echo "\n k.writeln(\"               window.close(); \") ";
	  echo "\n k.writeln(\"           }\") ";
	  echo "\n k.writeln(\"           else\") ";
	  echo "\n k.writeln(\"           {\") ";
	  echo "\n k.writeln(\"             alert(avis)\") ";
	  echo "\n k.writeln(\"           }\") ";
	  echo "\n k.writeln(\"           return true \") ";
	  echo "\n k.writeln(\"         }</\"+\"script>\") ";
	  echo "\n k.writeln('</HEAD><BODY bgcolor=white ><center>') ";
	  echo "\n k.writeln('<form name=info_table onsubmit=\"comprova_valors();\" >'); ";
	  echo "\n k.writeln(\"<font color=black face=arial size=-1 ><b> ".$mesg7[$idi_edit]."</b></font>\") ";
	  echo "\n k.writeln('<TABLE CELLSPACING=10><TR><TD valign=absmiddle >Rows:&nbsp;&nbsp;&nbsp;<INPUT TYPE=TEXT SIZE=3  maxlength=2 NAME=NumRows value='+NR+' ></TD>') ";
	  echo "\n k.writeln('<TD valign=absmiddle >Columns:&nbsp;&nbsp;&nbsp;<INPUT TYPE=TEXT SIZE=3 maxlength=2 NAME=NumCols value='+NC+'></TD></TR>') ";
	  echo "\n k.writeln('<TR><TD>Table Attributes:</TD><TD valign=absmiddle ><INPUT TYPE=TEXT SIZE=20 NAME=TableAttrs maxlength=120 value='+TA+'></TD></TR>') ";
	  echo "\n k.writeln('<TR><TD>Cell Attributes:</TD><TD><INPUT TYPE=TEXT SIZE=20 NAME=CellAttrs value='+CA+'></TD></TR>') ";
	  echo "\n k.writeln('<TR><TD>&nbsp;</TD><TD><INPUT TYPE=HIDDEN SIZE=20 NAME=Caption ></TD></TR></TABLE>') ";
	  echo "\n k.writeln('<TR><TD valign=absmiddle colspan=2 align=center ><INPUT TYPE=BUTTON NAME=OK VALUE=OK onclick=\"comprova_valors()\" ></TD></TR></TABLE>') ";
	  echo "\n k.writeln('</form>') ";
	  echo "\n k.writeln('</center></BODY></HTML>') ";
	  echo "\n k.close() ";
	  echo "\n par_tab.focus() ";
	  echo "\n return true ";
	echo "\n } ";

	echo "\n function inserta_table(nf,nc,at,ac,tit) { ";
	if( !strcmp($navegador,"NS") ){
	  echo "\n var pVar = ObjTableInfo; ";
	}else{
	  echo "\n var pVar = document.ObjTableInfo; ";
	}
	  echo "\n ".PropAcce_string("Set","pVar","NumRows","nf")."; ";
	  echo "\n ".PropAcce_string("Set","pVar","NumCols","nc")."; ";
	  echo "\n ".PropAcce_string("Set","pVar","TableAttrs","at")."; ";
	  echo "\n ".PropAcce_string("Set","pVar","CellAttrs","ac")."; ";
	  echo "\n obj_editor.ExecCommand(DECMD_INSERTTABLE,OLECMDEXECOPT_DODEFAULT, pVar); ";
	  echo "\n return true; ";
	echo "\n } ";

	echo "\n function insert_fila_table() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_INSERTROW,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function elim_fila_table() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_DELETEROWS,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function insert_col_table() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_INSERTCOL,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function elim_col_table() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_DELETECOLS,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function insert_celda_table() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_INSERTCELL,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function elim_celda_table() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_DELETECELLS,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function combinar_celdas_table() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_MERGECELLS,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function split_celdas_table() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_SPLITCELL,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	// Segona barra d'eines:

	echo "\n function FontName_onchange(sel_obj) { ";
	  echo "\n var ty = sel_obj.options[sel_obj.selectedIndex].value; ";
	  echo "\n if( ty != 0 ){ ";
	  echo "\n obj_editor.ExecCommand(DECMD_SETFONTNAME, OLECMDEXECOPT_DODEFAULT, ty); ";
	  echo "\n //obj_editor.SetFocus(); ";
	  echo "\n } ";
	  echo "\n sel_obj.options[0].selected = true ";
	echo "\n } ";

	echo "\n function FontSize_onchange(sel_obj) { ";
	  echo "\n var sz = sel_obj.options[sel_obj.selectedIndex].value; ";
	  echo "\n if( sz != 0 ){ ";
	  echo "\n obj_editor.ExecCommand(DECMD_SETFONTSIZE, OLECMDEXECOPT_DODEFAULT, sz); ";
	  echo "\n //obj_editor.focus(); ";
	  echo "\n } ";
	  echo "\n sel_obj.options[0].selected = true ";
	echo "\n } ";

	echo "\n function negreta(){ ";
		echo "\n obj_editor.ExecCommand(DECMD_BOLD,OLECMDEXECOPT_DODEFAULT); ";
	  	echo "\n //obj_editor.focus(); ";
	  	echo "\n return false; ";
	echo "\n } ";

	echo "\n function cursiva() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_ITALIC,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.SetFocus(); ";
	echo "\n } ";

	echo "\n function subry() { ";
		echo "\n obj_editor.ExecCommand(DECMD_UNDERLINE,OLECMDEXECOPT_DODEFAULT); ";
	  	echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function mostra_pal_fg_color(){ ";
		echo "\n paleta_colors('opener.fg_color_posa') ";
		echo "\n return true; ";
	echo "\n } ";

	echo "\n function fg_color_posa(arr) { ";
	  echo "\n if (arr != null) { ";
	    echo "\n obj_editor.ExecCommand(DECMD_SETFORECOLOR,OLECMDEXECOPT_DODEFAULT, arr); ";
	  echo "\n } ";
	echo "\n } ";

	echo "\n function mostra_pal_bg_color(){ ";
		echo "\n paleta_colors('opener.bg_color_posa') ";
		echo "\n return true; ";
	echo "\n } ";

	echo "\n function bg_color_posa(arr) { ";
	  echo "\n if (arr != null) { ";
	    echo "\n obj_editor.ExecCommand(DECMD_SETBACKCOLOR,OLECMDEXECOPT_DODEFAULT, arr); ";
	  echo "\n } ";
	echo "\n } ";

	echo "\n function alin_dreta() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_JUSTIFYRIGHT,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function centrat() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_JUSTIFYCENTER,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function alin_esq() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_JUSTIFYLEFT,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function llista_numerada() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_ORDERLIST,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function llista_no_num() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_UNORDERLIST,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function indentat() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_INDENT,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";

	echo "\n function deindentat() { ";
	  echo "\n obj_editor.ExecCommand(DECMD_OUTDENT,OLECMDEXECOPT_DODEFAULT); ";
	  echo "\n //obj_editor.focus(); ";
	echo "\n } ";
	echo "\n </script> ";
}

echo "<script language=javascript >";
// Variable de document_complet:
echo "\n var ".$nom_editor."_doc_complet = ".$document_complet.";";

// Funció guardar:
echo "\n function ".$nom_editor."_guardar() { ";
	  if( $funcio_save == "" && $action_submit == "" ){
	  	echo "\n alert('".$mesg8[$idi_edit]."'); ";
	  }
	  else
	  {
	  		// Contingut: (la funció contingut_html ja fa strip_body si cal)
	  		echo "\n var cont = contingut_html('".$nom_editor."'); ";
            // Posem el valor al input hidden:
#            echo "\n document.".$nom_editor."_doc_html.".$nom_editor."_contingut_html.value = cont; ";
            echo "\n document.myform_doc_html.".$nom_editor."_contingut_html.value = cont; ";
			// Ara gestionem què fer:
			if( $funcio_save != '' ){
				$funcio_save_aux = explode('(',$funcio_save);
				echo "\n ".$funcio_save_aux[0]."(cont);";
			}
			elseif( $action_submit != '' )
			{
#				echo "\n document.".$nom_editor."_doc_html.submit();";
#				echo "\n document.myform_doc_html.submit();";
			}
	  }
	echo "\n } ";
echo "</script>";
echo "<table cellspacing=2 cellpadding=0 border=1 bgcolor=silver ><tr><td>";
#echo "<FORM NAME=\"".$nom_editor."_doc_html\" METHOD=\"Post\" ACTION=\"".$action_submit."\" > "; ?>
<? echo "<input type=hidden name=\"".$nom_editor."_contingut_html\" value=\"\" >"; ?>
<table cellspacing=0 cellpadding=0 border=0 hspace=3 >
<tr>
<td valign=middle >
	&nbsp;&nbsp;&nbsp;
</td>
<td valign=middle >
<? #echo "\n	<a href=\"\"  onclick=\"obj_editor=".$nom_editor."; canvi_imatge('".$nom_editor."_nou','".$url_path_editor."shop_image/wysiwyg/newdoc.gif'); nou_doc(); return false;\"  onmouseover=\"canvi_imatge('".$nom_editor."_nou','".$url_path_editor."shop_image/wysiwyg/newdoc_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_nou','".$url_path_editor."shop_image/wysiwyg/newdoc.gif')\" ><img src='".$url_path_editor."shop_image/wysiwyg/newdoc.gif' alt='".$mesg9[$idi_edit]."' border=0 align=absmiddle name='".$nom_editor."_nou' ></a> "; ?>
</td>
<td valign=middle >
<? #echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; canvi_imatge('".$nom_editor."_guard','".$url_path_editor."shop_image/wysiwyg/save.gif'); ".$nom_editor."_guardar(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_guard','".$url_path_editor."shop_image/wysiwyg/save_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_guard','".$url_path_editor."shop_image/wysiwyg/save.gif')\" ><img name='".$nom_editor."_guard' src='".$url_path_editor."shop_image/wysiwyg/save.gif' alt='".$mesg10[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? #echo "\n	<img src='".$url_path_editor."shop_image/wysiwyg/separator.gif' border=0 align=absmiddle > "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; cortar(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_cort','".$url_path_editor."shop_image/wysiwyg/cut_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_cort','".$url_path_editor."shop_image/wysiwyg/cut.gif')\" ><img name='".$nom_editor."_cort' src='".$url_path_editor."shop_image/wysiwyg/cut.gif' alt='".$mesg11[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; copiar(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_cop','".$url_path_editor."shop_image/wysiwyg/copy_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_cop','".$url_path_editor."shop_image/wysiwyg/copy.gif')\" ><img name='".$nom_editor."_cop' src='".$url_path_editor."shop_image/wysiwyg/copy.gif' alt='".$mesg12[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href='' onclick=\"obj_editor=".$nom_editor."; pegar(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_paster','".$url_path_editor."shop_image/wysiwyg/paste_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_paster','".$url_path_editor."shop_image/wysiwyg/paste.gif')\" ><img name='".$nom_editor."_paster' src='".$url_path_editor."shop_image/wysiwyg/paste.gif' alt='".$mesg13[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<img src='".$url_path_editor."shop_image/wysiwyg/separator.gif' border=0 align=absmiddle > "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; desfer(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_ud','".$url_path_editor."shop_image/wysiwyg/undo_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_ud','".$url_path_editor."shop_image/wysiwyg/undo.gif')\" ><img name='".$nom_editor."_ud' src='".$url_path_editor."shop_image/wysiwyg/undo.gif' alt='".$mesg14[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href='' onclick=\"obj_editor=".$nom_editor."; refer(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_rd','".$url_path_editor."shop_image/wysiwyg/redo_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_rd','".$url_path_editor."shop_image/wysiwyg/redo.gif')\" ><img name='".$nom_editor."_rd' src='".$url_path_editor."shop_image/wysiwyg/redo.gif' alt='".$mesg15[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<img src='".$url_path_editor."shop_image/wysiwyg/separator.gif' border=0 align=absmiddle > "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; canvi_imatge('".$nom_editor."_fi','".$url_path_editor."shop_image/wysiwyg/find.gif'); cercar(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_fi','".$url_path_editor."shop_image/wysiwyg/find_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_fi','".$url_path_editor."shop_image/wysiwyg/find.gif')\" ><img name='".$nom_editor."_fi' src='".$url_path_editor."shop_image/wysiwyg/find.gif' alt='".$mesg16[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<img src='".$url_path_editor."shop_image/wysiwyg/separator.gif' border=0 align=absmiddle > "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; canvi_imatge('".$nom_editor."_lnk','".$url_path_editor."shop_image/wysiwyg/link.gif'); fer_link(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_lnk','".$url_path_editor."shop_image/wysiwyg/link_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_lnk','".$url_path_editor."shop_image/wysiwyg/link.gif')\" ><img name='".$nom_editor."_lnk' src='".$url_path_editor."shop_image/wysiwyg/link.gif' alt='".$mesg17[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; canvi_imatge('".$nom_editor."_image','".$url_path_editor."shop_image/wysiwyg/image.gif'); ins_img(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_image','".$url_path_editor."shop_image/wysiwyg/image_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_image','".$url_path_editor."shop_image/wysiwyg/image.gif')\" ><img name='".$nom_editor."_image' src='".$url_path_editor."shop_image/wysiwyg/image.gif' alt='".$mesg18[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<?
if( $document_complet == 1 ){
	echo "\n <td valign=middle >";
		echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; canvi_imatge('".$nom_editor."_dbgc','".$url_path_editor."shop_image/wysiwyg/doc_bgcolor.gif');  mostra_pal_doc_bgcolor(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_dbgc','".$url_path_editor."shop_image/wysiwyg/doc_bgcolor_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_dbgc','".$url_path_editor."shop_image/wysiwyg/doc_bgcolor.gif')\" ><img name='".$nom_editor."_dbgc' src='".$url_path_editor."shop_image/wysiwyg/doc_bgcolor.gif' alt='".$mesg19[$idi_edit]."' border=0 align=absmiddle ></a> ";
	echo "\n </td>";
}
?>
<td valign=middle >
<? echo "\n	<img src='".$url_path_editor."shop_image/wysiwyg/separator.gif' border=0 align=absmiddle > "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; canvi_imatge('".$nom_editor."_table','".$url_path_editor."shop_image/wysiwyg/instable.gif');  mostra_insert_table(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_table','".$url_path_editor."shop_image/wysiwyg/instable_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_table','".$url_path_editor."shop_image/wysiwyg/instable.gif')\" ><img name='".$nom_editor."_table' src='".$url_path_editor."shop_image/wysiwyg/instable.gif' alt='".$mesg20[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; insert_fila_table(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_ir','".$url_path_editor."shop_image/wysiwyg/insrow_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_ir','".$url_path_editor."shop_image/wysiwyg/insrow.gif')\" ><img name='".$nom_editor."_ir' src='".$url_path_editor."shop_image/wysiwyg/insrow.gif' alt='".$mesg21[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; elim_fila_table(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_dr','".$url_path_editor."shop_image/wysiwyg/delrow_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_dr','".$url_path_editor."shop_image/wysiwyg/delrow.gif')\" ><img name='".$nom_editor."_dr' src='".$url_path_editor."shop_image/wysiwyg/delrow.gif' alt='".$mesg22[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; insert_col_table(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_ic','".$url_path_editor."shop_image/wysiwyg/inscol_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_ic','".$url_path_editor."shop_image/wysiwyg/inscol.gif')\" ><img name='".$nom_editor."_ic' src='".$url_path_editor."shop_image/wysiwyg/inscol.gif' alt='".$mesg23[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; elim_col_table(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_dc','".$url_path_editor."shop_image/wysiwyg/delcol_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_dc','".$url_path_editor."shop_image/wysiwyg/delcol.gif')\" ><img name='".$nom_editor."_dc' src='".$url_path_editor."shop_image/wysiwyg/delcol.gif' alt='".$mesg24[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<img src='".$url_path_editor."shop_image/wysiwyg/separator.gif' border=0 align=absmiddle > "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; insert_celda_table(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_ice','".$url_path_editor."shop_image/wysiwyg/inscell_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_ice','".$url_path_editor."shop_image/wysiwyg/inscell.gif')\" ><img name='".$nom_editor."_ice' src='".$url_path_editor."shop_image/wysiwyg/inscell.gif' alt='".$mesg25[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; elim_celda_table(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_dce','".$url_path_editor."shop_image/wysiwyg/delcell_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_dce','".$url_path_editor."shop_image/wysiwyg/delcell.gif')\" ><img name='".$nom_editor."_dce' src='".$url_path_editor."shop_image/wysiwyg/delcell.gif' alt='".$mesg26[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; combinar_celdas_table(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_cc','".$url_path_editor."shop_image/wysiwyg/mrgcell_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_cc','".$url_path_editor."shop_image/wysiwyg/mrgcell.gif')\" ><img name='".$nom_editor."_cc' src='".$url_path_editor."shop_image/wysiwyg/mrgcell.gif' alt='".$mesg27[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; split_celdas_table(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_sc','".$url_path_editor."shop_image/wysiwyg/spltcell_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_sc','".$url_path_editor."shop_image/wysiwyg/spltcell.gif')\" ><img name='".$nom_editor."_sc' src='".$url_path_editor."shop_image/wysiwyg/spltcell.gif' alt='".$mesg28[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
</tr>
</table>
<table cellspacing=0 cellpadding=0 border=0 >
<tr>
<td valign=middle >
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
</td>
<td valign=middle >
<? echo   "<select name=\"".$nom_editor."_FontName\" style=\"width:140\" TITLE=\"Font Name\" LANGUAGE=\"javascript\" onchange=\"obj_editor=".$nom_editor."; return FontName_onchange(this)\"> ";
	echo "<option value=\"0\" selected >".$mesg41[$idi_edit];
?>
	<option value="Verdana" >Verdana
    <option value="Arial" >Arial
    <option value="Tahoma">Tahoma
    <option value="Courier New">Courier New
    <option value="Times New Roman" >Times New Roman
    <option value="Wingdings">Wingdings
  </select>
</td>
<td valign=middle >
<? echo "<select name=\"".$nom_editor."_FontSize\" style=\"width:40\" TITLE=\"Font Size\" LANGUAGE=\"javascript\" onchange=\"obj_editor = ".$nom_editor."; return FontSize_onchange(this)\"> ";
	echo "<option value=\"0\" selected >".$mesg42[$idi_edit];
?>
    <option value="1">1
    <option value="2">2
    <option value="3">3
    <option value="4">4
    <option value="5">5
    <option value="6">6
    <option value="7">7
  </select>
</td>
<td valign=middle >
<? echo "\n	<img src='".$url_path_editor."shop_image/wysiwyg/separator.gif' border=0 align=absmiddle > "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=\"\"  onclick=\"obj_editor=".$nom_editor."; negreta(); return false;\"  onmouseover=\"canvi_imatge('".$nom_editor."_negr','".$url_path_editor."shop_image/wysiwyg/bold_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_negr','".$url_path_editor."shop_image/wysiwyg/bold.gif')\" ><img src='".$url_path_editor."shop_image/wysiwyg/bold.gif' alt='".$mesg29[$idi_edit]."' border=0 align=absmiddle name='".$nom_editor."_negr' ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; cursiva(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_curs','".$url_path_editor."shop_image/wysiwyg/italic_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_curs','".$url_path_editor."shop_image/wysiwyg/italic.gif')\" ><img name='".$nom_editor."_curs' src='".$url_path_editor."shop_image/wysiwyg/italic.gif' alt='".$mesg30[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; subry(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_subr','".$url_path_editor."shop_image/wysiwyg//under_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_subr','".$url_path_editor."shop_image/wysiwyg/under.gif')\" ><img name='".$nom_editor."_subr' src='".$url_path_editor."shop_image/wysiwyg/under.gif' alt='".$mesg31[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<img src='".$url_path_editor."shop_image/wysiwyg/separator.gif' border=0 align=absmiddle > "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; canvi_imatge('".$nom_editor."_fg','".$url_path_editor."shop_image/wysiwyg/fgcolor.gif'); mostra_pal_fg_color(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_fg','".$url_path_editor."shop_image/wysiwyg/fgcolor_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_fg','".$url_path_editor."shop_image/wysiwyg/fgcolor.gif')\" ><img name='".$nom_editor."_fg' src='".$url_path_editor."shop_image/wysiwyg/fgcolor.gif' alt='".$mesg32[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; canvi_imatge('".$nom_editor."_bg','".$url_path_editor."shop_image/wysiwyg/bgcolor.gif'); mostra_pal_bg_color(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_bg','".$url_path_editor."shop_image/wysiwyg/bgcolor_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_bg','".$url_path_editor."shop_image/wysiwyg/bgcolor.gif')\" ><img name='".$nom_editor."_bg' src='".$url_path_editor."shop_image/wysiwyg/bgcolor.gif' alt='".$mesg33[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<img src='".$url_path_editor."shop_image/wysiwyg/separator.gif' border=0 align=absmiddle > "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; alin_esq(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_ae','".$url_path_editor."shop_image/wysiwyg/left_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_ae','".$url_path_editor."shop_image/wysiwyg/left.gif')\" ><img name='".$nom_editor."_ae' src='".$url_path_editor."shop_image/wysiwyg/left.gif' alt='".$mesg34[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; centrat(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_center','".$url_path_editor."shop_image/wysiwyg/center_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_center','".$url_path_editor."shop_image/wysiwyg/center.gif')\" ><img name='".$nom_editor."_center' src='".$url_path_editor."shop_image/wysiwyg/center.gif' alt='".$mesg35[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href='' onclick=\"obj_editor=".$nom_editor."; alin_dreta(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_ad','".$url_path_editor."shop_image/wysiwyg/right_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_ad','".$url_path_editor."shop_image/wysiwyg/right.gif')\" ><img name='".$nom_editor."_ad' src='".$url_path_editor."shop_image/wysiwyg/right.gif' alt='".$mesg36[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<img src='".$url_path_editor."shop_image/wysiwyg/separator.gif' border=0 align=absmiddle > "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; llista_numerada(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_nl','".$url_path_editor."shop_image/wysiwyg/numlist_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_nl','".$url_path_editor."shop_image/wysiwyg/numlist.gif')\" ><img name='".$nom_editor."_nl' src='".$url_path_editor."shop_image/wysiwyg/numlist.gif' alt='".$mesg37[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href='' onclick= \"obj_editor=".$nom_editor."; llista_no_num(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_ul','".$url_path_editor."shop_image/wysiwyg/bullist_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_ul','".$url_path_editor."shop_image/wysiwyg/bullist.gif')\" ><img name='".$nom_editor."_ul' src='".$url_path_editor."shop_image/wysiwyg/bullist.gif' alt='".$mesg38[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<img src='".$url_path_editor."shop_image/wysiwyg/separator.gif' border=0 align=absmiddle > "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; deindentat(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_deind','".$url_path_editor."shop_image/wysiwyg/deindent_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_deind','".$url_path_editor."shop_image/wysiwyg/deindent.gif')\" ><img name='".$nom_editor."_deind' src='".$url_path_editor."shop_image/wysiwyg/deindent.gif' alt='".$mesg39[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<td valign=middle >
<? echo "\n	<a href=''  onclick=\"obj_editor=".$nom_editor."; indentat(); return false;\" onmouseover=\"canvi_imatge('".$nom_editor."_ind','".$url_path_editor."shop_image/wysiwyg/inindent_focus.gif');\" onmouseout=\"canvi_imatge('".$nom_editor."_ind','".$url_path_editor."shop_image/wysiwyg/inindent.gif')\" ><img name='".$nom_editor."_ind' src='".$url_path_editor."shop_image/wysiwyg/inindent.gif' alt='".$mesg40[$idi_edit]."' border=0 align=absmiddle ></a> "; ?>
</td>
<?
// Objetos para tablas y para acceder propiedades (si se necesita):
echo "<td>";
if( !isset($insertat_editor) ){
	if( !strcmp($navegador,"NS") ){
		echo "<!-- Accessor de propietats a través del plug-in de Esker -->";
		echo "<EMBED type=\"application/x-eskerplus\" id=PropertyAccessor  classid=\"clsid:BB356E70-A100-11D4-8AF1-00104B4228F5\" codebase=\"accessor.ocx#Version=1,0,0,1\" width=2 height=2 >";

		echo "<!-- DEInsertTableParam Object -->";
		echo "<EMBED type=\"application/x-eskerplus\" id=\"ObjTableInfo\" CLASSID=\"clsid:47B0DFC7-B7A3-11D1-ADC5-006008A5848C\" width=2 height=2 VIEWASTEXT >";
	}
	else
	{
		echo "<!-- DEInsertTableParam Object -->";
		echo "<object ID=\"ObjTableInfo\" CLASSID=\"clsid:47B0DFC7-B7A3-11D1-ADC5-006008A5848C\" width=2 height=2 VIEWASTEXT>";
		echo "</object>";
	}
}
echo "</td>";
echo "</tr>";
echo "</table>";

//Objeto de edición:
if( !strcmp($navegador,"NS") ){
	echo "<embed type=\"application/x-eskerplus\" id=\"".$nom_editor."\" classid=\"clsid:2D360201-FFF5-11d1-8D03-00A0C959BC0A\"  height=".$editor_height." width=".$editor_width." VIEWASTEXT >";
}
else
{
	echo "<object ID=\"".$nom_editor."\" CLASSID=\"clsid:2D360201-FFF5-11D1-8D03-00A0C959BC0A\" height=".$editor_height." width=".$editor_width." VIEWASTEXT >";
  		echo "<param name=Scrollbars value=true>";
	echo "</object>";
}
// NOTA: fem servir el DHTMLSafe: clsid:2D360201-FFF5-11d1-8D03-00A0C959BC0A
// Es podria fer servir el normal: clsid:2D360200-FFF5-11d1-8D03-00A0C959BC0A
// però dona més problemes d'autoritzacions i merdes a Explorer.

echo "</td></tr></table>";
#echo "</FORM>";

echo "\n <script language =javascript >";
// Pel contingut i els settings inicials: cal intents asíncrons i recurrents ...
// Farem:
// 		Lletra: Arial
// 		Referenciat de la variable JS (que senyala a l'objecte Java del <embed del editor )
//		Posem contingut inicial

// Preparació del $content_inicial:
$content_inicial = str_replace('"',"'",$content_inicial);
$car_aux = "\r\n";
$content_inicial = ereg_replace($car_aux,'',$content_inicial);
$content_inicial_aux = '"'.$content_inicial.'"';

//  Es farà d'una forma o d'altre en funció del navegador:
if( !strcmp($navegador,"NS") ){
	echo "\n ".$nom_editor."_timerID=setInterval(\"".$nom_editor."_inicial()\",100);";
	echo "\n function ".$nom_editor."_inicial(){ ";
		echo "\n if( window[\"PropertyAccessor\"] && window[\"".$nom_editor."\"]){ ";
			echo "\n obj_editor = ".$nom_editor.";";
			echo "\n ".PropAcce_string("Set",$nom_editor,"DocumentHTML",$content_inicial_aux).";";
			echo "\n clearInterval(".$nom_editor."_timerID);";
		echo "\n } ";
		echo "\n return true;";
	echo "\n } ";
}
else
{
	echo "\n ".$nom_editor."_timerID=setInterval(\"".$nom_editor."_inicial()\",100);";
	echo "\n function ".$nom_editor."_inicial(){ ";
		echo "\n if( document[\"".$nom_editor."\"]){ ";
			echo "\n obj_editor = document.".$nom_editor.";";
			echo "\n document.".$nom_editor.".DocumentHTML = ".$content_inicial_aux;
			echo "\n clearInterval(".$nom_editor."_timerID);";
		echo "\n } ";
		echo "\n return true;";
	echo "\n } ";
}
echo "\n </script> ";
if( $noset ==  1 ){
	echo "</body>";
}
$insertat_editor = 1;
?>