
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
        // Send the line to be processed, and receive back a new relative vector who represent the line.
        vector<string> strVec = catchDelim(fullVector);
        string classification  = strVec.back();
        strVec.pop_back();
        classification = serverValidations.isLastSpace(classification);
        // Set the new relative vector in the vector of relative vectors.
        fileVec.push_back(dataVec);
    }
    myFile.close();
    // Return the vector of relative vectors.
    return fileVec;
}

/**
 * A method who catch each cell in the line of a cvs file
 * and returns a RelativeVector represent the data about the line.
 * @param fullVector the line from the file as a string.
 * @return A vector of strings, representing the cells in the file vector.
 */
vector<string> FileReader::catchDelim(const string &fullVector) {
    // Create a new stream to go over the line.
    istringstream line(fullVector);
    // Initiate a string to store the data from the vector.
    string fromDelim;
    // Create a vector of strings, representing the cells in the file vector.
    vector<string> strVec;
    // Go over the string from the file and separate its values to a new vector.
    while (getline(line, fromDelim, ',')) {
        strVec.push_back(fromDelim);
    }
    return strVec;
}