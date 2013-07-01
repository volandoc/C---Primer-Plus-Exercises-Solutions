#include "classic.h"
Classic::Classic(char * pr, char * s1, char * s2, int n, double x) : Cd(s1,s2,n,x) {
    primarywork = new char [std::strlen(pr)+1];
    std::strcpy(primarywork,pr);
}

Classic::Classic() : Cd() {
    primarywork = NULL;
}

Classic::Classic(const Classic & d) : Cd(d) {
    primarywork = new char [std::strlen(d.primarywork)+1];
    std::strcpy(primarywork,d.primarywork);
}

Classic & Classic::operator =(const Classic & d) {
    if (this == &d)
        return *this;
    Cd::operator=(d);
    delete [] primarywork;
    primarywork = new char [std::strlen(d.primarywork)+1];
    std::strcpy(primarywork,d.primarywork);
    return *this;
}

void Classic::Report() const {
    std::cout << "\nPrimary Work: " << primarywork;
    Cd::Report();
}