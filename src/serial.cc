#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "serial.h"

#define BAUDRATE B9600

Serial::Serial(const char* port, int flags)
{
    _fd = open(port, flags);
    if (_fd < 0) {
        perror("Unable to open");
    } else {
        fcntl(_fd, F_SETFL, 0);
    }

    memset(&_options, 0, sizeof(_options));
    saveContext();
}

Serial::~Serial(void)
{
    restoreContext();
    close(_fd);
}

void Serial::writePort(const char* str)
{
    static bool flag = false;
    if(!flag) {
        configureWrite(0);
        flag = true;
    }

    if(write(_fd, str, strlen(str)) < 0) {
        perror("Write error");
    }
}

void Serial::configureWrite(int flags)
{
    saveContext();
    configure();

//    _options.c_oflag |= (ONLRET | OPOST);

    tcflush(_fd, TCIFLUSH);
    tcsetattr(_fd, TCSANOW, &_options);
}

void Serial::saveContext(void)
{
    if ((tcgetattr(_fd, &_old) < 0))  {
        perror("Unable to check the options");        
    }
}

void Serial::restoreContext(void)
{
    tcsetattr(_fd, TCSANOW, &_old);
}

/*
* @param size of array of chars
* @return a newly allocated array of chars
*/
char* Serial::readPort(int size)
{
    configureRead(0);
    char* c = new char[size];
    while(true) {
        if (read(_fd, c, size) == size) {
            return c;
        }
    }
    return 0;

}

void Serial::configureRead(int flags)
{
    saveContext();
    configure();
    //  _options.c_iflag = IGNPAR | ICRNL;

    tcflush(_fd, TCIFLUSH);
    tcsetattr(_fd, TCSANOW, &_options);
}

void Serial::configure(void)
{
    _options.c_cflag = (BAUDRATE |  CS8 | CLOCAL | CREAD);
    _options.c_lflag = ~(ICANON | ECHO | ECHOE | ISIG);
    // _options.c_cc[VINTR]    = 0;     /* Ctrl-c */ 
    //_options.c_cc[VQUIT]    = 0;     /* Ctrl-\ */
    //_options.c_cc[VERASE]   = 0;     /* del */
    //_options.c_cc[VKILL]    = 0;     /* @ */
    //_options.c_cc[VEOF]     = 4;     /* Ctrl-d */
     //_options.c_cc[VTIME]    = 0;     /* inter-std::stringacter timer unused */
    //_options.c_cc[VMIN]     = 1;     /* blocking read until 1 std::stringacter arrives */
    //_options.c_cc[VSWTC]    = 0;     /* '\0' */
   // _options.c_cc[VSTART]   = 0;     /* Ctrl-q */ 
   // _options.c_cc[VSTOP]    = 0;     /* Ctrl-s */
   // _options.c_cc[VSUSP]    = 0;     /* Ctrl-z */
       // _options.c_cc[VEOL]     = 0;     /* '\0' */
   // _options.c_cc[VREPRINT] = 0;     /* Ctrl-r */
    //_options.c_cc[VDISCARD] = 0;     /* Ctrl-u */
    //_options.c_cc[VWERASE]  = 0;     /* Ctrl-w */
    //_options.c_cc[VLNEXT]   = 0;     /* Ctrl-v */
    //_options.c_cc[VEOL2]    = 0;     /* '\0' */

}
