/*
Write a program that asks the user to enter an hour value and a minute value.
The main() function should then pass these two values to a type void function that displays the two values in the format shown in the following sample run:
	Enter the number of hours: 9
	Enter the number of minutes: 28
	Time: 9:28
*/
#include <iostream>
using namespace std;

void ShowMyTime(int, int);

int main ()
{
	int h,m;
	cout << "Enter the number of light hours: ";
	cin >> h;
	cout << "Enter the number of minutes: ";
	cin >> m;

	ShowMyTime(h, m);

	cin.get();
	cin.get();
}

void ShowMyTime(int h, int m)
{
	cout << "Time: " << h << ":" << m;
}