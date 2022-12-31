#include <string>
#include <iostream>
#include "flowAndData/FileReader.h"
#include "flowAndData/KnnAlgorithm.h"
#include "flowAndData/ServerSocket.h"

using namespace std;

/**
 * This is the main function of the program, creating 2 vectors and checking validation.
 * @return return 0 if the program run without issues.
 */
int main(int args, char *argv[]) {
    // Creat a validation instance for the server's validation.
    ServerValidations serverValidations;
    // Set the path from the arguments.
    string path = argv[1];
    // Check if port and path are valid. if not, return.
    if(!serverValidations.validPortNumber(argv[2]) || !serverValidations.validPath(path)){
        cout << "Port or path are not valid" << endl;
        return 0;
    }
    // Convert the port to an int.
    int port = stoi(argv[2]);
    // Creat a new server socket.
    ServerSocket serverSocket(port, path);
    // Creat a new socket number.
    int socketNum = serverSocket.creatServerSocket();
    // Run the server.
    serverSocket.runServer(socketNum);
    return 0;
}
