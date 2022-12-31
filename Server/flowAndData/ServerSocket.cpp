#include "ServerSocket.h"

#include <utility>

/**
 * A default destructor.
 */
ServerSocket::~ServerSocket() = default;

/**
 * A default Constructor.
 */
ServerSocket::ServerSocket() = default;

/**
 * A constructor receiving a port number to bind to the socket and a path to the database file.
 * @param port A port number to bind to the socket.
 * @param path A path to a file database.
 */
ServerSocket::ServerSocket(int port, string path) {
    setPath(std::move(path));
    setPort(port);
}

/**
 * A setter for the path to the file data base.
 * @param path The path to the file data base.
 */
void ServerSocket::setPath(string path) {
    this->pathToFile = std::move(path);
}

/**
 * A setter for the port number to bind to the socket.
 * @param port The port number to bind to the socket.
 */
void ServerSocket::setPort(int port) {
    this->portNum = port;
}

/**
 * A getter for the path to the file database.
 * @return The path to the file data base.
 */
string ServerSocket::getPath() {
    return this->pathToFile;
}

/**
 * A getter for the port of the server's socket.
 * @return The port number to bind to the socket.
 */
int ServerSocket::getPort() {
    return this->portNum;
}

/**
 * The central method of the class. Responsible to create and run the server's socket.
 */
void ServerSocket::runServer() {

}


