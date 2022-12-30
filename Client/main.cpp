#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "flowAndData/Validations.h"
#include "flowAndData/FileReader.h"
# include "Distances/Minkowski.h"
# include "Distances/Euclidean.h"
# include "Distances/Taxicab.h"
# include "Distances/Canberra.h"
# include "Distances/Chebyshev.h"
#include "flowAndData/KnnAlgorithm.h"

using namespace std;


/**
 * Extracting arguments from the system args to be the K (for the knn algorithm), the path to the file (the database)
 * and the metric calculation.
 * @param argcArray The sysargs array.
 * @return A vector of those arguments.
 */
vector<string> extract_argc(char *argcArray[]) {
    // As we know the argc[0] is the program name, and by the format argc[1] is the k neighbors.
    string neighbors = argcArray[1];
    // As we know the argc[0] is the program name, and by the format argc[2] is the file/path.
    string path = argcArray[2];
    // As we know the argc[0] is the program name, and by the format argc[3] is the distance_algorithm.
    string distance_algorithm = argcArray[3];
    // Checking if the k neighbors is legal.
    for (char neighbor: neighbors) {
        if (!isdigit(neighbor) || neighbors[0] == '0') {
            cout << "Illegal Format." << endl;
            exit(0);
        }
    }
    // Creating a string vector and return it.
    vector<string> vector;
    vector.push_back(neighbors);
    vector.push_back(path);
    vector.push_back(distance_algorithm);
    return vector;
}


/**
 * Creating a vector from user's input and checking if its valid.
 * @return Return a valid vector by the specified format of the task.
 */
vector<double> insert_To_Vector() {
    string input;
    double number;
    vector<double> vector;
    // Create a Validation instance.
    Validations validate;
    // Using a stream function to get a string from the user.
    getline(cin, input);
    if (input.empty()){
        cout << "Illegal format- Empty input, try again." << endl;
        exception e;
        throw e;
    }
    // Checking validation for scientific notation.
    input = validate.isScientificNotationValid(input);
    // Send the string to be checked for validation.
    if (!validate.isNumber(input)) {
        cout << "Illegal format - Try again." << endl;
        exception e;
        throw e;
    }
    // Creating a vector from the user input string.
    istringstream vectorStream(input);
    while (vectorStream >> number) {
        vector.push_back(number);
    }
    return vector;
}


/**
 * returning the distance object (on the heap) as the user specified.
 * @param distanceSpec The user's request.
 * @return The instance of the distance.
 */
AbstractDistance *distanceCreator(const string &distanceSpec) {
    // Return the Euclidean distance.
    if (distanceSpec == "AUC") {
        auto *euc = new Euclidean();
        return euc;
    }
    // Return the Taxicab distance.
    if (distanceSpec == "MAN") {
        auto *man = new Taxicab();
        return man;
    }
    // Return the Chebyshev distance.
    if (distanceSpec == "CHB") {
        auto *chb = new Chebyshev();
        return chb;
    }
    // Return the Canberra distance.
    if (distanceSpec == "CAN") {
        auto *can = new Canberra();
        return can;
    }
    // Return the Minkowski distance.
    if (distanceSpec == "MIN") {
        auto *min = new Minkowski();
        return min;
    }
    // If no valid option was chosen, exit.
    cout << "Illegal Format" << endl;
    exit(-1);
}


/**
 * Checking if the k received as argument to the program is in valid format.
 * @param string k (received as argument to the program).
 */
void validK(const string &k) {
    // Checking if k is starting with 0.
    if (k[0] == '0') {
        cout << "Illegal format" << endl;
        exit(-1);
    }
    // Checking each char in the string if its in legal format.
    for (char i: k) {
        if (!isdigit(i)) {
            cout << "Illegal format" << endl;
            exit(-1);
        }
    }
}


/**
 * This is the main function of the program, creating 2 vectors and checking validation.
 * @return return 0 if the program run without issues.
 */
int main(int args, char *argv[]) {
    vector<string> argc_vector = extract_argc(argv);
    // Checking if the k argument is in valid format.
    validK(argc_vector[0]);
    unsigned long kNeighbors = stoi(argc_vector[0]);
    string path = argc_vector[1];
    string distance_algorithm = argc_vector[2];

    AbstractDistance *disCalc = distanceCreator(distance_algorithm);
    FileReader fileReader;
    vector<RelativeVector *> catalogedVec = fileReader.readFile(path);

    while (true) {
        vector<double> vector1;
        // Creating one vector from the user's inputs.
        try {
            vector1 = insert_To_Vector();
            KnnAlgorithm kElement(catalogedVec, vector1, kNeighbors, disCalc);
            cout << kElement.classificationUserVec() << endl;
        }
        catch (exception &e) {
            continue;
        }
    }

    return 0;
}
