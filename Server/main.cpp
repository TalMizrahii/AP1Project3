#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "flowAndData/FileReader.h"
# include "Distances/Minkowski.h"
# include "Distances/Euclidean.h"
# include "Distances/Taxicab.h"
# include "Distances/Canberra.h"
# include "Distances/Chebyshev.h"
#include "flowAndData/KnnAlgorithm.h"

using namespace std;

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
 * This is the main function of the program, creating 2 vectors and checking validation.
 * @return return 0 if the program run without issues.
 */
int main(int args, char *argv[]) {

    // ############################################################################
    // Create the socket and bind the port.
    // Get the info from the client's socket.
    // Process the Data to vector, metric, and K num.
    // ############################################################################

    // Creat a validation instance for the server's validation.
    ServerValidations serverValidations;
    // Set the path from the arguments.
    string path = argv[1];

    string test = argv[2];
    // Check if port and path are valid. if not, return.
    if(!serverValidations.validPortNumber(argv[2]) || !serverValidations.validPath(path)){
        cout << "Port or path are not valid" << endl;
        return 0;
    }
    int port = stoi(argv[2]);

    // ALL BELOW I GET FROM THE SOCKET, DELETE!!!!
    string distance_algorithm = "MAN";
    vector<double> vector1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int kNeighbors = 5;
    // #############################################################################

    AbstractDistance *disCalc = distanceCreator(distance_algorithm);
    FileReader fileReader;
    vector<RelativeVector *> catalogedVec = fileReader.readFile(path);
    KnnAlgorithm kElement(catalogedVec, vector1, kNeighbors, disCalc);
    cout << kElement.classificationUserVec() << endl;

    return 0;
}
