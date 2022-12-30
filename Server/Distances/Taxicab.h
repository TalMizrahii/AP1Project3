#ifndef EX3_TAXICAB_H
#define EX3_TAXICAB_H

#include "AbstractDistance.h"

/**
 * A distance calculation class using Taxicab algorithm.
 */
class Taxicab : public AbstractDistance {
public:
    // Calculates the Taxicab distance.
    double calculateDistance(vector<double> v1, vector<double> v2) override;

};

#endif //EX3_TAXICAB_H
