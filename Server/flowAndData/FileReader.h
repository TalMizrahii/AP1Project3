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

    // Creating a vector of strings, representing the cells in the file vector.
    vector<string> catchDelim(const string &fullVector);

private:
    ServerValidations serverValidations;
};

#endif //EX3_FILEREADER_H
