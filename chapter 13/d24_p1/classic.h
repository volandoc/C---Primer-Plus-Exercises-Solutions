#include <iostream>

#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd {
private:
    char primarywork[60];
public:
    Classic(char * pr, char * s1, char * s2, int n, double x);
    Classic();
    ~Classic() {};
    void Report() const;
};

#endif