/*
Modify Listing 15.11 so that the two exception types are classes derived from the
    logic_error class provided by the header file. Have each what() method
    report the function name and the nature of the problem. The exception objects need not
    hold the bad values; they should just support the what() method.
*/

#include "exc_mean.h"

// function prototypes
double hmean(double a, double b) throw(bad_hmean); // each function gets personal exception type
double gmean(double a, double b) throw(bad_gmean);

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
        catch (bad_hmean & bg) { // start of catch block
            cout << bg.what();
            cout << "Try again.\n";
            continue;
        } catch (bad_gmean & hg) {
            cout << hg.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }

    cout << "Bye!\n";
    system("pause");
    return 0;
}

double hmean(double a, double b) throw(bad_hmean) { // each function gets personal exception type, ie bad_Hmean
    if (a == -b)
        throw bad_hmean(); // if invalid arguments throw the exception
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(bad_gmean) { // bad_Gmean exception
    if (a < 0 || b < 0)
        throw bad_gmean(); // if invalid arguments throw the exception
    return std::sqrt(a * b);
}