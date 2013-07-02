#include <iostream>
#include <cmath>

using namespace std;

int main () {
    /*Write a program that asks the user to enter a latitude
        in degrees, minutes,and seconds and that then displays the latitude
        in decimal format.

        There are 60 seconds of arc to a minute and 60 minutes of arc to a degree;
        represent these values with symbolic constants.
        You should use a separate variable for each input value.
        A sample run should look like this:

        Enter a latitude in degrees, minutes, and seconds:
        First, enter the degrees: 37
        Next, enter the minutes of arc: 51
        Finally, enter the seconds of arc: 19
        37 degrees, 51 minutes, 19 seconds = 37.8553 degrees*/

    int latitudeDegrees = 0;
    int latitudeMinutes = 0;
    int latitudeSeconds = 0;
    const double minuteInDegrees = 0.0166666667;
    const double secondInDegrees = 0.000277777778;
    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl
         << "First, enter the degrees: ";
    cin >> latitudeDegrees;
    cout << "Next, enter minutes of arc: ";
    cin >> latitudeMinutes;
    cout << "Next, enter seconds of arc: ";
    cin >> latitudeSeconds;
    cout << latitudeDegrees << " degrees, "
         << latitudeMinutes << " minutes, "
         << latitudeSeconds << " seconds = "
         << latitudeDegrees + latitudeMinutes * minuteInDegrees + latitudeSeconds * secondInDegrees
         << " degrees.";


    cin.get();
    cin.get();
}