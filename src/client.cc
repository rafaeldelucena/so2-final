#include <sys/types.h> 
#include "host.h"

Host::Host(const char* serial, int port)
{
    _port = port;
    _serial = new Serial(serial, B9600);
    _buffer = new char[_size];
}

Host::~Host()
{
    delete _serial;
    delete _buffer;
}

void Host::writeSerial(const char* s)
{
    _serial->write(s);
}

void Host::listenSerial(void)
{
    _serial->read(_size);
}
