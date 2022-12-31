#ifndef EX3_SERVERSOCKET_H
#define EX3_SERVERSOCKET_H

#include <cstdlib>
#include <string>

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

    // The central method of the class. Responsible to create and run the server's socket.
    void runServer();

    // Setter for the path.
    void setPath(string path);

    // A setter for the port number.
    void setPort(int port);

    // A getter for the path to the file database.
    string getPath();

    // A getter for the port number.
    int getPort();

private:
    // The current port number the socket is bind to.
    int portNum{};
    // The current path to the database file.
    string pathToFile;

};

#endif //EX3_SERVERSOCKET_H
