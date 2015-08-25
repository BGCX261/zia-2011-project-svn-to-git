#ifndef COMMANDPANEL_H
#define COMMANDPANEL_H

#ifdef WIN32
    #include "abstractsocketclasswindows.h"
#else
    #include "abstractsocketclasslinux.h"
#endif

struct  CPanelData
{
    AbstractSocketClassWindows  *network;
    int                         *CPanelErrno;
    pthread_t                   *thread;
};

class   ICommandPanel
{
public:
    virtual int                 start() = 0;
    virtual int                 stop() = 0;
    virtual int                 restart() = 0;
    inline  virtual bool        getState() {return this->state;}

protected:
    bool                        state;
    int                         port;
    int                         CPanelErrno;
    std::string                 DocumentRoot;
    std::string                 XmlPath;

};

#endif // COMMANDPANEL_H
