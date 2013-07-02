/*
Do Exercise 1 from Chapter 9 but replace the code shown there with an appropriate golf class declaration. Replace set golf(golf &, const char*, int) with a constructor with the appropriate argument for providing initial values. Retain the interactive version of setgolf() but implement it by using the constructor. (For example, for the code for setgolf(), obtain the data, pass the data to the constructor to create a temporary object, and assign the temporary object to the invoking object, which is *this.)
*/
#include "header.h"
using namespace std;
int main() {
    Golf my_golf;                            // new golf definition with default arguments
    my_golf.showgolf();                        // must show error
    Golf my_golf2("John Doe", 35);            // another golf user
    my_golf2.showgolf();                    // must show data

    Golf my_golf3("Jane Doe");                // golf user with one argument
    my_golf3.showgolf();                    // must show data with 0 handicap

    my_golf3.setgolf();                        // setting new name and handicap
    my_golf3.showgolf();

    cout << "Setting new handicap for your user...\n";
    my_golf3.set_handicap(20);

    system("pause");
}