#include "Chebyshev.h"

/**
 * Calculating the Chebyshev distance between two vectors.
 * @param v1 the first vector.
 * @param v2 the second vector.
 * @return the Chebyshev distance between the two vectors.
 */
double Chebyshev::calculateDistance(vector<double> v1, vector<double> v2) {
    // Setting the maximum to the first couple of points.
    double max = fabs(v1[0] - v2[0]);
    double temp;
    // Iterating over the indexes in each vector.
    for (unsigned long i = 1; i < v1.size(); i++) {
        // Setting the temp to be the value of distance between v1[i] to v2[i].
        temp = fabs(v1[i] - v2[i]);
        // If temp is bigger than max, max is now temp.
        if (temp > max)
            max = temp;
    }
    // Return the maximum value.
    return max;
}
