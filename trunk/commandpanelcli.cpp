#include "commandpanelcli.h"
#include "StaticFunctions.h"
#include "stdlib.h"
#include "stdio.h"
#include <fcntl.h>
#include <string>
#include <iostream>

CommandPanelCLI::CommandPanelCLI(int argc, char *argv[])
{
    if (argc < 3)
    {
        promptUsage();
        exit(EXIT_SUCCESS);;
    }
    this->port = 0;
    this->DocumentRoot.clear();
    this->XmlPath.clear();
    this->state = false;
    parseArguments(argc, argv);
    std::cout << "Welcome to Zia Server !" << std::endl;
}

CommandPanelCLI::~CommandPanelCLI()
{
    if (state == true)
        delete this->network;

}

void    CommandPanelCLI::parseArguments(int argc, char *argv[])
{
    if (!(this->port = atoi(getValueFromArgv(argc, argv, "-p"))))
    {
        this->promptUsage();
        exit(EXIT_SUCCESS);
    }
    this->DocumentRoot = getValueFromArgv(argc, argv, "-D");
    if ((this->XmlPath = HandleXArgv(getValueFromArgv(argc, argv, "-X"))) == "NULL")
        std::cout << "Could not load XML file, running defaults values ..." << std::endl;
}

void    *threadCallCLI(void *data)
{
    struct  CPanelData *cli;

    cli = static_cast<CPanelData*>(data);
    if ((*cli->CPanelErrno = cli->network->StartServer()) != OK)
    {
        cli->thread->p = NULL;
        pthread_exit(cli->CPanelErrno);
    }
    return NULL;
}

void    *threadCallNotifierCli(void *data)
{
    struct  CPanelData     *cli;

    cli = static_cast<CPanelData*>(data);
    pthread_join(*cli->thread, NULL);
    CommandPanelCLI::printState(*cli->CPanelErrno);
    pthread_exit(cli->CPanelErrno);
    return cli->CPanelErrno;
}

void    CommandPanelCLI::ShellStopFunction(char *buf)
{
    std::cout << "test";
}

int     CommandPanelCLI::start()
{
    struct  CPanelData      cli;
    char                    buffer[1024];

    this->network = new AbstractSocketClassWindows(this->port, this->DocumentRoot, this->XmlPath);
    this->state = true;
    cli.network = this->network;
    cli.CPanelErrno = &this->CPanelErrno;
    cli.thread = &this->thread;
    if (pthread_create(&this->thread, NULL, threadCallCLI, &cli) == -1)
        return PTHREADERROR;
    if (pthread_create(&this->threadNotifier, NULL, threadCallNotifierCli, &cli) == -1)
        return PTHREADERROR;
    std::cout << "Notice : Server is being launched on port " << this->port << " ...\n" << std::endl;
    while (1)
    {
        memset(buffer, '\0', 1024);
        write(1, ">", 1);
        read(0, buffer, 1024);
        if (strlen(buffer) > 2)
        {
            if (!strcmp(buffer, "stop\n\n"))
                this->stop();
            else if (!strcmp(buffer, "restart\n\n"))
                this->restart();
            else if (!strcmp(buffer, "state\n\n"))
                this->getState() == 1 ? std::cout << "Server is online\n" : std::cout << "Server is offline" << std::endl;
            else if (!strcmp(buffer, "exit\n\n"))
                exit(EXIT_SUCCESS);
            else
                std::cout << "Error : Command unknown" << std::endl;
        }
    }
    return OK;
}

int     CommandPanelCLI::stop()
{
    if (this->state == false)
        return -1;
    if (pthread_cancel(this->thread) == -1)
        std::cout << "Could not delete thread " << this->thread.p << std::endl;
    if (pthread_cancel(this->threadNotifier) == -1)
        std::cout << "Could not delete thread " << this->thread.p << std::endl;
    this->network->StopServer();
    this->state = false;
    std::cout << "Server has been stopped" << std::endl;
    return 0;
}

int     CommandPanelCLI::restart()
{
    if (this->state == true)
        this->stop();
    this->start();
    return 0;
}

void     CommandPanelCLI::printState(int code)
{
    if (code == BINDERROR)
        std::cout << "\nNotifier : Error Code 3 : Server failed to bind given port" << std::endl;
    else if (code == INVALIDSOCKET)
        std::cout << "\nNotifier : Error Code 1 : Server failed to create a socket" << std::endl;
    else if (code == LISTENERROR)
        std::cout << "\nNotifier : Error Code 4 : Server failed to listen on the binded port" << std::endl;
    else if (code == PTHREADERROR)
        std::cout << "\nNotifier : Error Code 5 : Server failed to create a thread" << std::endl;
    else if (code == ACCEPTERROR)
        std::cout << "\nNotifier : Error Code 6 : Server does not accept new connection" << std::endl;
}

void    CommandPanelCLI::promptUsage()
{
    std::cout << "Usage: ./ZiaServer -p Port [-D DocumentRoot] [-X XmlPath]" << std::endl;
}
