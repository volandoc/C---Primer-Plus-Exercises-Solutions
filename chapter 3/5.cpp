#include <iostream>
#include <cmath>

using namespace std;

int main () {
    /*Write a program that asks how many miles you have driven
    and how many gallons of gasoline you have used
    and then reports the miles per gallon your car has gotten.
    Or, if you prefer,the program can request distance in kilometers
    and petrol in liters and then report the result European style,
    in liters per 100 kilometers.*/

    int distance, gasoline = 0;

    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "Please, enter how many kilometers you have driven: ";
    cin >> distance;
    cout << "Please, enter how many liters of gasoline you have used: ";
    cin >> gasoline;

    cout << "Car has gotten " << float(gasoline)/distance << " per kilometer.";

    cin.get();
    cin.get();
}