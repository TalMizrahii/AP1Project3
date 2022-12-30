#include "Minkowski.h"

/**
 * Calculating the distance using minkowskiDistance function.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Minkowski distance between the two vectors.
 */
double Minkowski::calculateDistance(vector<double> v1, vector<double> v2) {
    return minkowskiDistance(v1, v2, 2);
}

/**
 * Calculating the Minkowski distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @param p the constant value in the algorithm.
 * @return the Minkowski distance between the two vectors.
 */
double Minkowski::minkowskiDistance(vector<double> v1, vector<double> v2, double p) {
    // Setting the result to 0.
    double result = 0;
    // Iterating over the indexes in each vector.
    for (unsigned long i = 0; i < v1.size(); i++) {
        // Calculating the subtraction between them in absolute value, raising to the power of 2 and adding to result.
        result += pow(fabs(v1[i] - v2[i]), p);
    }
    // Returning the result to the power of p^-1.
    return pow(result, 1.0 / p);
}
