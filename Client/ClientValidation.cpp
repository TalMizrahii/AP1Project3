#include "ClientValidation.h"


/**
 * Checking if a string is a valid unsigned int.
 * @param str to check if can convert to int.
 * @return true id can be convert, false otherwise.
 */
bool ClientValidation::validUnsignedInt(const std::string &strNum) {
    // Check if the string is empty or not a number in the first position.
    if (strNum.empty() || (!isdigit(strNum[0]))) {
        return false;
    }
    // Checking if the string is convertable to int.
    char *p;
    strtol(strNum.c_str(), &p, 10);
    // If the string is not convertable, return false.
    if (*p != 0) {
        return false;
    }
    // If the string is convertable, return true.
    return true;
}


/**
 * Checking if the number is in scientific notation.
 * If so, convert it to the numeric value of it represented as a string. If not, return it as it came.
 * @param str The string to check.
 * @return the string changed or not.
 */
bool ClientValidation::validD(const string &str) {
    // Saving the string in a temporary value.
    string temp = str;
    // Creating a control pointer.
    char *end = nullptr;
    // If the string is not convertable, return false.
    if (end == str.c_str() || *end != '\0') {
        return false;
    }
    // If the string is convertable, return true.
    return true;
}


/**
 * Checkinf if the distance the user specified is valid.
 * @param distanceSpec The user's request.
 * @return True if distance valid, false otherwise.
 */
bool ClientValidation::validDistance(const string &distanceSpec) {
    // Check if the string is a valid distance.
    if (distanceSpec == "AUC" || distanceSpec == "MAN" || distanceSpec == "CHB" || distanceSpec == "CAN"
        || distanceSpec == "MIN") {
        return true;
    }
    // If no valid option was chosen, false.
    return false;
}


/**
 * Checking if the k_elements received as argument to the program is in valid format.
 * @param string k_elements (received as argument to the program).
 * @return False id k_elements invalid, true otherwise.
 */
bool ClientValidation::validKElements(const string &k_elements) {
    if (!validUnsignedInt(k_elements)) {
        return false;
    }
    int k = stoi(k_elements);
    if (k < 0) {
        return false;
    }
    return true;
}

/**
 * Checking if the ip received as argument to the program is in valid format.
 * @param string ip address (received as argument to the program).
 * @return False if the ip address invalid, true otherwise.
 */
bool ClientValidation::validIp(const string &ip) {
    // Create a new stream to go over the line.
    istringstream ip_line(ip);
    // Initiate a string to store the data from toNum.
    string ip_cell;
    // Read each data segment seperated by comma.
    while (getline(ip_line, ip_cell, '.')) {
        // Checking if the number is valid in ipv4 format.
        if (!validCellIpv4(ip_cell)) {
            return false;
        }
    }
    return true;
}

/**
 * Checking if the ip cell is in valid format.
 * @param string ip cell.
 * @return False if the ip cell invalid, true otherwise.
 */
bool ClientValidation::validCellIpv4(const string &cell) {
    // Getting the cell length.
    unsigned long cell_length = cell.length();
    // Cell length is at most 3.
    if (cell_length > 3) {
        return false;
    }
    // Checking if the cell composed of numbers.
    for (int i = 0; i < cell_length; i++) {
        if (!isdigit(cell[i])) {
            return false;
        }
    }
    // From string to int.
    int cell_num = stoi(cell);
    // Checking if the cell_num is in the valid range.
    if (cell_num < 0 || cell_num > 255) {
        return false;
    }
    return true;
}


/**
 * Checking if the port number is in valid format.
 * @param string port number.
 * @return False if the port number invalid, true otherwise.
 */
bool ClientValidation::validPortNumber(const string &port) {
    if (validUnsignedInt(port)) {
        // From string to int.
        int port_num = stoi(port);
        // Checking if the port is in the valid range.
        if (port_num < 1024 || port_num > 65535) {
            return false;
        }
        return true;
    }
    return false;
}

/**
 * Checking if the user input is in valid format.
 * @param user input.
 * @return False if the user input invalid, true otherwise.
 */
bool ClientValidation::checkingUserInput(vector<string> userVecCheck) {
    // Checking if the user didn't entered anything.
    if (userVecCheck.empty()) {
        return false;
    }
    // Checking if the user entered only -1 to close the connection.
    if (userVecCheck.size() == 1 && userVecCheck.back() == "-1") {
        return true;
    }
    // Getting the k that the user entered.
    string kElement = userVecCheck.back();
    // Pop the k that the user entered.
    userVecCheck.pop_back();
    // Getting the distance formula that the user entered.
    string distanceFormula = userVecCheck.back();
    // Pop the distance formula that the user entered.
    userVecCheck.pop_back();
    // Checking if the k, distance formula and double vec are valid.
    if (!validKElements(kElement)
        || !validDistance(distanceFormula)
        || !checkVecDouble(userVecCheck)) {
        return false;
    }
    return true;
}

/**
 * Checking if the user double input is in valid format.
 * @param user double input.
 * @return False if the user input invalid, true otherwise.
 */
bool ClientValidation::checkVecDouble(vector<string> vector) {
    // Getting the vector size
    unsigned long userVecLength = vector.size();
    // Checking each cell if valid.
    for (int i = 0; i < userVecLength; i++) {
        if (!validD(vector[i])) {
            return false;
        }
    }
    return true;
}