#include "cow.h"

Cow::Cow() {
    name[0] = '\0';
    hobby = NULL;
    weight = 0;
}

Cow::Cow (const char * nm, const char * ho, double wt) {
    strcpy(name,nm);
    hobby = new char [strlen(ho)+1];
    strcpy(hobby,ho);
    weight = wt;
}

Cow::Cow (const Cow & c) {
    strcpy(name,c.name);
    hobby = new char [strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight = c.weight;
}

Cow::~Cow() {
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c) {
    if (this == &c) // object assigned to itself
        return *this;
    delete [] hobby;
    strcpy(name,c.name);
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const {
    std::cout << "\nName: " << name;
    if (hobby == NULL)
        std::cout << "\nHobby:  [empty - please initialize]";
    else
        std::cout << "\nHobby: " << hobby;
    std::cout << "\nWeight: " << weight << std::endl;
}