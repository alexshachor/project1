//
// Created by alexander on 12/26/18.
//

#include "ClientManagement.h"

int ClientManagement::sockfd = 0;

void ClientManagement::connectToServer(string serverIp, int portno) {


    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    int socketResult = socket(AF_INET, SOCK_STREAM, 0);

    if (socketResult < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    ClientManagement::sockfd = socketResult;
    server = gethostbyname(serverIp.c_str());
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }


}

void ClientManagement::sendMessage(string message) {

    /* Send message to the server */
    if (!ClientManagement::sockfd) {
        throw ("sockfd has not been initialized");
    }
    int n = write(ClientManagement::sockfd, message.c_str(), message.size());

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Now read server response */
    // int size =1024;
    // char buffer[size];
    // bzero(buffer, size);
    // n = read(ClientManagement::sockfd, buffer, size-1);

    // if (n < 0) {
    //     perror("ERROR reading from socket");
    //     exit(1);
    // }
}