#ifndef EX3_CHEBYSHEV_H
#define EX3_CHEBYSHEV_H

#include "AbstractDistance.h"

/**
 * A distance calculation class using Chebyshev algorithm.
 */
class Chebyshev : public AbstractDistance {
public:
    // Calculates the Chebyshev distance.
    double calculateDistance(vector<double> v1, vector<double> v2) override;

};

#endif //EX3_CHEBYSHEV_H
