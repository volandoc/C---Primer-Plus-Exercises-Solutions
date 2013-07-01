/*
Redo Listing 7.7, modifying the three array-handling functions to each use two pointer parameters to represent a range.
The fill_array() function, instead of returning the actual number of items read,
should return a pointer to the location after the last location filled;
the other functions can use this pointer as the second argument to identify the end of the data.
*/
// arrfun3.cpp -- array functions and const
#include <iostream>
const int Max = 5;

// function prototypes
double * fill_array(double * begin, double * end);
void show_array(const double * begin, const double * end);  // don't change data
void revalue(double r, double * begin, double * end);

int main()
{
	using namespace std;
	double properties[Max];

	double * end_ptr = fill_array(properties, properties+Max);

	show_array(properties, end_ptr);
	if (end_ptr > properties)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))    // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, end_ptr);
		show_array(properties, end_ptr);
	}
	cout << "Done.\n";
	cin.get();
	cin.get();
	return 0;
}

double * fill_array(double * begin, double * end)
{
	using namespace std;
	double * pt;
	double temp;
	int i = 0;
	for ( pt = begin; pt != end; pt++)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		i++;
		if (!cin)    // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)     // signal to terminate
			break;
		*pt = temp;
	}
	return pt; // returns after the end pointer
}

// the following function can use, but not alter
void show_array(const double * begin, const double * end)
{
	using namespace std;
	const double * pt;
	int i = 0;
	for ( pt = begin; pt != end; pt++)
	{
		cout << "Property #" << (i + 1) << ": $";
		i++;
		cout << *pt << endl;
	}
}

// multiplies each element of array by r
void revalue(double r, double * begin, double * end)
{
	double * pt;
	for (pt = begin; pt != end; pt++)
		*pt *= r;
}
