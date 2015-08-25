#ifndef ABSTRACTSOCKETCLASS_H
#define ABSTRACTSOCKETCLASS_H

#include <string>
#include <pthread.h>
#include "AbstractSocketClass.h"

void               *threadCallWindows(void *data);

class AbstractSocketClassWindows : public IAbstractSocketClass
{
private:
    unsigned int        port;
    unsigned int        Ziaerrno;
    std::string         DocumentRoot;
    std::string         XmlPath;
    int                 sock;
    int                 nbClient;
    int                 socketClient;
    pthread_t           thread;

    int                 CreateTcpSocket();
    int                 LaunchMainLoop();

public:
    AbstractSocketClassWindows(unsigned int port, std::string DocumentRoot, std::string XmlPath);
    ~AbstractSocketClassWindows();
    virtual int         StartServer();
    virtual int         StopServer();

};

#endif // ABSTRACTSOCKETCLASS_H
