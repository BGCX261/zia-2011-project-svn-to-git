#include "abstractsocketclasslinux.h"
#include <stdio.h>
#include <fcntl.h>

AbstractSocketClassLinux::AbstractSocketClassLinux(unsigned int port, std::string DocumentRoot, std::string XmlPath)
{
    this->port = port;
    this->DocumentRoot = DocumentRoot;
    this->XmlPath = XmlPath;
}

AbstractSocketClassLinux::~AbstractSocketClassLinux()
{
    for (int i = 0; i < this->nbClient; i++)
        closesocket(this->socketClient[i]);
    closesocket(this->sock);
}

int     AbstractSocketClassLinux::CreateTcpSocket()
{
    struct  sockaddr_in sin;

    if ((this->sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        this->Ziaerrno = INVALIDSOCKET;
        return -1;
    }
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(this->port);
    if (bind(this->sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
        this->Ziaerrno = BINDERROR;
        return -1;
    }
    if (listen(this->sock, 5) == -1)
    {
        this->Ziaerrno = LISTENERROR;
        return -1;
    }
    return OK;
}

int     AbstractSocketClassLinux::StartServer()
{
    if ((this->Ziaerrno = this->CreateTcpSocket()) != OK)
        return this->Ziaerrno;
    printf("Server launched on port %d\n", this->port);
    if ((this->Ziaerrno = this->LaunchMainLoop()) != OK)
        return this->Ziaerrno;
    return OK;
}

void    *threadCallLinux(void* data)
{
    struct ClientData   *client;
    char                buffer[1024];

    memset(buffer, '\0', 1024);
    client = static_cast<ClientData*>(data);
    recv(client->socket, buffer, 1024, 0);
    printf("Buffer : %s\n", buffer);
    return NULL;
}

int     AbstractSocketClassLinux::LaunchMainLoop()
{
    for (this->nbClient = 0; 1; nbClient++)
    {
        struct sockaddr_in csin;
        struct ClientData  client;
        int clientStructSize = sizeof(csin);

        if ((this->socketClient[nbClient] = accept(this->sock, (struct sockaddr *)&csin, &clientStructSize)) == -1)
            return ACCEPTERROR;
        client.socket = this->socketClient[nbClient];
        client.ip = inet_ntoa(csin.sin_addr);
        client.port = htons(csin.sin_port);
        printf("Un client s'est connecte sa socket est la %d nb client est %d\n", socketClient[nbClient], nbClient);
        if (pthread_create(&this->thread[nbClient], NULL, threadCallLinux, &client) == -1)
            return PTHREADERROR;
    }
    return OK;
}

int     AbstractSocketClassLinux::StopServer()
{

}
