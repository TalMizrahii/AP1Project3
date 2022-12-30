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

/**
 * Checking if a last char is '\r'. if so, we remove it.
 * @param classification The string to check.
 * @return the string after the change.
 */
string ServerValidations::isLastSpace(string classification) {
    // Check if the last char is equal to '\r'.
    if (classification.back() == '\r') {
        // If so, remove it.
        classification.pop_back();
    }
    // Return the string with or without the change.
    return classification;
}
