#include "ServerValidations.h"


/**
 * Checking if a file exist on the computer.
 * @param path The path to the file.
 */
void ServerValidations::validPath(const string& path) {
    // Create a new stream to read from the file.
    fstream myFile;
    // Try to open the file.
    myFile.open(path);
    // If the file wouldn't open, print an error message and return.
    if (!myFile) {
        std::cout << "NO FILE" << endl;
        exit(-1); // Exit the program.
    }
    // If the file opened, close it.
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

/**
 * A method given a number (as a string) checks the need to concatenate 0 to it.
 * @param toNum the number as a string.
 * @return the number concatenated or not.
 */
string ServerValidations::isDot(string toNum) {
    // Check if the first char is a dot.
    if (toNum[0] == '.')
        // If so, concatenate 0 to the number.
        return '0' + toNum;
    // Otherwise just return the number.
    return toNum;
}

/**
 * Checking if a given string is a valid double.
 * If so, return true. Otherwise, return false.
 * @param str The string to check.
 * @return a boolean true if its a valid double, false otherwise.
 */
bool ServerValidations::validD(const string& strNumber) {
    // Saving the string in a temporary value.
    const string& temp = strNumber;
    // Creating a control pointer.
    char *end = nullptr;
    // trying to convert the string.
    strtod(temp.c_str(), &end);
    // If the string is not convertable, return the original string.
    if (end == temp.c_str() || *end != '\0') {
        return false;
    }
    return true;
}
