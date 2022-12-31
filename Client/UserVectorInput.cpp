//
// Created by yuval on 12/30/22.
//

#include "UserVectorInput.h"
#include "sstream"


/**
 * A default constructor.
 */
UserVectorInput::UserVectorInput() = default;


/**
 * A default destructor.
 */
UserVectorInput::~UserVectorInput() = default;


/**
 * returning the user input.
 * @return userInputStringVec the user input.
 */
vector<string> UserVectorInput::userInput() {
    string input;
    vector<string> userInputStringVec;
    // Getting the user input without ' '.
    while (getline(cin, input, ' ')) {
        userInputStringVec.push_back(input);
    }
    return userInputStringVec;
}

/**
 * Creating the user input as string vector checking it and make it ready to send.
 */
void UserVectorInput::userInputFlow() {
    ClientValidation validation;
    // Creating a vec from the user input using userInput function.
    vector<string> userVec = userInput();
    // Checking if the user enterd valid formats.
    while (!validation.checkingUserInput(userVec)) {
        cout << "invalid input" << endl;
        userVec = userInput();
    }



}
