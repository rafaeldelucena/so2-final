#include <stdlib.h>
#include <fcntl.h>
#include <iostream>
#include "serial.h"
#include <stdio.h>

int main(void)
{
    Serial* serial = new Serial("/dev/ttyUSB0", O_RDONLY | O_NOCTTY);
    while(true) {
        char* str = serial->readPort(1);
        std::cout << str << std::endl;
        delete str;

    }
    
    delete serial;
}
