/*
Write a program that reads up to 10 donation values into an array of double. (Or, if you prefer, use an array template object.)

The program should terminate input on non-numeric input.

It should report the average of the numbers and also report how many numbers in the array are larger than the average.
*/

#include <iostream>

const int Max = 10;  // value of array
int main() {
    using namespace std;
    double donation[Max] = {};
    cout << "Please enter donations.\n";
    cout << "You may enter " << Max << " donations.\n";
    int i, donations_count = 0;
    bool flag = false;                                    // flag for cycle termination
    for ( i = 0; i < Max; i++ ) {
        cout << "Donation #" << i+1 << ": ";
        while ( !(cin >> donation[i]) ) {
            cin.clear();                                // reset input
            while ( cin.get() != '\n' )
                continue;                                // get rid of bad input
            cout << "Input terminated.\n";
            flag = true;                                // termination of donation input
            break;
        }
        if ( flag == true )                                // flag for termination is on
            break;
        donations_count++;                                // donations counter ++
    }
    // calculate average
    double total = 0.0;
    for ( i = 0; i < Max; i++ )
        total += donation[i];
    // report results
    double donations_average = total / donations_count;
    cout << endl << donations_average  << " = average donation " << donations_count << "." << endl;
    int high_donations = 0;                                // donations that higher than average
    for ( i = 0; i < Max; i++ )
        donation[i] > donations_average ? high_donations++ : 0;
    cout << high_donations << " donations higher than average." << endl;

    system("pause");
    return 0;
}
