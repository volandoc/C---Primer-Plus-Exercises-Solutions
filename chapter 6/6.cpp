/*
Put together a program that keeps track of monetary contributions
to the Society for the Preservation of Rightful Influence.

It should ask the user to enter the number of contributors
and then solicit the user to enter the name and contribution of each contributor.

The information should be stored in a dynamically allocated array of structures.
Each structure should have two members:
	a character array (or else a string object) to store the name
	and a double member to hold the amount of the contribution.
	
After reading all the data, the program should display the names and amounts donated
for all donors who contributed $10,000 or more.
This list should be headed by the label Grand Patrons.
	
After that, the program should list the remaining donors.
That list should be headed Patrons.
	
If there are no donors in one of the categories, the program should print the word “none.”
	
Aside from displaying two categories, the program need do no sorting.
*/

#include <iostream>
#include <string>


int main()
{
	using namespace std;

	struct contributors 
	{
		string fullname ;
		double contribution;
	};

	int input;
	cout << "The Society for the Preservation of Rightful Influence welcomes you.\n";
	cout << "Please, enter the number of contributors: ";
	int contributors_number = 0;
	cin >> contributors_number;
	cin.get();

	contributors *con_list = new contributors [contributors_number];	// dynamic list of contributors

	for ( int i = 0; i < contributors_number; i++ ) // input of patrons data
	{
		cout << "Please, enter contributor # " << i+1 << " fullname: ";
		getline( cin, con_list[i].fullname );
		cout << "Please, enter contributor # " << i+1 << " contribution: ";
		cin >> con_list[i].contribution;
		cin.get();
	}
	
	int g_patrons = 0;							// grand patrons iterator
	cout << "Grand patrons: " << endl;
	for ( int i = 0; i < contributors_number; i++ )
	{
		if ( con_list[i].contribution >= 10000 )
		{
			cout << con_list[i].fullname << endl;
			g_patrons++;
		}
	}
	if ( g_patrons == 0 )					// if no grand patrons - return "none"
		cout << "none\n";
	int patrons = 0;						// patrons iterator
	cout << "Patrons: " << endl;
	for ( int i = 0; i < contributors_number; i++ )
	{
		if ( con_list[i].contribution < 10000 )
		{
			cout << con_list[i].fullname << endl;
			patrons++;
		}
	}
	if ( patrons == 0 )						// if no patrons - return "none"
		cout << "none\n";

	cout << "\nProgram terminated.\n";
	system("pause");
	return 0; 
}
