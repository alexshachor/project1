#ifndef PROJECT1_DATAREADERSERVER_H
#define PROJECT1_DATAREADERSERVER_H

#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <vector>
#include "FileHelper.h"
#include "MapsManagement.h"

#define VALUES_DELIMITER ','

using namespace std;

class DataReaderServer {
public:
    void *runServer(void *args);
};


#endif //PROJECT1_DATAREADERSERVER_H
