/*
Rewrite the Stonewt class (Listings 11.16 and 11.17) so that it overloads all six relational operators. The operators should compare the pounds members and return a type bool value.

Write a program that declares an array of six Stonewt objects and initializes the first three objects in the array declaration.

Then it should use a loop to read in values used to set the remaining three array elements.
Then it should report the smallest element, the largest element, and how many elements are greater or equal to 11 stone.
(The simplest approach is to create a Stonewt object initialized to 11 stone and to compare the other objects with that object.)
*/

// stone.cpp -- user-defined conversions
// compile with stonewt.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt & st, int n);
int main() {
    Stonewt incognito = 275; // uses constructor to initialize
    Stonewt wolfe(285.7);    // same as Stonewt wolfe = 285.7;
    Stonewt taft(21, 8);

    double temp = .0;
    Stonewt stonewt_arr[6];
    stonewt_arr[0] = .25;
    stonewt_arr[1] = 11;
    stonewt_arr[2] = 12;
    for (int i = 0; i < 3 ; i++) {
        cout << "Enter stone # " << i+4 << " (q to quit): ";
        std::cin >> temp;
        stonewt_arr[i+3] = temp;
    }

    Stonewt smallest, largest;
    Stonewt ideal(11);
    int greater = 0;
    int equal = 0;

    for (int i = 0; i < 6 ; i++) {
        if (i == 0) {                       // smallest and largest stonewall initializing with first array element
            smallest = stonewt_arr[i];
            largest = stonewt_arr[i];
        }
        if (smallest > stonewt_arr[i]) {    // check if the smallest greater than i element
            smallest = stonewt_arr[i];
        }

        if (largest < stonewt_arr[i]) {    // check if the largest smaller than i element
            largest = stonewt_arr[i];
        }

        if (stonewt_arr[i] > ideal) {
            greater ++;
        } else if (stonewt_arr[i] == ideal) {
            equal ++;
        }
    }

    std::cout << "Smallest element: ";
    smallest.show_lbs();
    std::cout << "Largest element: ";
    largest.show_lbs();
    std::cout << "Greater than 11 pounds: " << greater << "\nEqual to 11 pounds: " << equal << std::endl;

    std::cin.get();
    std::cin.get();
    system("pause");
    return 0;
}