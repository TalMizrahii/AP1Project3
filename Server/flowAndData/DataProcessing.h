#ifndef EX3_DATAPROCESSING_H
#define EX3_DATAPROCESSING_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "RelativeVector.h"
#include "ServerValidations.h"

using namespace std;

/**
 * A code sharing class to process data and strings.
 */
class DataProcessing {
public:

    // Creating a vector of strings, representing the cells in the file vector.
    vector<string> catchDelim(const string &fullVector, char delim);

    // Convert a vector of strings to a vector of doubles.
    vector<double> sTodVec(vector<string> strVec);

protected:
    // A server validation instance to use when processing the file.
    ServerValidations serverValidations;
};

#endif //EX3_DATAPROCESSING_H
