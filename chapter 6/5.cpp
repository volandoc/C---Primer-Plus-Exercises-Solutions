/*
The Kingdom of Neutronia, where the unit of currency is the tvarps, has the following income tax code:
    First 5,000 tvarps:    0% tax
    Next 10,000 tvarps:10% tax
    Next 20,000 tvarps:15% tax
    Tvarps after 35,000:20% tax

    For example,someone earning 38,000 tvarps would owe 5,000 * 0.00 + 10,000 * 0.10 + 20,000 * 0.15 + 3,000 * 0.20, or 4,600 tvarps.

    Write a program that uses a loop to solicit incomes and to report tax owed. The loop should terminate when the user enters a negative number or non-numeric input.
*/

#include <iostream>

int main() {
    using namespace std;

    int input;
    cout << "The Kingdom of Neutronia welcomes you, stranger.\n";
    cout << "Enter your destiny: ";

    /*

    I invent a formula for this:
    If           x > 35000 then taxes = x * 0.2 - 3000
    If 35000 > x > 15000 then taxes = x * 0.15 - 1250
    If 15000 > x > 5000     then taxes = x * 0.1 - 500
    If 5000     > x         then taxes = 0

    */

    while ( (cin >> input) && (input >= 0) ) {
        if ( input > 35000)
            cout << "Your tax is: " << input * 0.2 - 3000 << " tvarps." << endl;
        else if ( input > 15000)
            cout << "Your tax is: " << input * 0.15 - 1250 << " tvarps." << endl;
        else if ( input > 5000 )
            cout << "Your tax is: " << input * 0.1 - 500 << " tvarps." << endl;
        else cout << "Your tax is: 0 tvarps.  Lucky you!" << endl;
        cout << "\nEnter your destiny: ";
    }

    cout << "\nProgram terminated.\n";
    system("pause");
    return 0;
}
