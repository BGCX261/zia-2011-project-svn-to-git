#include "StaticFunctions.h"
#include <iostream>
#include <fcntl.h>

int isgui(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
        if (!strcmp(argv[i], "-gui"))
            return (1);
    return (0);
}

const   char    *getValueFromArgv(int argc, char *argv[], const char *opt)
{
    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i], opt))
        {
            if (i < argc - 1)
                return argv[i + 1];
        }
    }
    return ("NULL");
}

bool            FileExist(const std::string file)
{
    int         fd;

    if ((fd = open(file.c_str(), O_RDONLY)) == -1)
        return false;
    close(fd);
    return true;
}

std::string     CurrentDirectory()
{
    std::string cur;
#ifdef WIN32
    int size = PATH_MAX;
#elif LINUX
    int size = MAXPATHLEN;
#else
    int size = 250;
#endif
    char        buffer[size];
    getcwd(buffer, size);
    cur = buffer;
    return cur + "\\";
}

std::string     HandleXArgv(const char *file)
{
    std::string buffer;

    buffer = file;
    if (buffer == "NULL")
    {
        if (FileExist("ziad.xml"))
            return ("ziad.xml");
        else
            return "NULL";
    }
    return (FileExist(file) ? buffer : "NULL");
}

int             SendString(int sock, const char *data)
{
    int         code;

    if ((code = send(sock, data, strlen(data), 0)) == -1)
        std::cout << "Error : Send : Cannot send data" << std::endl;
    return (code);
}
