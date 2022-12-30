//
// Created by yuval on 12/30/22.
//

#ifndef EX3_CLIENTVALIDATION_H
#define EX3_CLIENTVALIDATION_H



#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>


using namespace std;


/**
 * A validation class for vectors.
 */
class ClientValidation {
public:
    // Checking if a string (representing a number) is a real number.
    bool isNumber(string s);

    // Checking if a number is in scientific notation.
    bool validD(const basic_string<char>& str);

    bool validIp(const string &ip);

    bool validPortNumber(const string &port);

    bool validUnsignedInt(const std::string &s);


protected:
    // Checking if the number is a valid floating point number.
    bool validFloatingNumber(string string1, unsigned long &i);

    // Checking if a number is a valid negative number.
    bool validNegative(string string1, unsigned long &i);

    // Checking if a string distance is a valid distance specifier.
    bool validDistance(const string &distanceSpec);

    // Checking if k_elements is a valid number.
    bool validKElements(const string &k_elements);

    bool validCellIpv4(const string &cell);


};

#endif //EX3_CLIENTVALIDATION_H