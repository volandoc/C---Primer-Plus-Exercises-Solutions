/*
This exercise is the same as Programming Exercise 2, except that the exceptions should
be derived from a base class (itself derived from logic_error) that stores the two argument
values, the exceptions should have a method that reports these values as well as
the function name, and a single catch block that catches the base-class exemption
should be used for both exceptions, with either exception causing the loop to terminate.
*/

#include "excpt.h"

// function prototypes
double hmean(double a, double b) throw(abc_bad);
double gmean(double a, double b) throw(abc_bad);

int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    double x, y, z;
    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        try { // start of try block
            z = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                 << " is " << gmean(x,y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block

        catch (abc_bad & abc) {
            abc.mesg();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }

    system("pause");
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b) throw(abc_bad) {
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(abc_bad) {
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}