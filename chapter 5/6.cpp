/*
Do Exercise 5 (previous) but use a two-dimensional array to store input for 3 years of monthly sales.
Report the total sales for each individual year and for the combined years.

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

const int Years = 3;
const int Months = 12;
int main ()
{	
	const string month[Months] =
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	
	
	int sales [Years] [Months];

	for (int i = 0; i < Years ; i++ )
	{
		for (int j = 0; j < Months; j++)
		{
			cout << "Please, enter sales in " << i+1 << " year, and "
				 << month[j] << " = ";
			cin >> sales[i][j];
		}
	}

	int sum[3];
	for (int i = 0; i < Years ; i++ )
	{
		int sum_tmp = 0;
		for ( int j = 0; j < Months; j++)
		{
			sum_tmp += sales[i][j];
		}
		sum[i] = sum_tmp;
	}

	for (int i = 0; i < Years ; i++ )
	{
		cout << "Average sales per year " << i+1 << " = " << sum[i] << endl; 
	}
	cout << "Average sales per year = " << sum[0] + sum [1] + sum[2] << endl; 

	system("pause");
}