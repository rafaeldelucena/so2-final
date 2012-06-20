#ifndef _GLUE_HOST_H_
#define _GLUE_HOST_H_

#include "serial.h"
#include "socket.h"

class Host
{
    public:
    Host(int port);
    ~Host(void);

    void sendMessage(const char*);
    void writeSerial(const char*);
    char* readSerial(void);
    private:
    Serial _serial;
    Socket _socket;
    int _port, _size;
    char* _buffer;
};

#endif // _GLUE_HOST_H_
