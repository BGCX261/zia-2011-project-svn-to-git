#ifndef HEADER_H
#define HEADER_H
#include "entityheader.h"
#include "general_header.h"
#include "requestheader.h"
#include "request.h"

class header
{
public:
    EntityHeader entityHeader;
    GeneralHeader generalHeader;
    RequestHeader requestHeader;
    Request request;
    header();
};

#endif // HEADER_H
