/*
Rewrite the Stonewt class (Listings 11.16 and 11.17)
so that it has a state member that governs whether the object is interpreted in stone form,
integer pounds form, or floating-point pounds form. Overload the
<<operator to replace the show_stn() and show_lbs() methods.

Overload the addition, subtraction, and multiplication operators so that one can add, subtract, and multiply Stonewt values.

Test your class with a short program that uses all the class methods and friends.
*/

// stone.cpp -- user-defined conversions
// compile with stonewt.cpp
#include "stonewt.h"
void display(const Stonewt & st, int n);
int main() {
    Stonewt incognito = 310; // uses constructor to initialize
    Stonewt wolfe(150.23);    // same as Stonewt wolfe = 285.7;
    Stonewt taft(21, 8);

    cout << "The celebrity weighed ";
    incognito.setMode(Stonewt::STONE);
    cout << incognito;
    cout << "\nThe detective weighed ";
    wolfe.setMode(Stonewt::STONE);
    cout << wolfe;
    cout << "\nThe detective weighed ";
    wolfe.setMode(Stonewt::I_POUNDS);
    cout << wolfe;
    cout << "\nThe President weighed ";
    taft.setMode(Stonewt::F_POUNDS);
    cout << taft;

    Stonewt test = wolfe + incognito;
    cout << "Testing + : " << test;
    test = incognito - taft;
    cout << "Testing - : "<< test;
    test = incognito * 2;
    cout << "Testing * : "<< test << endl;

    cout << "No stone left unearned\n";
    std::cin.get();
    return 0;
}
