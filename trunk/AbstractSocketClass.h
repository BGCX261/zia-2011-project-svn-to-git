#ifndef IABSTRACTSOCKETCLASS_H
#define IABSTRACTSOCKETCLASS_H

#include <winsock2.h>
#include <string>

#define MAXIMUM_CLIENTS 100

enum    NetworkCodes
{
    INVALIDSOCKET = 1,
    OK       = 2,
    BINDERROR = 3,
    LISTENERROR = 4,
    PTHREADERROR = 5,
    ACCEPTERROR = 6

};

struct ClientData
{
    int                 socket;
    int                 port;
    std::string         ip;
    std::string         DocumentRoot;
    std::string         XmlPath;
};

class   IAbstractSocketClass
{
    virtual int                 StartServer() = 0;
    virtual int                 StopServer() = 0;
};

#endif // IABSTRACTSOCKETCLASS_H
