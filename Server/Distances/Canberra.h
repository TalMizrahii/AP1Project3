#ifndef EX3_CANBERRA_H
#define EX3_CANBERRA_H

#include "AbstractDistance.h"

/**
 * A distance calculation class using Canberra algorithm.
 */
class Canberra : public AbstractDistance {
public:
    // Calculates the Taxicab distance.
    double calculateDistance(vector<double> v1, vector<double> v2) override;

};

#endif //EX3_CANBERRA_H
