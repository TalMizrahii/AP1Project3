#ifndef EX3_KNNALGORITHM_H
#define EX3_KNNALGORITHM_H



#include <cstdlib>
#include <vector>
#include <string>
#include "RelativeVector.h"
#include "../Distances/AbstractDistance.h"
#include <bits/stdc++.h>
#include <utility>
#include <map>
#include <cmath>

using namespace std;

/**
 * Given a vector, finding the k nearest neighbors to it.
 */
class KnnAlgorithm {
public:
    // The constructor of the class.
    explicit KnnAlgorithm(vector<RelativeVector *> cataloged_vectors, vector<double> user_vector,
                          unsigned long k_neighbors, AbstractDistance *calculation);

    // Setter for catalogedVectors.
    void setCataloged_vectors(vector<RelativeVector *> cataloged_vectors);

    // Setter for userVector.
    void setUserVector(vector<double> user_vector);

    // Setter for Calc.
    void seCalc(AbstractDistance *calculation1);

    // Setter for kNeighbors.
    void setKNeighbors(unsigned long k_neighbors);

    // Calculate the distances between the userVector to all cataloged vectors(classified vectors).
    bool calculateDistances();

    // Getter for kNeighbors.
    unsigned long getKNeighbors() const;

    // Getter for userVector.
    vector<double> getUserVector();

    // Getter for catalogedVectors.
    vector<RelativeVector *> getCatalogedVectors();

    // Getter for calc.
    AbstractDistance *getCalc();

    // Check validation of the vectors.
    bool sizeComparison(const vector<double> &v1, const vector<double> &v2);

    // Extracting the largest classification from the map.
    string extractClassification(const map<string, int> &kMap);

    // Sorting the vector by distances.
    vector<RelativeVector *> sortingAndGettingK();

    // Creating a map from the data vector.
    map<string, int> createMap(vector<RelativeVector *> knn);

    // The Destructor of the class.
    ~KnnAlgorithm();

    // A control flow method for the class.
    string classificationUserVec();

    // Delete all data of the catalog vector.
    void destroyKnn();

private:
    // The calculation for the distance.
    AbstractDistance *calc;
    // The user input vector.
    vector<double> userVector;
    // The classified vectors.
    vector<RelativeVector *> catalogedVectors;
    // The k neighbors we got as argument to the program.
    unsigned long kNeighbors;
};


#endif //EX3_KNNALGORITHM_H
