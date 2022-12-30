
#include "FileReader.h"

/**
 * A default constructor.
 */
FileReader::FileReader() = default;

/**
 * A default destructor.
 */
FileReader::~FileReader() = default;



/**
 * Reading a csv file line by line and returning a vector of RelativeVectors contain all info about the file's lines.
 * @param path The path to the file.
 * @return A vector of RelativeVectors contain all info about the file's lines.
 */
vector<RelativeVector *> FileReader::readFile(string &path) {
    // Create an instance of a ServerValidations to use in the method.
    ServerValidations serverValidations;
    // Validate if the path exist.
    serverValidations.validPath(path);
    // Create a new stream to read from the file.
    fstream myFile;
    myFile.open(path);
    // Declaring a vector of vectors.
    vector<RelativeVector *> fileVec;
    // While the file is still ok to read:
    while (myFile.good()) {
        // Create a String to read a full line from the file.
        string fullVector;
        // Get the line from the file and put it in the fullVector.
        getline(myFile, fullVector);
        // Check if we detected an empty line and ignore it.
        if(fullVector.empty()){
            continue;
        }

    }
}
