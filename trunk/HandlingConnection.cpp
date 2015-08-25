#include "HandlingConnection.h"
#include "AbstractSocketClass.h"
#include "zfile.h"
#include "reponse.h"
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
    //struct file fichier;
    struct folder fichier;
    std::string httpVersion = "1.1";

    memset(buffer, '\0', BYTES_TO_READ);
    client = static_cast<ClientData*>(data);
    recv(client->socket, buffer, BYTES_TO_READ, 0);
    QString toto = buffer;
    toto = toto.split("\r\n").at(0).split(" ").at(1);
    std::string extension = toto.toStdString();
    std::cout << "Fichier a lire : " << toto.toStdString().c_str() << "\n";
    int offset = extension.find('.');
    extension = extension.substr(offset + 1, extension.length());
    std::cout << "Extension du fichier : " << extension.c_str() << "\n";
    fichier.filename = toto.toStdString();
    fichier.ext = extension.c_str();
    fichier.filepath = "";
    zFile *reader = new zFile(fichier, client->DocumentRoot);
    Reponse *builder = new Reponse("Zia-Server", reader->getReturnCode(), httpVersion, "GET", reader->getContentType(), reader->getDocumentLength());
    std::cout << builder->getResponse();
    QString reponse = "HTTP/1.1 200 OK\r\nDate : Thu, 31 Mar 2011 10:47:12 GMT\r\nServer : Microsoft-IIS/2.0\r\nContent-Type : text/html\r\nConnection: Close\r\n\r\n";
        //qDebug(buffer);
    send(client->socket, builder->getResponse().c_str(), builder->getResponse().length(), 0);
    send(client->socket, reader->getDocumentContent(), reader->getDocumentLength(), 0);
    closesocket(client->socket);
    delete reader;
    delete builder;

    return NULL;
}
