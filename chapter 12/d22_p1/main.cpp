/*
Consider the following class declaration:
class Cow {
    char name[20];
    char * hobby;
    double weight;
public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow c&);
    ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow() const; // display all cow data
};

Provide the implementation for this class and write a short program that uses all the member functions.
*/
#include "cow.h"

int main() {
    using namespace std;

    Cow name1("Big Fat Cow","Eating grass",300.5);
    Cow name2;
    Cow name3 = name1; // copy constructor is used

    name1.ShowCow();
    name2.ShowCow();
    name3.ShowCow();

    Cow name4("Small Cow","running around",150);
    name2 = name4; // assignment
    name2.ShowCow();

    Cow name5("Average Cow","sleeping",200);

    name1 = name2 = name3 = name4 = name5;

    name1.ShowCow();
    name2.ShowCow();
    name3.ShowCow();

    system("pause");
    return 0;
}