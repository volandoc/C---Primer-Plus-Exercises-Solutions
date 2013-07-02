/*
Redo Listing 7.15 without using the array class.

Do two versions:
a. Use an ordinary array of const char * for the strings representing the season names,
and use an ordinary array of double for the expenses.

b. Use an ordinary array of const char * for the strings representing the season names,
and use a structure whose sole member is an ordinary array of double for the expenses.
(This design is similar to the basic design of the array class.)
*/

//version a
#include <iostream>
#include <array>
#include <string>
using namespace std;
const int Seasons = 4;
const char * snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

void fill(double []);
void show(const double []);
int main() {
    double expenses[4];

    fill(expenses);
    show(expenses);


    cin.get();
    cin.get();
    return 0;
}

void fill(double pa[]) {
    for (int i = 0; i < Seasons; i++) {
        cout << "Enter " << snames[i] << " expenses: ";
        cin >> pa[i];
    }
}

void show(const double da[]) {
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++) {
        cout << snames[i] << ": $" << da[i] << '\n';
        total += da[i];
    }
    cout << "Total: $" << total << '\n';
}