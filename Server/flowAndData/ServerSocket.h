#ifndef EX3_SERVERSOCKET_H
#define EX3_SERVERSOCKET_H

#include <cstdlib>
#include <string>
#include <utility>
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

/**
 *
 */
class ServerSocket {
public:

    // A default destructor.
    ~ServerSocket();

    // A default constructor.
    ServerSocket();

    // A constructor witch receives a port number for the socket to bind and a path to a file database.
    ServerSocket(int port, string path);

    // Setter for the path.
    void setPath(string path);

    // A setter for the port number.
    void setPort(int port);

    // A getter for the path to the file database.
    string getPath();

    // A getter for the port number.
    int getPort();

    // Checking if the user sent a request to end the connection.
    bool endConnectionCheck(const string &strToCheck);

    // The central method of the class. Responsible to create and run the server's socket.
    int creatServerSocket();

    // Running the server.
    void runServer(int serverSocket);

private:
    // The current port number the socket is bind to.
    int portNum{};
    // The current path to the database file.
    string pathToFile;
};

#endif //EX3_SERVERSOCKET_H
