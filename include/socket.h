#ifndef _GLUE_SOCKET_H_
#define _GLUE_SOCKET_H_

#include <sys/socket.h>

class Socket
{
    public:
    Socket(int port);
    ~Socket();
    void connect(void);

    private:
    void configAddress(void);
    struct sockaddr_in _addr;
    int _socket, _connection;

};

#endif // _GLUE_SOCKET_H_
