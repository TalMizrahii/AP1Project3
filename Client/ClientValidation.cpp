//
// Created by yuval on 12/30/22.
//

#include "ClientValidation.h"


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
string ClientValidation::isScientificNotation(const string &str) {
    // Saving the string in a temporary value.
    string temp = str;
    // Creating a control pointer.
    char *end;
    // trying to convert the string.
    double result = strtod(str.c_str(), &end);
    // If the string is not convertable, return the original string.
    if (end == str.c_str() || *end != '\0') {
        return temp;
    }
    // If the string is convertable, return the converted version.
    string strResult = to_string(result);
    return strResult;
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
 * Checking a full string for scientific notation.
 * @param str The string to check.
 * @return The string repaired.
 */
string ClientValidation::isScientificNotationValid(const string str) {
    // Create a new stream to go over the line.
    istringstream line(str);
    // Initiate a string to store the data from toNum.
    string lastStr, result;
    // Read each data segment seperated by comma.
    while (getline(line, lastStr, ' ')) {
        // Checking if the number is in scientific notation.
        result += isScientificNotation(lastStr) + " ";
    }
    result.pop_back();
    return result;
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
 * @return False id k_elements invalid, true otherwise
 */
bool ClientValidation::validKElements(const string &k_elements) {
    // Checking if k_elements is starting with 0.
    if (k_elements[0] == '0') {
        return false;
    }
    // Checking each char in the string if its in legal format.
    for (char i: k_elements) {
        if (!isdigit(i)) {
            return false;
        }
    }
    return true;
}

bool ClientValidation::validIp(const string &ip) {
    // Create a new stream to go over the line.
    istringstream ip_line(ip);
    // Initiate a string to store the data from toNum.
    string ip_cell;
    // Read each data segment seperated by comma.
    while (getline(ip_line, ip_cell, '.')) {
        // Checking if the number is valid in ipv4 format.
        if (!validCellIpv4(ip_cell)){
            return false;
        }
    }
    return true;
}

bool ClientValidation::validCellIpv4(const string &cell) {
    unsigned long cell_length = cell.length();
    if (cell_length > 3){
        return false;
    }
    for (int i = 0; i < cell_length; i++) {
        if (!isdigit(cell[i])){
            return false;
        }
    }
    int cell_num = stoi(cell);
    if (cell_num < 0 || cell_num > 255){
        return false;
    }
    return true;
}



