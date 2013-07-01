/*
Write a program that asks the user to enter up to 10 golf scores, which are to be stored in an array.
You should provide a means for the user to terminate input prior to entering 10 scores.
The program should display all the scores on one line and report the average score.
Handle input, display, and the average calculation with three separate array-processing functions.
*/
#include <iostream>

using namespace std;

int input( double * , const int );
void display( const double * , const int );
void average( const double * , const int );

const int Number = 10;
int main ()
{
	double scores[Number] = {};
	int real_number = 0; //real number of scores which user enters
	real_number = input( scores, Number ); // func "input" takes input from user, counts and returns quantity of scores

	display( scores, real_number ); // display all scores
	average( scores, real_number ); // summation of all scores

	
	system("pause");
}

int input( double * p, const int Number )
{
	int i = 0; // scores counter
	double temp = 0;
	cout << "You can terminate input by entering non numerical input.\n";
	cout << "Enter score # " << i+1 << endl;
	while ( (i < Number) && (cin >> temp ) )
	{
		p[i] = temp;
		i++;
		cout << "Enter score # " << i+1 << endl;
	}
	return i;
}

void display( const double * p, const int real_number)
{
	cout << "Scores are:\n";
	for (int k=0; k < real_number; k++)
	{
		cout << p[k] << "  " ;
	}
	cout << endl;
}

void average( const double * p, const int real_number )
{
	double sum = 0;
	for (int k=0; k < real_number; k++)
	{
		sum += p[k];
	}
	cout << "Average score : " << sum << endl;
}