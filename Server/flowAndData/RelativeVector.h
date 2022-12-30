
#ifndef EX3_RELATIVEVECTOR_H
#define EX3_RELATIVEVECTOR_H

#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

/**
 * A class representing a vector by name and values.
 */
class RelativeVector {

public:
    // A constructor receiving a vector of doubles.
    explicit RelativeVector(vector<double> initValuesVector);

    // A constructor.
    RelativeVector();

    // A destructor.
    ~RelativeVector();

    // A setter.
    void setValuesVector(vector<double> newValuesVector);

    // A setter.
    void setClassification(string newClassification);

    // A setter.
    void setDistanceFromRelativeVec(double newDistanceFromRelativeVec);

    // A getter.
    vector<double> getValuesVector();

    // A getter.
    string getClassification();

    // A getter.
    double getDistanceFromRelativeVec();


private:
    // The vector of doubles.
    vector<double> valuesVector;
    // The classification of the vector.
    string classification;
    // The distance from the main vector calculated by KNN class.
    double distanceFromRelativeVec{};
};

#endif //EX3_RELATIVEVECTOR_H
