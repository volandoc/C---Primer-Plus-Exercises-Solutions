#include <iostream>
namespace SALES
{
using std::cin;
using std::cout;
using std::endl;
extern const int QUARTERS = 4;
struct Sales
{
	double sales[QUARTERS];
	double average;
	double max;
	double min;
};	
	// copies the lesser of 4 or n items from the array ar
	// to the sales member of s and computes and stores the
	// average, maximum, and minimum values of the entered items;
	// remaining elements of sales, if any, set to 0
	void setSales(Sales & s, const double ar[], int n)
	{
		for (int i = 0; i < QUARTERS; i++)
		{
			s.sales[i] = ar[i];
		}
		double min = s.sales[0];
		double max = s.sales[0];
		double average = s.sales[0];
		for (int i = 1; i < n; i++)
		{
			if (min > s.sales[i])
				min = s.sales[i];
			if (max < s.sales[i])
				max = s.sales[i];
			average += s.sales[i];
		}
		average /= 4;
		s.min = min;
		s.max = max;
		s.average = average;

		for (int i = n; i < QUARTERS; i++) // if elements of arr < QUANTITY - push 0.
		{
			s.sales[i] = 0;
		}
	}
	// gathers sales for 4 quarters interactively, stores them
	// in the sales member of s and computes and stores the
	// average, maximum, and minimum values
	void setSales(Sales & s)
	{

	for (int i = 0; i < QUARTERS; i++)
	{
		cout << "Please enter sale # " << i+1 << " : ";
		cin >> s.sales[i];
	}
	
	double min = s.sales[0];
	double max = s.sales[0];
	double average = s.sales[0];
	for (int i = 1; i < QUARTERS; i++)
	{
		if (min > s.sales[i])
			min = s.sales[i];
		if (max < s.sales[i])
			max = s.sales[i];
		average += s.sales[i];
	}
	average /= 4;
	s.min = min;
	s.max = max;
	s.average = average;


	}
	// display all information in structure s
	void showSales(const Sales & s)
	{
		cout << "Sales: \n";
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << "    # "<<i+1 << " : " << s.sales[i] << endl;
		}
		cout << "    min : " << s.min << endl;
		cout << "    max : " << s.max << endl;
		cout << "average : " << s.average << endl;
	}

}