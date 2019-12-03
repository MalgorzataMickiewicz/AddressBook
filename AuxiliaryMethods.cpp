#include <iostream>
#include <sstream>

#include "AuxiliaryMethods.h"

using namespace std;

string AuxiliaryMethods::conversionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

