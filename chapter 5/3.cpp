/*
Write a program that asks the user to type in numbers.
After each entry, the program should report the cumulative sum of the entries to date.
The program should terminate when the user enters 0.
*/

#include <iostream>
using namespace std;
int main ()
{	
	int i;
	cout << "Type in number = ";
	cin >> i;
	int sum = 0;
	sum +=i;
	while ( i != 0 )
	{
		sum +=i;
		cout << "sum = " << sum << endl;
		cout << "Type in number = ";
		cin >> i;
	}
		cout << "Program terminated." << endl;
	system("pause");
}

