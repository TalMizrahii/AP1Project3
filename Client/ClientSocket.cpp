
#include "ClientSocket.h"

#include <utility>


/**
 * A default destructor.
 */
ClientSocket::~ClientSocket() = default;

/**
 * A constructor for the Client's socket.
 * @param ipAddress The ip number of the server to connect.
 * @param portNumber The port number of the server to connect.
 */
ClientSocket::ClientSocket(string ipAddress, int portNumber) {
    setIp(std::move(ipAddress));
    setPort(portNumber);
}

/**
 * A setter for the ip of the server to connect.
 * @param ipAddress The ip number of the server.
 */
void ClientSocket::setIp(string ipAddress) {
    this->ip = std::move(ipAddress);
}

/**
 * A setter for the server's number.
 * @param portNumber The server's port number.
 */
void ClientSocket::setPort(int portNumber) {
    this->port = portNumber;
}

/**
 * A getter for the server's ip address.
 * @return The ip of the server.
 */
string ClientSocket::getIp() {
    return this->ip;
}

/**
 * A getter for the server's port number.
 * @return The server's port number.
 */
int ClientSocket::getPort() {
    return this->port;
}

/**
 * The central method of the class. Responsible to create the client's socket.
 * @return The client's socket.
 */
int ClientSocket::creatClientSocket() {
    // Create a new socket.
    int clientSocket = makeNewSocket();
    // Creating a struct address for the socket.
    struct sockaddr_in sin = creatAddrInStruct();
    // Connecting to the server.
    if (connect(clientSocket, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        exit(0);
    }
    return clientSocket;
}

/**
 * Creating a new socket.
 * @return An int representing a socket.
 */
int ClientSocket::makeNewSocket() {
    // Creat a new socket.
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    // If the creation didn't work, raise an error.
    if (clientSocket < 0) {
        perror("Error binding socket.");
        exit(0);
    }
    return clientSocket;
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


/**
 * Send the user request to the server.
 * @param clientSocket The client's socket.
 */
bool ClientSocket::sendToServer(int sock) {
    // Getting the user request.
    string message = this->userVectorInput.userInputFlow();
    // Checking if the user want to close the connection.
    if (message == "-1") {
        return false;
    }
    // Making the buffer ready.
    const char *char_message = message.c_str();
    // Checking the buffer size.
    int data_len = strlen(char_message);
    // Sending the data to the server.
    int sentBytes = send(sock, char_message, data_len, 0);
    // Checking if it sent correctly.
    if (sentBytes < 0) {
        perror("error sending the message to the server");
        exit(0);
    }
    return true;
}

/**
 * Received the data from the server.
 * @param clientSocket The client's socket.
 * @return The server reply.
 */
long ClientSocket::receiveData(int clientSocket, char *buffer, int expectedDataLen) {
    // Receive data from the current client.
    long readBytes = recv(clientSocket, buffer, expectedDataLen, 0);
    // Check if the "receive" method worked.
    if (readBytes < 0) {
        // If it didn't work, raise an error.
        perror("Error receiving data.");
        exit(0);
    }
    return readBytes;
}

/**
 * Control the flow of sending and receiving data from the client.
 */
void ClientSocket::runClient() {
    // Create a new socket.
    int clientSocket = creatClientSocket();
    // We want to send a data to the server until the user want to close ot until the server close from his side.
    while (true) {
        bool flag = sendToServer(clientSocket);
        // Checking if the user want to close the socket.
        if (!flag) {
            cout << "The client request to close the connection to the server!" << endl;
            close(clientSocket);
            exit(0);
        }

        // Creating a new clear buffer.
        char buffer[4096];
        for (char &i: buffer) {
            i = 0;
        }
        // Set the data that the server can accept from a connection to the buffer's size.
        int expectedDataLen = sizeof(buffer);
        // Getting the server reply.
        long numOfBytes = receiveData(clientSocket, buffer, expectedDataLen);
        // Check if the number of bytes is 0.
        if (!numOfBytes) {
            // If it is, close the socket.
            close(clientSocket);
            return;
        }
        // Declaration of the buffer and the serverReply.
        string serverReply = creatString(buffer, numOfBytes);
        // Print the server reply.
        cout << serverReply << endl;
    }
}

/**
 * Concatenating a char* to a string.
 * @param buffer The char*
 * @param readBytes The length of the char*.
 * @return the string representing the char*.
 */
string ClientSocket::creatString(char *buffer, long readBytes) {
    string serverReply;
    // concatenating the server reply to a string.
    for (int i = 0; i < readBytes; i++) {
        serverReply += buffer[i];
    }
    return serverReply;
}
