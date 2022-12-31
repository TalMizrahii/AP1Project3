
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
    string userInputFlow();

protected:
    // Getting the user input.
    vector<string> userInput();

    // Recover the original user string input.
    string recoverOriginalUserInput(vector<string> userVec1);
};

#endif //EX3_USERVECTORINPUT_H
