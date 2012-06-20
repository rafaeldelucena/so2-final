#include "stdio.h"
#include "sys/types.h"
#include "netinet/in.h"
#include "string.h"
#include "sys/socket.h"
#include "stdlib.h"
#include "unistd.h"


#include <iostream>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#define BAUDRATE B9600

/* 

int writer(const char* str)
{
    struct termios _options;
    int _fd = openPort("/dev/ttyUSB0", O_WRONLY | O_NOCTTY);

    _options.c_cflag = (BAUDRATE |  CS8 | CLOCAL | CREAD);
    _options.c_lflag = ~(ICANON | ECHO | ECHOE | ISIG);
//  _options.c_oflag |= (ONLRET | OPOST);

    tcflush(_fd, TCIFLUSH);
    tcsetattr(_fd, TCSANOW, &_options);

    printf("Enviando: %s \n", str);
    printf("Tamanho: %lu\n ", strlen(str));
    if(write(_fd, str, strlen(str)) < 0) {
        perror("Write error");
    }
    printf("Enviado \n");
    close(_fd);
}
 */
int main(int argc, char** argv) {
/* 
    int sd,con,port,i;
    char content1[30];
    char content2[30];
    struct sockaddr_in cli;
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    if((sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==-1) {
        printf("\n Socket problem");
        return 0;
        }

    int porta = atoi(argv[1]);
    bzero((char*)&cli,sizeof(cli));
    cli.sin_family = AF_INET;
    cli.sin_port=htons(porta);
    cli.sin_addr.s_addr=htonl(INADDR_ANY);
    con=connect(sd,(struct sockaddr*)&cli,sizeof(cli));
    if(con==-1) {
        printf("\n connection error");
        return 0;
    }

    if(fork()) {
        printf("\nEnter the data to be send type exit for stop: ");
        scanf("%s",content1);
        while(strcmp(content1,"exit")!=0) {
            send(sd,content1,30,0);
            scanf("%s",content1);
        }
        send(sd,"exit",5,0);
    }
    else {
        while((strcmp(content2,"exit") != 0)) { 
            i=recv(sd,content2,30,0);
            printf("RECEBEU DO SERVER: '%s'\n",content2);
            writer(content2);

            if (i == 0) {
                printf("Server morreu");
                break;
            }
        }
    }
    close(sd);
    close(con);*/
    int _fd = open("/dev/ttyUSB0", O_RDONLY | O_NOCTTY);
    int _size = 1;
    
    if (_fd < 0) {
        perror("Unable to open");
    } else {
        fcntl(_fd, F_SETFL, 0);
    }
    static struct termios _options;
    _options.c_cflag = (BAUDRATE |  CS8 | CLOCAL | CREAD);
    _options.c_lflag = ~(ICANON | ECHO | ECHOE | ISIG);
    tcflush(_fd, TCIFLUSH);
    tcsetattr(_fd, TCSANOW, &_options);
    
//   char* str = (char*) malloc(_size * sizeof(char));
    char c[1];
    char d;
    while(1) {
        if ((read(_fd, c, _size) == _size)) {

            printf("Aqui! aa\n");
            std::cout << c << std::endl;
            printf("Bizarro!");
        }
    }
    //char* str = (char*) malloc(size * sizeof(char));

/*     while(1) {
        if(!(read(_fd, str, size) < size)) { 
            str[size] = 0;
        }
    }*/
    printf("saí!\n");
    close(_fd);
    return 0;
}
