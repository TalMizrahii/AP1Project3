#include "Taxicab.h"

/**
 * Calculating the Taxicab Geometry distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Taxicab Geometry distance between the two vectors.
 */
double Taxicab::calculateDistance(vector<double> v1, vector<double> v2) {
    // Setting the result to 0.
    double result = 0;
    // Iterating over the indexes in each vector.
    for (unsigned long i = 0; i < v1.size(); i++) {
        // Calculating the subtraction between them in absolute value, raising to the power of 2 and adding to result.
        result += fabs(v1[i] - v2[i]);
    }
    // Returning the result to the power of p^-1.
    return result;
}
