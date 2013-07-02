#include <iostream>
#include <cmath>

using namespace std;

int main () {
    /*Write a program that asks you to enter an automobile gasoline consumption figure
    in the European style (liters per 100 kilometers) and converts to the U.S.style of miles per gallon.
    Note that in addition to using different units of measurement,
    the U.S.approach (distance / fuel) is the inverse of the European approach (fuel / distance).
    Note that 100 kilometers is 62.14 miles, and 1 gallon is 3.875 liters.
    Thus, 19 mpg is about 12.4 l/100 km, and 27 mpg is about 8.7 l/100 km.*/

    float euroAutoConsFig, usAutoConsFig = 0.0;
    const float milesInKm = 0.6214;
    const float gallonsInLiter = 1/3.875;

    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "Please, enter how many liters per 100 kilometers is your automobile gets: ";
    cin >> euroAutoConsFig;

    usAutoConsFig = 100/euroAutoConsFig*milesInKm/gallonsInLiter;

    cout << "Your car can ride " << int(usAutoConsFig) << " miles per gallon.";

    cin.get();
    cin.get();
}