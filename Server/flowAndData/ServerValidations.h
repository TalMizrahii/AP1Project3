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

class ServerValidations{
public:
    // Check if a file is on the server using given path.
    void validPath(const string& path);
    // Checking if the last char is space or not.
    string isLastSpace(string classification);
};


#endif //EX3_SERVERVALIDATIONS_H
