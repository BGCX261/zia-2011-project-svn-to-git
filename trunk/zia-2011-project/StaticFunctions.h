#ifndef STATICFUNCTIONS_H
#define STATICFUNCTIONS_H

#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include <ostream>
#include <fstream>
#include <unistd.h>
#include "limits.h"
#include <winsock2.h>

int     isgui(int argc, char *argv[]);
const char    *getValueFromArgv(int argc, char *argv[], const char *opt);
std::string   HandleXArgv(const char *file);
std::string   CurrentDirectory();
bool          FileExist(const std::string *file);
int           SendString(int sock, const char *data);

#endif // STATICFUNCTIONS_H
