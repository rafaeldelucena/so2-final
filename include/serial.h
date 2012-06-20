#ifndef _GLUE_SERIAL_H_
#define _GLUE_SERIAL_H_

#include <termios.h>

class Serial
{
    public:
    Serial(const char* port, int flags);
    ~Serial(void);
    char* readPort(int size);
    void writePort(const char*);
    
    private:
    void configure(void);
    void configureRead(int flags);
    void configureWrite(int flags);
    void saveContext(void);
    void restoreContext(void);

    int _fd;
    struct termios _options, _old;
    char* _buffer;

};

#endif // _GLUE_SERIAL_H_
