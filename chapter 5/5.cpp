/*
You sell the book 'C++ for Fools'.
Write a program that has you enter a year's worth of monthly sales (in terms of number of books, not of money).

The program should use a loop to prompt you by month,
using an array of char *(or an array of string objects, if you prefer) initialized to the month strings
and storing the input data in an array of int.

Then, the program should find the sum of the array contents and report the total sales for the year.
*/


#include <iostream>
#include <array>
#include <string>
using namespace std;
int main ()
{	
	array <string, 12> month = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	array <int, 12> sales;

	for (int i = 0; i < 12 ; i++ )
	{
		cout << "Please, enter sales in " << month[i] << " = ";
		cin >> sales[i];
	}
	
	int sum = 0;
	for (int i = 0; i < 12 ; i++ )
	{
		sum += sales[i];
	}

	cout << "Average sales per year = " << sum << endl; 
	system("pause");
}