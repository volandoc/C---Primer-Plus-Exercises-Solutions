#include "cd.h"
Cd::Cd(char * s1, char * s2, int n, double x) {
    std::strncpy(performers,s1,49);
    performers[49] = '\0';
    std::strncpy(label,s2,19);
    label[19] = '\0';
    selections = n;
    playtime = x;
}
Cd::Cd() {
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0;
}
void Cd::Report() const {
    std::cout << "\nPerformer: " << performers;
    std::cout << "\nLabel: " << label;
    std::cout << "\nSelections: " << selections;
    std::cout << "\nPlaytime: " << playtime << std::endl;
}