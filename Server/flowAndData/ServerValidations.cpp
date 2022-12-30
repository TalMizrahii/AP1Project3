#include "ServerValidations.h"


/**
 * Checking if a file exist on the computer.
 * @param path The path to the file.
 */
void ServerValidations::validPath(const string& path) {
    // Create a new stream to read from the file.
    fstream myFile;
    myFile.open(path);
    if (!myFile) {
        std::cout << "NO FILE" << endl;
        exit(-1); // Exit the program.
    }
    myFile.close();
}
