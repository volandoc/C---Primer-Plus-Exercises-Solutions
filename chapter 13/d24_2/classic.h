#ifndef CLASSIC2_H_
#define CLASSIC2_H_
#include <iostream>
#include "cd.h"

class Classic : public Cd
{
private:
    char * primarywork;
public:
    Classic(char * pr, char * s1, char * s2, int n, double x);
    Classic();
    Classic(const Classic & d);
    ~Classic() { delete [] primarywork; };
    void Report() const;
    Classic & operator=(const Classic & d);
};

#endif