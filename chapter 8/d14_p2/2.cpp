/*
The CandyBar structure contains three members.
The first member holds the brand name of a candy bar.
The second member holds the weight (which may have a fractional part) of the candy bar,
and the third member holds the number of calories (an integer value) in the candy bar.

Write a program that uses a function that takes as arguments a reference to CandyBar, a pointer-to-char, a double, and an int
and uses the last three values to set the corresponding members of the structure.

The last three arguments should have default values of "Millennium Munch", 2.85, and 350.
Also the program should use a function that takes a reference to a CandyBaras an argument and displays the contents of the structure.

Use const where appropriate.
*/
#include <iostream>
#include <string>
using namespace std;

struct CandyBar {
    char * name;
    double weight;
    int calories;
};

void set_candy (CandyBar & candy, char * name = "Millennium Munch", const double weight = 2.85, const int calories = 350);
void show_candy (const CandyBar & candy);


int main () {
    CandyBar my_candy;
    set_candy(my_candy);
    show_candy(my_candy);

    system("pause");
}

void set_candy (CandyBar & candy, char * name, const double weight, const int calories) {
    cout << "Candy setup...\n";
    candy.name = name;
    candy.weight = weight;
    candy.calories = calories;
    cout << "Done!\n";
}

void show_candy (const CandyBar & candy) {
    cout << "\nCandy: " << candy.name;
    cout << "\nweight: " << candy.weight;
    cout << "\ncalories: " << candy.calories << endl;

}