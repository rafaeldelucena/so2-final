#include <errno.h>
#include "socket.h"

Socket::Socket(int port)
    : _port(port)
{
    if((_connection = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("Socket error");
    }
}

Socket::~Socket()
{
    close(_socket);
    close(_connection);
}

void Socket::configAddress(int port)
{
    bzero(&_addr, sizeof(_addr));
    _addr.sin_family = AF_INET;
    _addr.sin_port(port);
    _addr.sin_addr.s_addr=htonl(INADDR_ANY);
}

void Socket::connect(void)
{
    configAddress();
    _connection = connect(_socket, &_addr, sizeof(_addr));
    if(_connection == -1) {
        perror("Connection error");
    }
}
