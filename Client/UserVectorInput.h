//
// Created by yuval on 12/30/22.
//

#ifndef EX3_USERVECTORINPUT_H
#define EX3_USERVECTORINPUT_H
#include <cstdlib>
#include <vector>
#include <string>
#include "ClientValidation.h"

using namespace std;


class UserVectorInput {
public:
    // The default constructor of the class.
    explicit UserVectorInput();



    // The Destructor of the class.
    ~UserVectorInput();

    // The function control all the flow of getting user input check it and make it ready to send.
    void userInputFlow();

protected:
    // Getting the user input.
    vector<string> userInput();

};





























#endif //EX3_USERVECTORINPUT_H
