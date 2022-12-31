
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
    int clientSocket = makeNewSocket();
    struct sockaddr_in sin = creatAddrInStruct();
    if (connect(clientSocket, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
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
    }
    return true;
}

/**
 * Recieved the data from the server.
 * @param clientSocket The client's socket.
 * @return The server reply.
 */
string ClientSocket::receiveData(int clientSocket) {
    // Declaration of the buffer and the serverReply.
    string serverReply;
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
    if (readBytes == 0) {
        close(clientSocket);
        return "The server closed the connection";
    }
    // concatenating the server reply to a string.
    for (int i = 0; i < readBytes; i++) {
        serverReply += buffer[i];
    }
    return serverReply;
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
        // Getting the server reply.
        string serverReply = receiveData(clientSocket);
        // Print the server reply.
        cout << serverReply << endl;
    }
}





