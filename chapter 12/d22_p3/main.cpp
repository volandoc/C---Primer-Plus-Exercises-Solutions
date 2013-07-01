/*
Rewrite the Stock class, as described in Listings 10.7and 10.8 in Chapter 10 so that it uses dynamically allocated memory directly instead of using string class objects to hold the stock names.
Also replace the show() member function with an overloaded operator<<()definition. Test the new definition program in Listing 10.9.
*/

#include "stock2.h"
const int STKS = 4;
int main() {
    using std::cout;
    using std::ios_base;
    // create an array of initialized objects
    Stock stocks[STKS] = {  // copy constructor
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    cout.precision(2); // #.## format
    cout.setf(ios_base::fixed, ios_base::floatfield);// #.## format
    cout.setf(ios_base::showpoint); // #.## format
    cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
        cout << stocks[st];
    Stock top = stocks[0]; // copy constructor
    for (st = 1; st < STKS; st++)
        top = top.topval(stocks[st]); // assignment constructor
    cout << "\nMost valuable holding:\n";
    cout << top;

    system("pause");
    return 0;
}