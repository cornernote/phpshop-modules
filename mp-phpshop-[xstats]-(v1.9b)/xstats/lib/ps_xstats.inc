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

class ps_xstats{
  var $classname="ps_xstats";


function page_shopper()
{
  global $sess, $page_sid;
  $db  = new ps_DB;
  $db->query("insert into stutter_page values ('$page_sid',NOW())");
  $db->query("insert into stutter_page values ('$sess->sessid',NOW())");
  return $db->num_rows();
}


function chat_shopper()
{
  global $sess;
  $db  = new ps_DB;
  $db->query("select * from stutter_page where sid='$sess->sessid'");
  if($db->num_rows())
  {
    $db->query("delete from stutter_page where sid='$sess->sessid'");
    $db->query("delete from stutter_page where DAYOFYEAR(page_time)<DAYOFYEAR(NOW())");
    $chat_shopper = "onload=\"javascript:i('ChatRoom')\"";
  }
  return $chat_shopper;
}


function count($sql="")
{
  $db  = new ps_DB;
  $db->query("select * from session_stats $sql");
  return $db->num_rows();
}


function count_members()
{
  $db  = new ps_DB;
  $q = "SELECT * FROM session_stats ";
  $q.= "WHERE EXTRACT(DAY_MINUTE FROM start_time)>(EXTRACT(DAY_MINUTE FROM NOW())-5) ";
  $q.= "AND MONTH(start_time)=MONTH(NOW()) ";
  $q.= "AND YEAR(start_time)=YEAR(NOW()) ";
  $q.= "AND user_id!='' ";
  $q.= "group by sid";
  $db->query($q);
  return $db->num_rows();
}

function count_users()
{
  $db  = new ps_DB;
  $q = "SELECT * FROM session_stats ";
  $q.= "WHERE EXTRACT(DAY_MINUTE FROM start_time)>(EXTRACT(DAY_MINUTE FROM NOW())-5) ";
  $q.= "AND MONTH(start_time)=MONTH(NOW()) ";
  $q.= "AND YEAR(start_time)=YEAR(NOW()) ";
  $q.= "group by sid";
  $db->query($q);
  return $db->num_rows();
}

function revertTimeStamp($timestamp) 
{ 
  $year=substr($timestamp,0,4); 
  $month=substr($timestamp,5,2); 
  $day=substr($timestamp,8,2); 
  $hour=substr($timestamp,11,2); 
  $minute=substr($timestamp,14,2); 
  $second=substr($timestamp,17,2); 
  $newdate=mktime($hour,$minute,$second,$month,$day,$year); 
  RETURN ($newdate); 
} 


function time_difference($start="",$end="")
{
  if($start){ $start=$this->revertTimeStamp($start); }else{ $start=mktime(); }
  if($end){ $end=$this->revertTimeStamp($end); }else{ $end=mktime(); }
  return sprintf("%.0f",($end-$start)/60);
}


function get_time($sql="")
{
  $db=new ps_DB;
  $db1=new ps_DB;

  $db->query("select * from session_stats $sql group by sid");
  while($db->next_record())
  {
    $sid=$db->f("sid");

    $db1->query("select * from session_stats where sid='$sid'");
    $db1->next_record();
    $start_time=$db1->f("start_time");
    if($db1->num_rows()>1){
      while($db1->next_record()){ $end_time=$db1->f("start_time"); }
    }else{ $end_time=$start_time; }


    $visit_time=$this->time_difference($start_time,$end_time)+$visit_time;
  }
  
  return $visit_time;
}

function percent($percent="0",$total="0")
{
  $val=sprintf("%.2f",100/$total*$percent);
  return $val;
}

function addhit()
{
  global $sess, $auth, $HTTP_USER_AGENT, $REQUEST_URI, $HTTP_REFERER, $REMOTE_ADDR, $page, $product_id;

  $browser=$this->which_browser($HTTP_USER_AGENT);
  $os=$this->which_os($HTTP_USER_AGENT);

  $db  = new ps_DB;
  $query = sprintf("insert into session_stats ( sid, start_time, page, uri, referer, addr, browser, browser_image, os, os_image, product_id, user_id ) values ('%s',now(),'%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')",
    $sess->sessid,
    $page,
    $REQUEST_URI,
    $HTTP_REFERER,
    $REMOTE_ADDR,
    $browser[0],
    $browser[1],
    $os[0],
    $os[1],
    $product_id,
    $auth["user_id"]);
  $db->query($query);
}

// "Resolve" the Operating system
function which_os($ua)
{
	if (eregi("Mac", $ua))
	{
		$os = "MacOS";
		$osimg = "mac";
		$osstat = "os_macintosh";
	}
	else if (eregi("windows nt", $ua))
	{
		$os = "Windows NT";
		$osimg = "windows";
		$osstat = "os_windowsnt";
	}
	
	else if (eregi("winnt", $ua))
	{
		$os = "Windows NT";
		$osimg = "windows";
		$osstat = "os_windowsnt";
	}
	else if (eregi("windows 98", $ua))
	{
		$os = "Windows 98";
		$osimg = "windows";
		$osstat = "os_windows98";
	}
	else if (eregi("win98", $ua))
	{
		$os = "Windows 98";
		$osimg = "windows";
		$osstat = "os_windows98";
	}
	else if (eregi("windows 95", $ua))
	{
		$os = "Windows 95";
		$osimg = "windows";
		$osstat = "os_windows95";
	}
	else if (eregi("win95", $ua))
	{
		$os = "Windows 95";
		$osimg = "windows";
		$osstat = "os_windows95";
	}
	else if (eregi("Linux ([0-9.]+)", $ua, $regs))
	{
		$os = "Linux ".$regs[1];
		$osimg = "linux";
		$osstat = "os_linux";
	}
	else if (eregi("Linux", $ua, $regs))
	{
		$os = "Linux";
		$osimg = "linux";
		$osstat = "os_linux";
	}
	// ########################
	// #     Last choices     #
	// ########################
	
	// (if everything else fails)
	
	else if (eregi("mdk for ([0-9]\.[0-9])", $ua, $regs))
	{
		$os = "Linux MDK ".$regs[1];
		$osimg = "linux";
		$osstat = "os_linux";
	}
	else if (eregi("mdk", $ua, $regs))
	{
		$os = "Linux MDK";
		$osimg = "linux";
		$osstat = "os_linux";
	}
	else if (eregi("win|windows", $ua))
	{
		$os = "Windows";
		$osimg = "windows";
		$osstat = "os_windows";
	}
	// Maybe Konqueror ==> Linux ?
	else if (eregi("konqueror/(([0-9]*\.[0-9]*\.[0-9]*)|([0-9]*\.[0-9]*))", $ua, $regs))
	{
		$os = "Linux ?";
		$osimg = "linux";
		$osstat = "os_linux";
	}
	else
	{
		$os = "Other";
		$osimg = "question";
		$osstat = "os_other";
	}
	return(array($os,$osimg,$osstat));
}

// "Resolve" the Browser
function which_browser($ua)
{
	if (eregi("msie ([0-9.]+)", $ua, $regs))
	{
		$browser = "Explorer ".$regs[1];
		$browserimg = "explorer";
		$browserstat = "browser_msie";
	}
	else if (eregi("konqueror/([0-9.]+)", $ua, $regs))
	{
		$browser = "Konqueror ".$regs[1];
		$browserimg = "konqueror";
		$browserstat = "browser_konqueror";
	}
	else if (eregi("netscape([0-9]*/[0-9.]+)", $ua, $regs))
	{
		$browser = "Netscape ".$regs[1];
		$browserimg = "navigator";
		$browserstat = "browser_netscape";
	}
	else if (eregi("^mozilla/([0-9].?.[0-9][0-9]|[0-9].?.[0-9]|[0-9])", $ua, $regs))
	{
		if( eregi(" (m[0-9]*)", $ua, $regs2)|| eregi("gecko", $ua))
		{
			$browser = "Mozilla ".$regs[1];
			$browserimg = "mozilla";
			$browserstat = "browser_mozilla";
		}
		else
		{
			$browser = "Netscape ".$regs[1];
			$browserimg = "navigator";
			$browserstat = "browser_netscape";
		}
	}
	else if (eregi("mozilla .([0-9]*)", $ua, $regs))
	{
		$browser = "Mozilla ".$regs[1];
		$browserimg = "mozilla";
		$browserstat = "browser_mozilla";
	}
	else if (eregi("Opera/([0-9.]+)", $ua, $regs))
	{
		$browser = "Opera ".$regs[1];
		$browserimg = "opera";
		$browserstat = "browser_opera";
	}
	else if (eregi("Lynx/([0-9.]+)", $ua, $regs))
	{
		$browser = "Lynx ".$regs[1];
		$browserimg = "lynx";
		$browserstat = "browser_lynx";
	}
	else if (eregi("(^[a-zA-Z]+)/([0-9.]+)", $ua, $regs))
	{
		$browser = $regs[1]." ".$regs[2];
		$browserimg = "question";
		$browserstat = "browser_other";
	}
	else if (eregi("(^[a-zA-Z]+) ([0-9.]+)", $ua, $regs))
	{
		$browser = $regs[1]." ".$regs[2];
		$browserimg = "question";
		$browserstat = "browser_other";
	}
	else if (eregi("(^[a-zA-Z]+)", $ua, $regs))
	{
		$browser = $regs[1];
		$browserimg = "question";
		$browserstat = "browser_other";
	}
	else
	{
		$browser = "Other";
		$browserimg = "question";
		$browserstat = "browser_other";		
	}
	return(array($browser,$browserimg,$browserstat));
}

}
?>