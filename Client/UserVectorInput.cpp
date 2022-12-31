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
string UserVectorInput::userInputFlow() {
    ClientValidation validation;
    // Creating a vec from the user input using userInput function.
    vector<string> userVec = userInput();
    // Checking if the user enterd valid formats.
    while (!validation.checkingUserInput(userVec)) {
        cout << "invalid input" << endl;
        userVec = userInput();
    }
    // Recover the user input.
    string originalUserInput = recoverOriginalUserInput(userVec);
    return originalUserInput;
}
/**
 * Recover the original user input.
 * @param userVec1 vector of string.
 */
string UserVectorInput:: recoverOriginalUserInput(vector<string> userVec1){
    // Getting the vec size.
    unsigned long userVecLength = userVec1.size();
    string originalInput;
    // Concatenating the userVec to recover the original string input.
    for (int i = 0; i < userVecLength ; i++) {
        originalInput += userVec1[i] + " ";
    }
    // The last char is " " so we pop it.
    originalInput.pop_back();
    return  originalInput;
}
