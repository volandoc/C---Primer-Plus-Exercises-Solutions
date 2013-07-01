#include <iostream>
#include <stdexcept>
#include <cmath> // or math.h, unix users may need -lm flag

#ifndef EXC_MEAN_H
#define EXC_MEAN_H

class bad_hmean : public std::logic_error {
public:
    bad_hmean() : std::logic_error("hmean() invalid arguments: a = -b\n") {} // string to be displayed for what() method
};

class bad_gmean : public std::logic_error {
public:
    bad_gmean() : std::logic_error("gmean()  arguments should be >= 0\n") {} // string to be displayed for what() method
};

#endif