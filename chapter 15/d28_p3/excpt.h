#include <iostream>
#include <stdexcept>
#include <cmath> // or math.h, unix users may need -lm flag

#ifndef EXCPT_H
#define EXCPT_H

class abc_bad : public std::logic_error {
protected:
    double v1;
    double v2;
public:
    abc_bad(const char * s ="not defined yet", double a = 0, double b = 0) : std::logic_error(s), v1(a), v2(b) {}
    virtual void mesg() const = 0;
    virtual ~abc_bad() {}
};

class bad_hmean : public abc_bad {
public:
    bad_hmean(double a, double b) : abc_bad("\ninvalid arguments: a = -b\n", a, b) {}
    void mesg() const;
};

inline void bad_hmean::mesg() const {
    std::cout << "hmean(" << v1 << ", " << v2 <<"): ";
    std::cout << what();
}

class bad_gmean : public abc_bad {
public:
    bad_gmean(double a = 0, double b = 0) : abc_bad("\ngmean() arguments should be >= 0\n", a, b) {}
    void mesg() const;
};

inline void bad_gmean::mesg() const {
    std::cout << "Values used: " << v1 << ", " << v2;
    std::cout << what();
}

#endif