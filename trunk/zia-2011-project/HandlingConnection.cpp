#include "HandlingConnection.h"
#include "AbstractSocketClass.h"
#include <QStringList>
#include <QString>
#include <fcntl.h>
#include <sys/stat.h>
#include <iostream>

/********************************
        Main Client Thread
********************************/

void    *threadCallWindows(void* data)
{
    struct ClientData   *client;
    char                buffer[BYTES_TO_READ];

    client = static_cast<ClientData*>(data);
    std::cout << client->DocumentRoot << client->XmlPath << std::endl;
    recv(client->socket, buffer, BYTES_TO_READ, 0);
    QString reponse = "HTTP/1.1 200 OK\r\nDate : Thu, 31 Mar 2011 10:47:12 GMT\r\nServer : Microsoft-IIS/2.0\r\nContent-Type : text/html\r\nConnection: Close\r\n\r\ntoto";
        //qDebug(buffer);
        send(client->socket, reponse.toStdString().c_str(), reponse.length(), 0);
        closesocket(client->socket);

    return NULL;
}
