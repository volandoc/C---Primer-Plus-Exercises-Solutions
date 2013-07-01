/*
Modify Listing 8.14 so that it uses two template functions called SumArray() to return the sum of the array contents instead of displaying the contents.
The program now should report the total number of things and the sum of all the debts.
*/

// tempover.cpp --- template overloading
#include <iostream>

template <typename T>            // template A
void ShowArray(T arr[], int n);

template <typename T>            // template B
void ShowArray(T * arr[], int n);

template <typename T>            // template C
void SumArray(T arr[], int n);

template <typename T>            // template D
void SumArray(T * arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int main()
{
	using namespace std;
	int things[6] = {13, 31, 103, 301, 310, 130};
	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double * pd[3]; 

	// set pointers to the amount members of the structures in mr_E
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	cout << "Listing Mr. E's counts of things:\n";
	// things is an array of int
	ShowArray(things, 6);  // uses template A
	cout << "Listing Mr. E's debts:\n";
	// pd is an array of pointers to double
	ShowArray(pd, 3);      // uses template B (more specialized)
	// cin.get();

	cout << "\nSummation of Mr. E's counts of things:\n";
	// things is an array of int
	SumArray(things, 6);  // uses template A
	cout << "\nSummation Mr. E's debts:\n";
	// pd is an array of pointers to double
	SumArray(pd, 3);      // uses template B (more specialized)
	// cin.get();

	system("pause");
	return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
	using namespace std;
	cout << "template A\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n)
{
	using namespace std;
	cout << "template B\n";
	for (int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl; 
}


template <typename T>            // template C
void SumArray(T arr[], int n)
{
	using namespace std;
	T sum = (T) 0;
	cout << "template C\n";
	for (int i = 0; i < n; i++)
		sum += arr[i];
	cout << sum << endl;
}

template <typename T>            // template D
void SumArray(T * arr[], int n)
{
	using namespace std;
	T sum = (T) 0;
	cout << "template D\n";
	for (int i = 0; i < n; i++)
		sum += *arr[i];
	cout << sum << endl;
}