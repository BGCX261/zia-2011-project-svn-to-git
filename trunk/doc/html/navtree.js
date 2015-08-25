var NAVTREE =
[
  [ "ZiA", "index.html", [
    [ "Class List", "annotated.html", [
      [ "AbstractSocketClassLinux", "class_abstract_socket_class_linux.html", null ],
      [ "AbstractSocketClassWindows", "class_abstract_socket_class_windows.html", null ],
      [ "ClientData", "struct_client_data.html", null ],
      [ "CommandPanelCLI", "class_command_panel_c_l_i.html", null ],
      [ "CPanelData", "struct_c_panel_data.html", null ],
      [ "CPanelState", "struct_c_panel_state.html", null ],
      [ "EcritureDom", "class_ecriture_dom.html", null ],
      [ "file", "structfile.html", null ],
      [ "folder", "structfolder.html", null ],
      [ "gui", "classgui.html", null ],
      [ "IAbstractSocketClass", "class_i_abstract_socket_class.html", null ],
      [ "ICommandPanel", "class_i_command_panel.html", null ],
      [ "Lecture_DOM", "class_lecture___d_o_m.html", null ],
      [ "mime", "structmime.html", null ],
      [ "Module", "class_module.html", null ],
      [ "ModulesWindowClass", "class_modules_window_class.html", null ],
      [ "QWindowAPI", "class_q_window_a_p_i.html", null ],
      [ "Reponse", "class_reponse.html", null ],
      [ "type", "classtype.html", null ],
      [ "zFile", "classz_file.html", null ],
      [ "Zia", "class_zia.html", null ]
    ] ],
    [ "Class Index", "classes.html", null ],
    [ "Class Hierarchy", "hierarchy.html", [
      [ "ClientData", "struct_client_data.html", null ],
      [ "CPanelData", "struct_c_panel_data.html", null ],
      [ "CPanelState", "struct_c_panel_state.html", null ],
      [ "EcritureDom", "class_ecriture_dom.html", null ],
      [ "file", "structfile.html", null ],
      [ "folder", "structfolder.html", null ],
      [ "IAbstractSocketClass", "class_i_abstract_socket_class.html", [
        [ "AbstractSocketClassLinux", "class_abstract_socket_class_linux.html", null ],
        [ "AbstractSocketClassWindows", "class_abstract_socket_class_windows.html", null ]
      ] ],
      [ "ICommandPanel", "class_i_command_panel.html", [
        [ "CommandPanelCLI", "class_command_panel_c_l_i.html", null ],
        [ "gui", "classgui.html", null ]
      ] ],
      [ "Lecture_DOM", "class_lecture___d_o_m.html", null ],
      [ "mime", "structmime.html", null ],
      [ "Module", "class_module.html", null ],
      [ "QWindowAPI", "class_q_window_a_p_i.html", [
        [ "gui", "classgui.html", null ],
        [ "ModulesWindowClass", "class_modules_window_class.html", null ]
      ] ],
      [ "Reponse", "class_reponse.html", null ],
      [ "type", "classtype.html", null ],
      [ "zFile", "classz_file.html", null ],
      [ "Zia", "class_zia.html", null ]
    ] ],
    [ "File List", "files.html", [
      [ "ZiaServer/AbstractSocketClass.h", null, null ],
      [ "ZiaServer/abstractsocketclasslinux.h", null, null ],
      [ "ZiaServer/abstractsocketclasswindows.h", null, null ],
      [ "ZiaServer/commandpanelcli.h", null, null ],
      [ "ZiaServer/HandlingConnection.h", null, null ],
      [ "ZiaServer/ICommandPanel.h", null, null ],
      [ "ZiaServer/reponse.h", null, null ],
      [ "ZiaServer/StaticFunctions.h", null, null ],
      [ "ZiaServer/zfile.h", null, null ],
      [ "ZiaServer/Gui/gui.h", null, null ],
      [ "ZiaServer/Gui/moduleswindow.h", null, null ],
      [ "ZiaServer/Gui/qwindowapi.h", null, null ],
      [ "ZiaServer/xml/Lecture.h", null, null ],
      [ "ZiaServer/xml/module.h", null, null ],
      [ "ZiaServer/xml/SaveXML.h", null, null ],
      [ "ZiaServer/xml/type.h", null, null ],
      [ "ZiaServer/xml/zia.h", null, null ]
    ] ]
  ] ]
];

