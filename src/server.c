#include "stdio.h"
#include "sys/types.h"
#include "netinet/in.h"
#include "string.h"
#include "sys/socket.h"
#include "stdlib.h"
#include "unistd.h"

main(int argc, char** argv) {

    int sd,i,len,bi,nsd,port;
    char content[30];
    struct sockaddr_in ser,cli;
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    if((sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==-1) {
        printf("\n Socket problem");
        return 0;
    }
    int porta = atoi(argv[1]);

    printf("\n Socket created\n");
    bzero((char*)&cli,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_port=htons(porta);
    ser.sin_addr.s_addr=htonl(INADDR_ANY);
    bi=bind(sd,(struct sockaddr *)&ser,sizeof(ser));

    if(bi==-1) {
        printf("\n bind error, port busy, plz change port in client and server");
        return 0;
    }

    i=sizeof(cli);
    listen(sd,5);
    while (1) {
        printf("\n Esperando nova conexao");
        nsd = accept(sd,((struct sockaddr *)&cli),&i);

        if(nsd==-1) {
            printf("\ncheck the description parameter\n");
            return 0;
        }

        printf("\nConnection accepted");

        if(fork()) {
            printf("\n NOVO FORK");

            while(1) {
                printf("\n Enviando para cliente:");
                scanf("%s",content);
                if (send(nsd,content,30,0) != -1) {
                    printf("MSG (%s) ENVIADA PARA CLIENTE", content);
                } else {
                    printf("ERRO AO ENVIAR MSG (%s) PARA CLIENTE", content);
                }
            }
        } else {
            i = recv(nsd,content,30,0);
            while((strcmp(content,"exit") != 0) && i != 0) { //&& flagpeer > -1) { 
                printf("Value of nsd %i \n", nsd);
                printf("\nReceived from client x %s\n",content);
                i=recv(nsd,content,30,0);
                printf("\nVALOR I: %i", i);
                if (i == 0) {
//                    printf("\nClient morreu");
//                    close(nsd);
//                    break;
                }
            }
            printf("Cliente morreuuuuu");
            close(nsd);
        }
    }

    printf("\n Bye");
    close(sd);
    close(nsd);
    return 0;
}
