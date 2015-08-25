#include "abstractsocketclasswindows.h"
#include <stdio.h>
#include <fcntl.h>
#include <iostream>

AbstractSocketClassWindows::AbstractSocketClassWindows(unsigned int port, std::string DocumentRoot, std::string XmlPath)
{
    this->port = port;
    this->DocumentRoot = DocumentRoot;
    this->XmlPath = XmlPath;
}

AbstractSocketClassWindows::~AbstractSocketClassWindows()
{
    closesocket(this->socketClient);
    closesocket(this->sock);
}

int     AbstractSocketClassWindows::CreateTcpSocket()
{
    WSADATA WSAData;
    struct  sockaddr_in sin;

    WSAStartup(MAKEWORD(2,2), &WSAData);
    if ((this->sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        this->Ziaerrno = INVALIDSOCKET;
        return -1;
    }
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(this->port);
    if (bind(this->sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
        return BINDERROR;
    if (listen(this->sock, 5) == -1)
        return LISTENERROR;
    return OK;
}

int     AbstractSocketClassWindows::StartServer()
{
    if ((this->Ziaerrno = this->CreateTcpSocket()) != OK)
        return this->Ziaerrno;
    if ((this->Ziaerrno = this->LaunchMainLoop()) != OK)
        return this->Ziaerrno;
    return OK;
}

int     AbstractSocketClassWindows::LaunchMainLoop()
{
    for (this->nbClient = 0; 1; )
    {
        struct sockaddr_in csin;
        struct ClientData  *client;
        int clientStructSize = sizeof(csin);

        client = new ClientData;
        if ((this->socketClient = accept(this->sock, (struct sockaddr *)&csin, &clientStructSize)) == -1)
            return ACCEPTERROR;
        client->socket = this->socketClient;
        client->ip = inet_ntoa(csin.sin_addr);
        client->port = htons(csin.sin_port);
        client->DocumentRoot = this->DocumentRoot;
        client->XmlPath = this->XmlPath;
        printf("Un client s'est connecte sa socket est la %d nb client est %d\n", socketClient, nbClient);
        if (pthread_create(&this->thread, NULL, threadCallWindows, client) == -1)
            return PTHREADERROR;
    }
    return OK;
}

int     AbstractSocketClassWindows::StopServer()
{
    this->~AbstractSocketClassWindows();
}
