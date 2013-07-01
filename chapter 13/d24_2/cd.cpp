#include "cd.h"
Cd::Cd(char * s1, char * s2, int n, double x) {
    performers = new char [std::strlen(s1)+1];
    std::strcpy(performers,s1);
    label = new char [std::strlen(s2)+1];
    std::strcpy(label,s2);
    selections = n;
    playtime = x;
}

Cd::Cd() {
    performers = NULL;
    label = NULL;
    selections = 0;
    playtime = 0;
}

Cd::Cd(const Cd & d) {
    performers = new char [std::strlen(d.performers)+1];
    std::strcpy(performers,d.performers);
    label = new char [std::strlen(d.label)+1];
    std::strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd & Cd::operator=(const Cd & d) {
    if (this == &d)
        return *this;
    delete [] performers;
    delete [] label;
    performers = new char [std::strlen(d.performers)+1];
    std::strcpy(performers,d.performers);
    label = new char [std::strlen(d.label)+1];
    std::strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

void Cd::Report() const {
    std::cout << "\nPerformer: " << performers;
    std::cout << "\nLabel: " << label;
    std::cout << "\nSelections: " << selections;
    std::cout << "\nPlaytime: " << playtime << std::endl;
}

Cd::~Cd() {
    delete [] performers;
    delete [] label;
}