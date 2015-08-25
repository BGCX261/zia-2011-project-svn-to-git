#ifndef COMMANDPANELCLI_H
#define COMMANDPANELCLI_H

#include <string>
#include "ICommandPanel.h"

void    *threadCallNotifierCli(void *data);

class CommandPanelCLI : public ICommandPanel
{    
private:
    pthread_t                   thread;
    pthread_t                   threadNotifier;
#ifdef  WIN32
    AbstractSocketClassWindows  *network;
#endif

    void    parseArguments(int argc, char *argv[]);
    void    promptUsage();

public:
    CommandPanelCLI(int argc, char *argv[]);
    virtual ~CommandPanelCLI();
    virtual int     start();
    virtual int     stop();
    virtual int     restart();
    static  void    printState(int code);
    void            ShellStopFunction(char *buf);

};

#endif // COMMANDPANELCLI_H
