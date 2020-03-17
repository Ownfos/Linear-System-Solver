#ifndef UTILITY_H
#define UTILITY_H

#include <cmath>

namespace ownfos
{
    // Check if a value is small enough to consider as 0
    bool IsZero(double value)
    {
        return std::fabs(value) < 0.000001;
    }
}

#endif