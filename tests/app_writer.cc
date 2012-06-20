#include <fcntl.h>
#include <iostream>
#include "serial.h"

int main(void)
{
    Serial* serial = new Serial("/dev/ttyUSB0", O_WRONLY | O_NOCTTY);

    char str;
    while(true) {
        std::cout << "Digite: " << std::endl;
        std::cin >> str;
        serial->writePort(&str);
    }

    delete serial;
    return 0;
}
