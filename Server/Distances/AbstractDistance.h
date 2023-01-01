#ifndef EX3_ABSTRACTDISTANCE_H
#define EX3_ABSTRACTDISTANCE_H

#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>


/**
 * This class calculate the distance between two vectors using different distance algorithms.
 */
using namespace std;

class AbstractDistance {

public:
    // A pure virtual method for the distances.
    virtual double calculateDistance(vector<double> v1, vector<double> v2) = 0;

    // A default destructor.
    virtual ~AbstractDistance();
};

#endif //EX3_ABSTRACTDISTANCE_H
