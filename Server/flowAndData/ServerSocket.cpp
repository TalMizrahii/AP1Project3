#include "ServerSocket.h"
#include "FileReader.h"
#include "KnnAlgorithm.h"


/**
 * A default destructor.
 */
ServerSocket::~ServerSocket() = default;

/**
 * A default Constructor setting default values to the port and path.
 */
ServerSocket::ServerSocket() : DataProcessing() {
    setPort(12345);
    setPath("/home/tal/Desktop/AP1/ex3/datasets/iris/iris_classified.csv");
}

/**
 * A constructor receiving a port number to bind to the socket and a path to the database file.
 * @param port A port number to bind to the socket.
 * @param path A path to a file database.
 */
ServerSocket::ServerSocket(int port, string path) : DataProcessing() {
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
    serverSocket = setListen(5, serverSocket);
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
    return serverSocket;
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
    // Run forever.
    while (true) {
        // Accept a new client.
        int clientSocket = acceptClient(serverSocket);
        // A while loop to get endless requests from a client as long as the message he sends isn't -1.
        while (true) {
            // Creat a buffer to receive data from the client.
            char buffer[4096];
            // Get the size of the buffer.
            long expectedDataLen = sizeof(buffer);
            // Receive data from the client's socket.
            long readBytes = receiveData(clientSocket, buffer, expectedDataLen);
            // Check for an empty message or if the user wants to close the connection.
            if (readBytes == 0 || endConnectionCheck(buffer)) {
                // If he does, close his socket and accept another client.
                close(clientSocket);
                break;
            }
            string reply = processRequest(buffer);
            replyToClient(reply, clientSocket);
        }
    }
}

/**
 * Sending data to a given socket of a client.
 * @param reply The data to send.
 * @param clientSocket The client's socket to send to.
 */
void ServerSocket::replyToClient(string reply, int clientSocket) {
    unsigned long lenMsg = reply.size();
    const char *buffer = reply.c_str();
    int sent_bytes = send(clientSocket, buffer, lenMsg, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}


/**
 * Check if the user wants to close the socket by sending the message "-1".
 * @param strToCheck The message to check.
 * @return A boolean value to the question.
 */
bool ServerSocket::endConnectionCheck(const string &strToCheck) {
    return (strToCheck == "-1");
}

/**
 * Given a client socket, accept it's data on a TCP connection.
 * @param clientSocket The client's socket.
 * @param buffer The buffer to store the reply.
 * @return The number of bytes received in the buffer.
 */
long ServerSocket::receiveData(int clientSocket, char *buffer, long expectedDataLen) {
    // Receive data from the current client.
    long readBytes = recv(clientSocket, buffer, expectedDataLen, 0);
    // Check if the "receive" method worked.
    if (readBytes < 0) {
        // If it didn't work, raise an error.
        perror("Error receiving data.");
    }
    return readBytes;
}

/**
 * Accept a new client.
 * @param serverSocket The server's socket.
 * @return a socket of a new  client.
 */
int ServerSocket::acceptClient(int serverSocket) {
    // Create a struct for an incoming client.
    struct sockaddr_in client_sin{};
    // Set the size of the struct.
    unsigned int addr_len = sizeof(client_sin);
    // Accept a new client.
    int clientSocket = accept(serverSocket, (struct sockaddr *) &client_sin, &addr_len);
    // Check if the operation succeeded.
    if (clientSocket < 0) {
        // If it didn't work, rise an error.
        perror("Error accepting client.");
    }
    return clientSocket;
}

/**
 * Processing the client's request and calculating the knn classification from the file database.
 * @param buffer The full request from the client.
 * @return if passed all validation, replies the classification of the vector. Otherwise, replies "invalid input".
 */
string ServerSocket::processRequest(const string &buffer) {
    // Processing the given string to vector.
    vector<string> strVec = catchDelim(buffer, ' ');
    // Extract the k element as a string.
    string kElementStr = strVec.back();
    // remove it from the vector.
    strVec.pop_back();
    // Extract the metric from the vector.
    string metric = strVec.back();
    // remove it from the vector.
    strVec.pop_back();
    if (!serverValidations.validI(kElementStr) || !serverValidations.validMetric(metric)) {
        return "invalid input";
    }
    // convert the kElement to int.
    int kNum = stoi(kElementStr);
    // Creat a calculation metric.
    AbstractDistance *disCalc = distanceCreator(metric);
    // Convert the vector of strings to a vector of doubles.
    vector<double> valuesVector = sTodVec(strVec);
    // Get the path and set it to a temp variable.
    string path = getPath();
    // Create a fileReader.
    FileReader fileReader;
    // Read the file and receive the data as a Relative vector.
    vector<RelativeVector *> catalogedVec = fileReader.readFile(path);
    // Calculate the distance.
    KnnAlgorithm kElement(catalogedVec, valuesVector, kNum, disCalc);
    // Return the result.
    return kElement.classificationUserVec();
}

/**
 * returning the distance object (on the heap) as the user specified.
 * @param distanceSpec The user's request.
 * @return The instance of the distance.
 */
AbstractDistance *ServerSocket::distanceCreator(const string &distanceSpec) {
    // Return the Euclidean distance.
    if (distanceSpec == "AUC") {
        auto *euc = new Euclidean();
        return euc;
    }
    // Return the Taxicab distance.
    if (distanceSpec == "MAN") {
        auto *man = new Taxicab();
        return man;
    }
    // Return the Chebyshev distance.
    if (distanceSpec == "CHB") {
        auto *chb = new Chebyshev();
        return chb;
    }
    // Return the Canberra distance.
    if (distanceSpec == "CAN") {
        auto *can = new Canberra();
        return can;
    }
        // Return the Minkowski distance.
    else if (distanceSpec == "MIN") {
        auto *min = new Minkowski();
        return min;
    }
}


