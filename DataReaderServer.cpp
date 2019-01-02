#include "DataReaderServer.h"

void *runServerThread(void *arg) {

    int *params = (int *) arg;
    int sockfd, newsockfd, portno, clilen;
    int size = 1024;
    char buffer[size];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = (*params)++;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    MapsManagement::pathValueInit();

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,
                       (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


    /* If connection is established then start communicating */
    while () {
        bzero(buffer, size);
        n = read(newsockfd, buffer, size - 1);
        std::string str(buffer);
        vector<string> strArr = FileHelper::split(str, VALUES_DELIMITER);
        pthread_mutex_lock(&mutex);
        MapsManagement::updateSymbolTable(strArr);
        pthread_mutex_unlock(&mutex);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        /* Write a response to the client */
        // n = write(newsockfd, "I got your message", 18);
    }
    close(sockfd);
}

void *DataReaderServer::runServer(void *args) {
    pthread_t trid;
    pthread_create(&trid, nullptr, runServerThread, args);

}