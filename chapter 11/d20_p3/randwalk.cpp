/*
Modify Listing 11.15 so that instead of reporting the results of a single trial for a particular target/step combination, it reports the highest, lowest, and average number of steps for N trials, where N is an integer entered by the user.
*/

// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <fstream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include <iomanip>
#include "vect.h"

const int MAX_RAND = 360;

int main() {
    using namespace std;
    using VECTOR::Vector;
    srand((int) time(0));		// seed random-number generator
    double direction;
    Vector step;				// tested model
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int trials_number = 0;			// user defined trials number
    double highest = .0;
    double average = .0;
    double lowest = .0;

    cout << "Enter target distance (q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep)) {
            break;
        }
        cout << "Enter step trials number: ";
        if (!(cin >> trials_number)) {
            break;
        }
        for (int i = 0; i < trials_number; i++) {
            while (result.magval() < target) {
                direction = rand() % 360;
                step.reset(dstep, direction, VECTOR::Vector::Mode::POL);
                result = result + step;
                steps++;
            }
            if(i == 0) {
                lowest = steps;
            }
            if (
                lowest > steps ) {
                lowest = steps;
            }
            if ( highest < steps ) {
                highest = steps;
            }
            average += steps;
            result.reset(0.0, 0.0);
        }
        average /= trials_number;

        cout << "After " << trials_number << " trials, the subject has the following data:\n";
        cout << "Minimal steps: " << lowest << endl;
        cout << "Maximum steps: " << highest << endl;
        cout << "Average steps: " << average << endl;
        result.reset(0.0, 0.0);				        // reset vector to 0
        average, highest = 0;						// reset average to 0 for new data input
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    // keep window open
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();

    return 0;
}