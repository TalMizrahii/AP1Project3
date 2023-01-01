

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
    explicit ClientSocket(string ipAddress, int portNumber);

    // The Destructor of the class.
    ~ClientSocket();

    // Setter for the ip of the server.
    void setIp(string ipAddress);

    // Setter for the port number of the server.
    void setPort(int portNumber);

    // Getter for the ip of the server.
    string getIp();

    // Getter for the port number of the server.
    int getPort();


    // Control the flow of receive and send to the sever.
    void runClient();

protected:
    // Create a socket.
    int makeNewSocket();

    // Create a socket with the server details.
    int creatClientSocket();

    // Sending data to the server.
    bool sendToServer(int sock);

    // Getting the server reply.
    long receiveData(int clientSocket, char *buffer, int expectedDataLen);

    // Create the struct needed for creating a socket.
    sockaddr_in creatAddrInStruct();

    // Concatenating a char* to a string.
    string creatString(char *buffer, long readBytes);


private:
    string ip;
    int port;
    UserVectorInput userVectorInput;


};

#endif //EX3_CLIENTSOCKET_H
