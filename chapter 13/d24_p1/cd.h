#include <iostream>

#ifndef CD_H_
#define CD_H_

// base class
class Cd { // represents a CD disk
private:
    char performers[50];
    char label[20];
    int selections; // number of selections
    double playtime; // playing time in minutes
public:
    Cd(char * s1, char * s2, int n, double x);
    // Cd(const Cd & d); removed, there are no pointers or dynamic allocation
    Cd();
    virtual ~Cd() {} ;
    virtual void Report() const; // reports all CD data
    // Cd & operator=(const Cd & d); removed, not needed
};

#endif