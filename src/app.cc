#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "serial.h"

int main(void)
{
    Serial* serial = new Serial("/dev/ttyUSB0", O_WRONLY | O_NOCTTY);
    
    char c;
    std::cout << "Digite: " << std::endl;
    std::cin >> c;
    serial->writePort(&c);

    delete serial;
    return 0;
}
