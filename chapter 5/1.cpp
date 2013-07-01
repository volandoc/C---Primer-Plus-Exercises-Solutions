/*
Write a program that requests the user to enter two integers.
The program should then calculate and report the sum of all the integers between
and including the two integers.
At this point, assume that the smaller integer is entered first.
For example, if the user enters 2 and 9,
the program should report that the sum of all the integers from 2 through 9 is 44.
*/

#include <iostream>

int main ()
{
	using namespace std;
	int i1, i2, i3 = 0;
	cout << "Enter first integer = ";
	cin >> i1;
	cout << "Enter second integer = ";
	cin >> i2;

	for (int i = i1; i <= i2; i++)
	{
		i3 += i;
	}

	cout << "Your sum = " << i3 << endl;

	system("pause");
}