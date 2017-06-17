//
// Created by gerardo on 13/06/17.
//

#ifndef SERVER_CLIENTAPP_H
#define SERVER_CLIENTAPP_H

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
using  namespace std;

#define MENS_MAX_LEN 500


void panic(char *msg)
{
    fprintf (stderr, "Fatal error: %s (errno %d, %s)\n", msg, errno, strerror(errno));
    exit(2);
}

string Client(char *Serv, int Port, char *MSJ) {
    char *server;
    int port;
    int socketfd;
    int finish = 0;
    char mens[MENS_MAX_LEN];
    struct sockaddr_in serverAddress, clientAddress;
    struct hostent *h;

    fd_set readmask;
    struct timeval timeout;
    size_t recvsize;

    server = Serv;
    port = Port;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd==-1)
        panic("Failed to create socket");

    clientAddress.sin_family = AF_INET;
    clientAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    clientAddress.sin_port = htons(0);

    if (bind(socketfd, (struct sockaddr *)&clientAddress, sizeof(clientAddress))==-1)
        panic("Binding address");

    h = gethostbyname(server);
    serverAddress.sin_family = h->h_addrtype;
    memcpy((char*) &serverAddress.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
    serverAddress.sin_port = htons(port);

    if (connect(socketfd, (struct sockaddr * )&serverAddress, sizeof(serverAddress))==-1)
        panic("Cannot connect");

    while (!finish) {
        FD_ZERO(&readmask);
        FD_SET(socketfd, &readmask);
        FD_SET(STDIN_FILENO, &readmask);
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000;

        if (select(socketfd + 1, &readmask, NULL, NULL, &timeout) == -1)
            panic("Error on SELECT");

        if (FD_ISSET(socketfd, &readmask)) {
            recvsize = recv(socketfd, mens, MENS_MAX_LEN, 0);
            if (recvsize == -1)
                panic("Cannot receive information");
            mens[recvsize] = '\0';
            send(socketfd, "EXIT", 4, 0);
            finish=1;
        }
        if (send(socketfd, MSJ, 500, 0) == -1)
                    panic("Cannot sent message");

    }
    return mens;


}

#endif //SERVER_CLIENTAPP_H
