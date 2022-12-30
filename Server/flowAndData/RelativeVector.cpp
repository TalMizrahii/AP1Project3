#include "RelativeVector.h"

/**
 * A constructor for the class receiving a vector of doubles.
 * @param initValuesVector The values vector.
 */
RelativeVector::RelativeVector(vector<double> initValuesVector) {
    setValuesVector(std::move(initValuesVector));
}

/**
 * A default destructor.
 */
RelativeVector::~RelativeVector() = default;

/**
 * A setter for the values vector.
 * @param newValuesVector The values vector.
 */
void RelativeVector::setValuesVector(vector<double> newValuesVector) {
    this->valuesVector = std::move(newValuesVector);
}

/**
 * A setter for the classification of the vector.
 * @param newClassification A string representing the classification of the vector.
 */
void RelativeVector::setClassification(string newClassification) {
    this->classification = std::move(newClassification);
}

/**
 * A setter for the distance from the main vector.
 * @param newDistanceFromRelativeVec The distance from the main vector.
 */
void RelativeVector::setDistanceFromRelativeVec(double newDistanceFromRelativeVec) {
    this->distanceFromRelativeVec = newDistanceFromRelativeVec;
}

/**
 * A getter for the values vector.
 * @return The values vector.
 */
vector<double> RelativeVector::getValuesVector() {
    return this->valuesVector;
}

/**
 * A getter for the classification of the vector.
 * @return A string of the classification of the vector.
 */
string RelativeVector::getClassification() {
    return this->classification;
}

/**
 * A getter for the distance from the main vector.
 * @return a double representing the distance from the main vector.
 */
double RelativeVector::getDistanceFromRelativeVec() {
    return this->distanceFromRelativeVec;
}

/**
 * A default destructor.
 */
RelativeVector::RelativeVector() = default;
