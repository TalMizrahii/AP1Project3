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
#include "DataProcessing.h"

using namespace std;

/**
 * A class to read from a file, process the data and return a vector of the data processed.
 */
class FileReader : public DataProcessing {
public:
    // A constructor.
    FileReader();

    // A destructor.
    ~FileReader();

    // A reading file method.
    vector<RelativeVector *> readFile(string &path);


    // Creating a relative vector from the strVec.
    RelativeVector *creatRelativeVector(vector<string> strVec);

};

#endif //EX3_FILEREADER_H
