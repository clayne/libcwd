with (document)
{
  var styles_path;
  var rootpath;
  var rootpos = location.href.lastIndexOf("libcw.sourceforge.net");
  if (rootpos != -1)
    rootpath = location.href.substring(0,rootpos) + "libcw.sourceforge.net/";
  else
  {
    rootpos = location.pathname.lastIndexOf("/html/");
    if (rootpos != -1) 
      rootpath = location.pathname.substring(0,rootpos) + "/";
    else
    {
      rootpos = location.pathname.lastIndexOf("/tutorial/");
      if (rootpos != -1) 
	rootpath = location.pathname.substring(0,rootpos) + "/";
      else
      {
        rootpos = location.pathname.lastIndexOf("/documentation/");
	if (rootpos != -1)
	  rootpath = location.pathname.substring(0,rootpos) + "/documentation/";
      }
    }
  }

  if (is_opera)
    styles_path = rootpath + "styles/opera/";
  else
  {
    if (is_mozilla4)
      styles_path = rootpath + "styles/netscape4/";
    else
    {
      if (is_netscape6)
	styles_path = rootpath + "styles/netscape6/";
      else
      {
	if (is_konqueror)
	  styles_path = rootpath + "styles/konqueror/";
	else
	{
	  if (is_ie)
	    styles_path = rootpath + "styles/ie/";
	  else if (is_mozilla5up || is_gecko)
	    styles_path = rootpath + "styles/mozilla/";
	  else
	    styles_path = rootpath + "styles/ie/";
	}
      }
    }
  }

  write("<LINK REL=StyleSheet HREF=\"" + styles_path + "main.css\" TYPE=\"text/css\">");
  if (need_style_tutorial == 1)
    write("<LINK REL=StyleSheet HREF=\"" + styles_path + "tutorial.css\" TYPE=\"text/css\">");
  if (need_style_doxygen == 1)
    write("<LINK REL=StyleSheet HREF=\"" + styles_path + "doxygen.css\" TYPE=\"text/css\">");
  if (need_style_tag_cw == 1)
    write("<LINK REL=StyleSheet HREF=\"" + styles_path + "tag-cw.css\" TYPE=\"text/css\">");
}