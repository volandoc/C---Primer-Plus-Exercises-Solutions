#include <iostream>
#include "header.h"

Person::Person(const std::string & ln, const char * fn) {
    lname = ln;
    strcpy(fname, fn);
    std::cout << "\nUsing constructor with parameters.\nInitialisation done.\n";
}

void Person::Show() const {
    std::cout << "\nMethod Show(): " << this->fname << " " << this->lname << std::endl;
} // first name last name format
void Person::FormalShow() const {
    std::cout << "\nMethod FormalShow(): " << this->lname << " " << this->fname << std::endl;
}// last name, first name format