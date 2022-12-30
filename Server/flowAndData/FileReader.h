#ifndef EX3_FILEREADER_H
#define EX3_FILEREADER_H

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
 * A class to read from a file, process the data and return a vector of the data processed.
 */
class FileReader {
public:
    // A constructor.
    FileReader();

    // A destructor.
    ~FileReader();

    // A reading file method.
    vector<RelativeVector *> readFile(string &path);



    // A validation for a dot method.
    string isDot(string fullVector);

    // Catching the specification of the vector.
    RelativeVector *catchDelim(const string &toNum);

    // Checking if the last char is space or not.
    string isLastSpace(string classification);

};

#endif //EX3_FILEREADER_H
