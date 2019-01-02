//
// Created by alexander on 12/26/18.
//

#ifndef PROJECT1_CLIENTMANAGEMENT_H
#define PROJECT1_CLIENTMANAGEMENT_H


#include "string"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

using namespace std;

class ClientManagement {
private:
    static int sockfd;
public:
    static void connectToServer(string serverIp, int portno);

    static void sendMessage(string message);
};


#endif //PROJECT1_CLIENTMANAGEMENT_H
