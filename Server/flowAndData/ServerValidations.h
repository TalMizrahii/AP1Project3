//
// Created by tal on 12/30/22.
//

#ifndef EX3_SERVERVALIDATIONS_H
#define EX3_SERVERVALIDATIONS_H

#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;
/**
 * A validation class for the server.
 */
class ServerValidations{
public:
    // Check if a file is on the server using given path.
    bool validPath(const string& path);
    // Checking if the last char is space or not.
    string isLastSpace(string classification);

    // A validation for a dot method.
    string isDot(string toNum);

    // Checking if the string is a valid double number.
    bool validD(const string& strToD);

    // Checking if a sting is a number.
    bool validI(const std::string &s);

    // Check if a strung is a valid port or not.
    bool validPortNumber(const string &port);
};


#endif //EX3_SERVERVALIDATIONS_H