function createIndent(o,domNode,node,level)
{
  if (node.parentNode && node.parentNode.parentNode)
  {
    createIndent(o,domNode,node.parentNode,level+1);
  }
  var imgNode = document.createElement("img");
  if (level==0 && node.childrenData)
  {
    node.plus_img = imgNode;
    node.expandToggle = document.createElement("a");
    node.expandToggle.href = "javascript:void(0)";
    node.expandToggle.onclick = function() 
    {
      if (node.expanded) 
      {
        $(node.getChildrenUL()).slideUp("fast");
        if (node.isLast)
        {
          node.plus_img.src = node.relpath+"ftv2plastnode.png";
        }
        else
        {
          node.plus_img.src = node.relpath+"ftv2pnode.png";
        }
        node.expanded = false;
      } 
      else 
      {
        expandNode(o, node, false);
      }
    }
    node.expandToggle.appendChild(imgNode);
    domNode.appendChild(node.expandToggle);
  }
  else
  {
    domNode.appendChild(imgNode);
  }
  if (level==0)
  {
    if (node.isLast)
    {
      if (node.childrenData)
      {
        imgNode.src = node.relpath+"ftv2plastnode.png";
      }
      else
      {
        imgNode.src = node.relpath+"ftv2lastnode.png";
        domNode.appendChild(imgNode);
      }
    }
    else
    {
      if (node.childrenData)
      {
        imgNode.src = node.relpath+"ftv2pnode.png";
      }
      else
      {
        imgNode.src = node.relpath+"ftv2node.png";
        domNode.appendChild(imgNode);
      }
    }
  }
  else
  {
    if (node.isLast)
    {
      imgNode.src = node.relpath+"ftv2blank.png";
    }
    else
    {
      imgNode.src = node.relpath+"ftv2vertline.png";
    }
  }
  imgNode.border = "0";
}

function newNode(o, po, text, link, childrenData, lastNode)
{
  var node = new Object();
  node.children = Array();
  node.childrenData = childrenData;
  node.depth = po.depth + 1;
  node.relpath = po.relpath;
  node.isLast = lastNode;

  node.li = document.createElement("li");
  po.getChildrenUL().appendChild(node.li);
  node.parentNode = po;

  node.itemDiv = document.createElement("div");
  node.itemDiv.className = "item";

  node.labelSpan = document.createElement("span");
  node.labelSpan.className = "label";

  createIndent(o,node.itemDiv,node,0);
  node.itemDiv.appendChild(node.labelSpan);
  node.li.appendChild(node.itemDiv);

  var a = document.createElement("a");
  node.labelSpan.appendChild(a);
  node.label = document.createTextNode(text);
  a.appendChild(node.label);
  if (link) 
  {
    a.href = node.relpath+link;
  } 
  else 
  {
    if (childrenData != null) 
    {
      a.className = "nolink";
      a.href = "javascript:void(0)";
      a.onclick = node.expandToggle.onclick;
      node.expanded = false;
    }
  }

  node.childrenUL = null;
  node.getChildrenUL = function() 
  {
    if (!node.childrenUL) 
    {
      node.childrenUL = document.createElement("ul");
      node.childrenUL.className = "children_ul";
      node.childrenUL.style.display = "none";
      node.li.appendChild(node.childrenUL);
    }
    return node.childrenUL;
  };

  return node;
}

function showRoot()
{
  var headerHeight = $("#top").height();
  var footerHeight = $("#nav-path").height();
  var windowHeight = $(window).height() - headerHeight - footerHeight;
  navtree.scrollTo('#selected',0,{offset:-windowHeight/2});
}

function expandNode(o, node, imm)
{
  if (node.childrenData && !node.expanded) 
  {
    if (!node.childrenVisited) 
    {
      getNode(o, node);
    }
    if (imm)
    {
      $(node.getChildrenUL()).show();
    } 
    else 
    {
      $(node.getChildrenUL()).slideDown("fast",showRoot);
    }
    if (node.isLast)
    {
      node.plus_img.src = node.relpath+"ftv2mlastnode.png";
    }
    else
    {
      node.plus_img.src = node.relpath+"ftv2mnode.png";
    }
    node.expanded = true;
  }
}

function getNode(o, po)
{
  po.childrenVisited = true;
  var l = po.childrenData.length-1;
  for (var i in po.childrenData) 
  {
    var nodeData = po.childrenData[i];
    po.children[i] = newNode(o, po, nodeData[0], nodeData[1], nodeData[2],
        i==l);
  }
}

function findNavTreePage(url, data)
{
  var nodes = data;
  var result = null;
  for (var i in nodes) 
  {
    var d = nodes[i];
    if (d[1] == url) 
    {
      return new Array(i);
    }
    else if (d[2] != null) // array of children
    {
      result = findNavTreePage(url, d[2]);
      if (result != null) 
      {
        return (new Array(i).concat(result));
      }
    }
  }
  return null;
}

function initNavTree(toroot,relpath)
{
  var o = new Object();
  o.toroot = toroot;
  o.node = new Object();
  o.node.li = document.getElementById("nav-tree-contents");
  o.node.childrenData = NAVTREE;
  o.node.children = new Array();
  o.node.childrenUL = document.createElement("ul");
  o.node.getChildrenUL = function() { return o.node.childrenUL; };
  o.node.li.appendChild(o.node.childrenUL);
  o.node.depth = 0;
  o.node.relpath = relpath;

  getNode(o, o.node);

  o.breadcrumbs = findNavTreePage(toroot, NAVTREE);
  if (o.breadcrumbs == null)
  {
    o.breadcrumbs = findNavTreePage("index.html",NAVTREE);
  }
  if (o.breadcrumbs != null && o.breadcrumbs.length>0)
  {
    var p = o.node;
    for (var i in o.breadcrumbs) 
    {
      var j = o.breadcrumbs[i];
      p = p.children[j];
      expandNode(o,p,true);
    }
    p.itemDiv.className = p.itemDiv.className + " selected";
    p.itemDiv.id = "selected";
    $(window).load(showRoot);
  }
}

