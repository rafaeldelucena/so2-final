#include <sys/types.h>
#include "host.h"

Host::Host(int port)
    : _serial("/dev/ttyUSB0", B9600), _socket(port)
{
    _buffer = new char[_size];
}

Host::~Host()
{
    delete _buffer;
}

void Host::writeSerial(const char* s)
{
    _serial.writePort(s);
}

char* Host::readSerial(void)
{
   char* c = _serial.readPort(_size);
   return c;
}
