#include <iostream>
#include <string>
#include <array>

using namespace std;

int main ()
{
	/*
	Write a program that requests the user to enter three times for the 40-yd dash
	(or 40-meter, if you prefer) and then displays the times and the average.
	Use an array object to hold the data.
	(Use a built-in array if array is not available.)
	*/
	array <float, 3> lenght;

	cout << "Enter your 1st time = ";
	cin >> lenght[0];
	cout << "Enter your 2nd time = ";
	cin >> lenght[1];
	cout << "Enter your 3rd time = ";
	cin >> lenght[2];
	
	cout << "Your average time = " << float(lenght[0] + lenght[1] +lenght[2])/3 << endl;


	system ("pause");
}