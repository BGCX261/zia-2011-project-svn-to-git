#ifndef ABSTRACTSOCKETCLASS_H
#define ABSTRACTSOCKETCLASS_H

#include <string>
#include <pthread.h>
#include "AbstractSocketClass.h"

void               *threadCallLinux(void *data);

class AbstractSocketClassLinux : public IAbstractSocketClass
{
private:
    unsigned int        port;
    unsigned int        Ziaerrno;
    std::string         DocumentRoot;
    std::string         XmlPath;
    int                 sock;
    int                 nbClient;
    int                 socketClient[MAXIMUM_CLIENTS];
    pthread_t           thread[MAXIMUM_CLIENTS];

    int                CreateTcpSocket();
    int                LaunchMainLoop();

public:
    AbstractSocketClassLinux(unsigned int port, std::string DocumentRoot, std::string XmlPath);
    ~AbstractSocketClassLinux();
    virtual int                 StartServer();
    virtual int                 StopServer();

};

#endif // ABSTRACTSOCKETCLASS_H
