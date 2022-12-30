
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
        // Creating the relative vector.
        RelativeVector *dataVec = creatRelativeVector(strVec);
        // Set the new relative vector in the vector of relative vectors.
        fileVec.push_back(dataVec);
    }
    myFile.close();
    // Return the vector of relative vectors.
    return fileVec;
}

/**
 * Creating a new relative vector on the heap and
 * setting it the classification and values vector from a string vector.
 * @param strVec A vector of strings, representing the cells in the file vector.
 * @return A new relative vector containing the data from the string vector.
 */
RelativeVector *FileReader::creatRelativeVector(vector<string> strVec) {
    // Get the classification.
    string classification  = strVec.back();
    // Remove the classification from strVec, reminding only the numbers of the vector.
    strVec.pop_back();
    // Check the classification for last \r.
    classification = serverValidations.isLastSpace(classification);
    // Create a new relative vector named dataVec.
    auto *dataVec = new RelativeVector;
    // Set the classification to the dataVec.
    dataVec->setClassification(classification);
    // Convert the string vector to a doubles vector.
    vector<double> numVec = sTodVec(strVec);
    dataVec->setValuesVector(numVec);
    return dataVec;
}

/**
 * A method who catch each cell in the line of a cvs file
 * and returns a vector of strings, representing the cells in the file vector.
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

/**
 * Converting a vector of strings to a vector of doubles.
 * @param strVec The vector of strings.
 * @return The vector of doubles.
 */
vector<double> FileReader::sTodVec(vector<string> strVec) {
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
