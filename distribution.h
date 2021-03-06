#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>

#include "constants.h"

class Distribution
{
protected:

public:
    Distribution();

    std::vector<double> ideal_distribution(const size_t N);
    std::vector<double> robust_distribution(const size_t N);

    ~Distribution();
};

#endif // DISTRIBUTION_H
