#include "Canberra.h"

/**
 * Calculating the Canberra distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Canberra distance between the two vectors.
 */
double Canberra::calculateDistance(vector<double> v1, vector<double> v2) {
    // Setting the result to 0.
    double result = 0;
    // Iterating over the indexes in each vector.
    for (unsigned long i = 0; i < v1.size(); i++) {
        // Avoiding division by 0.
        if (v1[i] == 0 && v2[i] == 0) {
            continue;
        }
        // Calculating the subtraction between them in absolute value, dividing by each index in absolut value,
        // and adding to result.
        result += fabs(v1[i] - v2[i]) / (fabs(v1[i]) + fabs(v2[i]));
    }
    // Returning the result.
    return result;
}
