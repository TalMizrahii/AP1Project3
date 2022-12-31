

#ifndef EX3_CLIENTSOCKET_H
#define EX3_CLIENTSOCKET_H

#include <cstring>
#include "UserVectorInput.h"
#include <cstdlib>
#include <utility>
#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

class ClientSocket {
public:
    // The constructor of the class.
    explicit ClientSocket(string ip1, int portNumber);

    // The Destructor of the class.
    ~ClientSocket();

    void setIp(string ip1);

    void setPort(int portNumber);

    string getIp();

    int getPort();

    int creatClientSocket();

protected:
    int makeNewSocket();
    sockaddr_in creatAddrInStruct();


private:
    string ip;
    int port;
    UserVectorInput userVectorInput;


};

#endif //EX3_CLIENTSOCKET_H
