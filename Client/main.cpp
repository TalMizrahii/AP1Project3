#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "ClientValidation.h"

using namespace std;


/**
 * Extracting arguments from the system args to be the K (for the knn algorithm), the path to the file (the database)
 * and the metric calculation.
 * @param argcArray The sysargs array.
 * @return A vector of those arguments.
 */
vector<string> extract_argc(char *argcArray[]) {
    ClientValidation v;
    // As we know the argc[0] is the program name, and by the format argc[1] is the ip address.
    string ip_address = argcArray[1];
    // Checking if the ip address  legal.
    if (!v.validIp(ip_address)){
        cout << "Illegal ip." << endl;
        exit(0);
    }
    // As we know the argc[0] is the program name, and by the format argc[2] is the port.
    string port = argcArray[2];


    vector<string> vector;
    vector.push_back(path);
    vector.push_back(distance_algorithm);
    return vector;
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
