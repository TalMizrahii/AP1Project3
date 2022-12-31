#include "ServerSocket.h"


/**
 * A default destructor.
 */
ServerSocket::~ServerSocket() = default;

/**
 * A default Constructor setting default values to the port and path.
 */
ServerSocket::ServerSocket() {
    setPort(12345);
    setPath("/home/tal/Desktop/AP1/ex3/datasets/iris/iris_classified.csv");
}

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
 * The central method of the class. Responsible to create the server's socket.
 * @return The server's socket.
 */
int ServerSocket::creatServerSocket() {
    // Create a new socket.
    int serverSocket = makeNewSocket();
    struct sockaddr_in sin = creatAddrInStruct();
    // Bind the struct with all data to the server's socket, check if the binding worked.
    serverSocket = bindSocket(serverSocket, sin);
    serverSocket = setListen(5);
    return serverSocket;
}

/**
 * Binding a socket to a port number.
 * @param port The port number to bind.
 * @param sin The struct number to bind.
 * @return the socket after binding.
 */
int ServerSocket::bindSocket(int serverSocket, sockaddr_in sin) {
    if (bind(serverSocket, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        // If the binding didn't work, raise an error.
        perror("Error binding socket.");
    }
    return serverSocket;
}

/**
 * Creat a sockaddr_in for the server's socket.
 * @return struct of sockaddr_in.
 */
struct sockaddr_in ServerSocket::creatAddrInStruct() {
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

/**
 * Setting a given socket to listen to a specific number of client.
 * @param numOfListens The number of client to listen.
 * @return The socket after setting.
 */
int ServerSocket::setListen(int numOfListens, int serverSocket) {
    // Set the socket to listen to only 5 client in a row.
    if (listen(serverSocket, numOfListens) < 0) {
        // If the set didn't work, rise an error.
        perror("Error listening to a socket.");
    }
}

/**
 * Creating a new socket.
 * @return An int representing a socket.
 */
int ServerSocket::makeNewSocket() {
    // Creat a new socket.
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    // If the creation didn't work, raise an error.
    if (serverSocket < 0) {
        perror("Error binding socket.");
    }
    return serverSocket;
}

/**
 * Given a server's socket (an int), running it.
 * @param serverSocket The int of the server's socket.
 */
void ServerSocket::runServer(int serverSocket) {
    while (true) {
        // Create a struct for an incoming client.
        struct sockaddr_in client_sin{};
        // Set the size of the
        unsigned int addr_len = sizeof(client_sin);
        // Accept a new client.
        int clientSocket = accept(serverSocket, (struct sockaddr *) &client_sin, &addr_len);
        // Check if the operation succeeded.
        if (clientSocket < 0) {
            // If it didn't work, rise an error.
            perror("Error accepting client.");
        }
        // Initiate a buffer and it's size.
        char buffer[4096];
        // Set the data that the server can accept from a connection to the buffer's size.
        int expected_data_len = sizeof(buffer);
        // Receive data from the current client.
        long readBytes = recv(clientSocket, buffer, expected_data_len, 0);
        // Check if the "receive" method worked.
        if (readBytes < 0) {
            // If it didn't work, raise an error.
            perror("Error receiving data.");
        }
            // Check for an empty message.
        else if (readBytes == 0) {
            // CLOSE >> ?
        }
        // Receive the data from the client.
        string clientInfo(buffer);
        // Checking if the user wants to close the connection.
        if (endConnectionCheck(clientInfo)) {
            close(clientSocket);
            continue;
        }

        // Check for closer of the socket.
        // Function witch process HERE!!!!

        // Send the processed data back to the client.
        long sent_bytes = send(clientSocket, buffer, readBytes, 0);
        // Check if the sending didn't work.
        if (sent_bytes < 0) {
            // If the sending didn't work, raise an error.
            perror("Error sending data to client.");
        }
    }
}

bool ServerSocket::endConnectionCheck(const string &strToCheck) {
    if (strToCheck)
}









