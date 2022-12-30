//
// Created by yuval on 12/30/22.
//

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
 * The function check if the input has negative sign that the user enters is in a valid format.
 *
 * @param string1 the user input string.
 * @param i the for loop counter.
 * @return return false if isn't valid and true if valid
 * (we get the loop counter by reference because if valid we want to continue).
 */
bool ClientValidation::validNegative(string string1, unsigned long &i) {
    // If the sign is not valid by format, reject.
    if (i == string1.length() - 1
        || (string1[i] == '-'
            && string1[i - 1] != ' ')) {
        return false;
    }
    // Want to get ahead in the for loop.
    i++;
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
 * The function check if the input has '.' sign that the user enters is in a valid format(floating point format).
 *
 * @param string1 the user input string.
 * @param i the for loop counter.
 * @return return false if isn't valid and true if valid
 * (we get the loop counter by reference because if valid we want to continue).
 */
bool ClientValidation::validFloatingNumber(string string1, unsigned long &i) {
    // Getting the string length.
    unsigned long string1_length = string1.length();
    // If we have '.' we must get a number in the next char, otherwise not in format,
    // And checking if not accessing out of scoping our array.
    if ((i == string1_length - 1)
        || (isdigit(string1[i + 1]) == false
            || isdigit(string1[i - 1]) == false)) {
        return false;
    }
    // Checking if there are any chars in the floating point string that is not a digit.
    for (unsigned long j = i + 1; j < string1_length; j++) {
        // If we have space we the format is valid.
        if (string1[j] == ' ') {
            break;
            // If after the point there any char that is not a digit return false (not a valid floating format).
        } else if (isdigit(string1[j]) == false) {
            return false;
        }
    }
    // Want to get ahead in the for loop.
    i++;
    return true;
}

/**
 * Checking if the user input is in the right format.
 * @param s a string that the user entered.
 * @return boolean, True if the the string in the right format False otherwise.
 */
bool ClientValidation::isNumber(string s) {
    // Getting the string length.
    unsigned long s_length = s.length();
    unsigned long i = 0;
    // Check if the first or last char in the input is ' ' and if the first char is '-'.
    if ((isdigit(s[i]) == false && s[i] != '-')
        || isdigit(s[s.length() - 1]) == false) {
        return false;
    }
    // Check each char of the user input.
    for (i = 1; i < s_length; i++) {
        // Checking if the user input has 2 spaces neighbors.
        if ((s[i] == ' ' && s[i - 1] == ' ')) {
            return false;
        }
        // Checking if there is a space , if we have only 1 space, the format is still correct.
        if (s[i] == ' ') {
            continue;
        }
        // Checking if the user input a valid floating point number.
        if (s[i] == '.' && !validFloatingNumber(s, i)) {
            return false;
        }
        // Checking if the chars are in valid negative format
        if (s[i] == '-' && !validNegative(s, i)) {
            return false;
        }
        // Checking if the char is a digit.
        if (isdigit(s[i]) == false) {
            return false;
        }
    }
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



