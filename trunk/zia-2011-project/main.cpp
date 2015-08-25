#include <QtCore/QCoreApplication>
#include "commandpanelcli.h"
#include "StaticFunctions.h"
#include <stdio.h>
#include "Gui/gui.h"
#include "Gui/qwindowapi.h"

int main(int argc, char *argv[])
{
    if (!isgui(argc, argv))
    {
        QCoreApplication a(argc, argv);
        CommandPanelCLI *cli = new CommandPanelCLI(argc, argv);
        cli->start();
        return a.exec();
    }
    else
    {
        QApplication a(argc, argv);
        gui     *ZiaGui = new gui("ZiaServer", 300, 600, true, NULL, "img/back.png");
        ZiaGui->show();
        return a.exec();
    }
    return 0;
}
