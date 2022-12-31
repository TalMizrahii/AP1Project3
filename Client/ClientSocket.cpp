
#include "ClientSocket.h"

#include <utility>


/**
 * A default destructor.
 */
ClientSocket::~ClientSocket() = default;

ClientSocket::ClientSocket(string ip1, int portNumber) {
    setIp(std::move(ip1));
    setPort(portNumber);
}

void ClientSocket::setIp(string ip1) {
    this->ip = std::move(ip1);
}

void ClientSocket::setPort(int portNumber) {
    this->port = portNumber;
}

string ClientSocket::getIp() {
    return this->ip;
}

int ClientSocket::getPort() {
    return this->port;
}

/**
 * The central method of the class. Responsible to create the client's socket.
 * @return The client's socket.
 */
int ClientSocket::creatClientSocket() {
    // Create a new socket.
    int serverSocket = makeNewSocket();
    struct sockaddr_in sin = creatAddrInStruct();
    return serverSocket;
}

/**
 * Creating a new socket.
 * @return An int representing a socket.
 */
int ClientSocket::makeNewSocket() {
    // Creat a new socket.
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    // If the creation didn't work, raise an error.
    if (serverSocket < 0) {
        perror("Error binding socket.");
    }
    return serverSocket;
}

/**
 * Creat a sockaddr_in for the client's socket.
 * @return struct of sockaddr_in.
 */
struct sockaddr_in ClientSocket::creatAddrInStruct() {
    // Create a struct for the socket's data.
    struct sockaddr_in sin{};
    // Set values to it of it's size (in bytes).
    memset(&sin, 0, sizeof(sin));
    // Set the protocol of the connection to the struct.
    sin.sin_family = AF_INET;
    // Set the addresses values of the socket.
    sin.sin_addr.s_addr = INADDR_ANY;
    // Get the current port.
    const int serverPort = getPort();
    // Set the current port of the server to the struct.
    sin.sin_port = htons(serverPort);
    return sin;
}


