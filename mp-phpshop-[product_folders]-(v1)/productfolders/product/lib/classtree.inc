<?
// ----------------------------------------------------------------------
// Ad Rotator
// ----------------------------------------------------------------------
// Module designed by Mr PHP
// W: www.mrphp.com.au
// E: info@mrphp.com.au
// P: +61 418 436 690
// ----------------------------------------------------------------------
// Credit to Patrick Hess <hess@dland.de> for the original concept
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


        class Tree {
                // configuration
                var $tree_ftv2blank                 = "ftv2blank.gif";
                var $tree_ftv2doc                 = "ftv2doc.gif";
                var $tree_ftv2folderclosed         = "ftv2folderclosed.gif";
                var $tree_ftv2folderopen         = "ftv2folderopen.gif";
                var $tree_ftv2lastnode                 = "ftv2lastnode.gif";
                var $tree_ftv2link                 = "ftv2link.gif";
                var $tree_ftv2mlastnode         = "ftv2mlastnode.gif";
                var $tree_ftv2mnode                 = "ftv2mnode.gif";
                var $tree_ftv2node                 = "ftv2node.gif";
                var $tree_ftv2plastnode         = "ftv2plastnode.gif";
                var $tree_ftv2pnode                 = "ftv2pnode.gif";
                var $tree_ftv2vertline                 = "ftv2vertline.gif";
                var $tree_basefrm                 = "_top";

                // internal data
                var $tree_path;
                var $tree_count = 1;

                function Tree ($t_path = "classtree")
                {
                        $this->tree_path = $t_path;
                }

                function open_tree ($t_text, $t_url)
                {
                        $t_text=ereg_replace ("\"", "&quot;", $t_text);
?>
<script>
classPath = <? echo "\"$this->tree_path\";\n"; ?>
ftv2blank = <? echo "\"$this->tree_ftv2blank\""; ?>;
ftv2doc = <? echo "\"$this->tree_ftv2doc\""; ?>;
ftv2folderclosed = <? echo "\"$this->tree_ftv2folderclosed\""; ?>;
ftv2folderopen = <? echo "\"$this->tree_ftv2folderopen\""; ?>;
ftv2lastnode = <? echo "\"$this->tree_ftv2lastnode\""; ?>;
ftv2link = <? echo "\"$this->tree_ftv2link\""; ?>;
ftv2mlastnode = <? echo "\"$this->tree_ftv2mlastnode\""; ?>;
ftv2mnode = <? echo "\"$this->tree_ftv2mnode\""; ?>;
ftv2node = <? echo "\"$this->tree_ftv2node\""; ?>;
ftv2plastnode = <? echo "\"$this->tree_ftv2plastnode\""; ?>;
ftv2pnode = <? echo "\"$this->tree_ftv2pnode\""; ?>;
ftv2vertline = <? echo "\"$this->tree_ftv2vertline\""; ?>;
basefrm = <? echo "\"$this->tree_basefrm\""; ?>;
</script><script src=<?        echo "\"$this->tree_path/ftiens4.js\"";
?> type="text/javascript">
</script><script>
<?                        echo "\n";

                        $jsvn = "foldersTree";
                        echo "$jsvn = gFld(\"$t_text\", \"$t_url\")\n";
                        return ($jsvn);
                }

                function add_folder ($t_parent, $t_text, $t_url)
                {
                        $t_text=ereg_replace ("\"", "&quot;", $t_text);
                        $jsvn = "aux".$this->tree_count;
                        $this->tree_count++;
                        echo "$jsvn = insFld($t_parent, gFld (\"$t_text\", \"$t_url\"))\n";
                        return ($jsvn);
                }

                function add_document ($t_parent, $t_text, $t_url)
                {
                        $t_text=ereg_replace ("\"", "&quot;", $t_text);
                        echo "insDoc($t_parent, gLnk ($t_parent, \"$t_text\", \"$t_url\"))\n";
                }

                function close_tree ()
                {
                        echo "\ninitializeDocument()\n</script>";
                }

                function print_Children($CatID="0",$jsname="foldersTree")
                {
                        global $sess;

                  //print the categories
                        $db=new ps_DB;
                        $q ="SELECT * FROM category, category_xref ";
                        $q.="WHERE category.category_id=category_xref.category_child_id ";
                        $q.="AND category_xref.category_parent_id='$CatID' ";
                        $q.="ORDER BY category.category_name";
                        $db->query($q);
                        while ($db->next_record())
                        {
                                $ID=$db->f("category_id");
                                $Name=$db->f("category_name");
                                $url=$sess->url(SECUREURL . "?page=product/product_category_form&category_id=$ID");

                                $newjsname = $this->add_folder($jsname,$Name,"$url");
                                $this->print_Children($ID,$newjsname);
                        }

                  //print the products
                        $q ="SELECT * FROM product, product_category_xref ";
                        $q.="WHERE product.product_id=product_category_xref.product_id ";
                        $q.="AND product_category_xref.category_id='$CatID' ";
                        $q.="ORDER BY product.product_name";
                        $db->query($q);
                        while ($db->next_record())
                        {
                                $ID=$db->f("product_id");
                                $Name=$db->f("product_name");
                                $sku=$db->f("product_sku");
                                $url=$sess->url(SECUREURL . "?page=product/product_form&product_id=$ID");

                                $this->add_document($jsname,"$Name - $sku","$url");
                        }
                }
        }
?>