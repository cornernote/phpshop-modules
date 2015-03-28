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


// Fem funció contextual que varia el codi del PropertyAccessor en funció de si es Explorer o Netscape: retorna string amb PropertyAccessor.Get(...) si és Netscape o bé directament Object.property si és Explorer:
function PropAcce_string($situ,$nomeditor,$property,$value){
	global $navegador;
	$pa_str = "";
	if( !strcmp($situ,"Get") ) {
		if( !strcmp($navegador,"IE") ){
			$pa_str = $nomeditor . "." . $property ;
		}
		else
		{
			$pa_str = "PropertyAccessor.Get(".$nomeditor.",\"".$property."\");";
		}
	}
	if( !strcmp($situ,"Set") ) {
		if( !strcmp($navegador,"IE") ){
			$pa_str = $nomeditor . "." . $property . " = " . $value ;
		}
		else
		{
			$pa_str = "PropertyAccessor.Set(".$nomeditor.",\"".$property."\",".$value.");";
		}
	}
	return $pa_str;
}
?>