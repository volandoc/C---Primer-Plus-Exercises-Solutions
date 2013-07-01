/*
Write a program that repeatedly asks the user to enter pairs of numbers
until at least one of the pair is 0. 
For each pair, the program should use a function to calculate the harmonic mean of the numbers.

The function should return the answer to main(), which should report the result.
The harmonic mean of the numbers is the inverse of the average of the inverses and can be calculated as follows:
harmonic mean = 2.0 * x * y / (x + y)
*/
#include <iostream>

using namespace std;

double harmonic_mean( double, double );

int main ()
{
	double x,y;
	cout << "Please, enter two numbers: ";
	while ( (cin >> x >> y) && (x != 0) && ( y != 0 ) )
	{
		cout << "Harmonic mean of " << x << " and " << y << " = " << harmonic_mean( x, y );
		cout << "\n\nPlease, enter two new numbers: ";
	}
	cout << "Sorry, wrong input, program terminated.\n";
	system("pause");
}

double harmonic_mean( double x, double y )
{
	return 2.0 * x * y / (x + y);
}
