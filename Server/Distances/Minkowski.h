#ifndef EX3_MINKOWSKI_H
#define EX3_MINKOWSKI_H

#include "AbstractDistance.h"

/**
 * A distance calculation class using Minkowski algorithm.
 */
class Minkowski : public AbstractDistance {
public:
    // Calculates the Euclidean distance.
    double calculateDistance(vector<double> v1, vector<double> v2) override;

    // Calculates the minkowski distance.
    double minkowskiDistance(vector<double> v1, vector<double> v2, double p);

};

#endif //EX3_MINKOWSKI_H
