/*
Define a recursive function that takes an integer argument and returns the factorial of that argument. 
Recall that 3 factorial, written 3!, equals 3 * 2!, and so on, with 0! defined as 1.
In general, if n is greater than zero, n! = n * (n - 1)!. 
Test your function in a program that uses a loop to allow the user to enter various values for which the program reports the factorial.
*/

#include <iostream>

using namespace std;

long double factorial( long );

int main ()
{
	long number;
	cout << "Please enter factorial number: ";
	while ( cin >> number && number > 0 )
	{
		if ( number == 0 )
			cout << "0! = 1";
		else if ( number == 1 )
			cout << "1! = 1";
		else cout << number <<"! = " << factorial( number );
	cout << "\nPlease enter next factorial number: ";
	}
	
	cout << endl;
	system("pause");
}

long double factorial( long number )
{
	if ( number == 1 )
		return 1;
	else return number * factorial( number -1 );
}