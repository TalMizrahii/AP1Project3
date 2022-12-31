#include "DataProcessing.h"

/**
 * A method witch convert a string to a vector of string, separating by a given token.
 * @param fullVector The string to separate.
 * @param delim The token.
 * @return The vector witch represent the string. separated.
 */
vector<string> DataProcessing::catchDelim(const string &fullVector, char delim) {
    // Create a new stream to go over the line.
    istringstream line(fullVector);
    // Initiate a string to store the data from the vector.
    string fromDelim;
    // Create a vector of strings, representing the cells in the file vector.
    vector<string> strVec;
    // Go over the string from the file and separate its values to a new vector.
    while (getline(line, fromDelim, delim)) {
        strVec.push_back(fromDelim);
    }
    return strVec;
}

/**
 * Converting a vector of strings to a vector of doubles.
 * @param strVec The vector of strings.
 * @return The vector of doubles.
 */
vector<double> DataProcessing::sTodVec(vector<string> strVec) {
    // The new vector of doubles.
    vector<double> numVec;
    // Save the size of strVec.
    unsigned int iter = strVec.size();
    // Go over all the string representing a double in this vector.
    for (int i = 0; i < iter; ++i) {
        // Set the current string in strToD.
        string strToD = strVec[i];
        // Check it in isDot for validation.
        strToD = serverValidations.isDot(strToD);
        // If the string is valid to conversion, convert.
        if(serverValidations.validD(strToD)){
            // Put the number in the double's vector.
            numVec.push_back(stod(strToD));
        }
    }
    return numVec;
}
