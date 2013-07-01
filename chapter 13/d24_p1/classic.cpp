#include "classic.h"
Classic::Classic(char * pr, char * s1, char * s2, int n, double x) : Cd(s1,s2,n,x) {
    strncpy_s(primarywork,pr,59);
    primarywork[59] = '\0';
}
Classic::Classic() : Cd() {
    primarywork[0] = '\0';
}
void Classic::Report() const {
    std::cout << "\nPrimary Work: " << primarywork;
    Cd::Report();
}