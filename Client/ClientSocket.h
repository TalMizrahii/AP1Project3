

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

    // Setter for the ip of the server.
    void setIp(string ip1);

    // Setter for the port number of the server.
    void setPort(int portNumber);

    // Getter for the ip of the server.
    string getIp();

    // Getter for the port number of the server.
    int getPort();

    // Create a socket with the server details.
    int creatClientSocket();

    // Sending data to the server.
    void sendToServer(int sock);

    // Getting the server reply.
    string receiveData(int clientSocket);

protected:
    // Create a socket.
    int makeNewSocket();

    // Create the struct needed for creating a socket.
    sockaddr_in creatAddrInStruct();


private:
    string ip;
    int port;
    UserVectorInput userVectorInput;

};

#endif //EX3_CLIENTSOCKET_H
