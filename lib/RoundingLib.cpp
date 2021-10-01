#define LIB_EXPORT
#include "RoundingLib.h"
#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>

std::string Rounding(int numerator, int denominator, unsigned int roundTo)
{
    if(denominator == 0) {
        return "Can't divide by zero";
    }
    std::ostringstream ss;
    ss << std::setprecision(roundTo) << std::fixed << (double)numerator/denominator;
    return ss.str();
}