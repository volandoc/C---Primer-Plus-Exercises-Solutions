/*
When you join the Benevolent Order of Programmers,
you can be known at BOP meetings by your real name,
your job title, or your secret BOP name.

Write a program that can list members by real name,
by job title, by secret name, or by a member's preference. 

Base the program on the following structure:
// Benevolent Order of Programmers name structure 

struct bop {
	char fullname[strsize]; // real name
	char title[strsize]; // job title
	char bopname[strsize]; // secret BOP name
	int preference; // 0 = fullname, 1 = title, 2 = bopname
};

In the program, create a small array of such structures and initialize it to suitable values.
Have the program run a loop that lets the user select from different alternatives:
	a. display by name		b. display by title
	c. display by bop name	d. display by preference
	q. quit

	Note that “display by preference” does not mean display the preference member;
	it means display the member corresponding to the preference number.
	For instance, if preference is 1, choice d would display the programmer's job title.
	A sample run may look something like the following:
Benevolent Order of Programmers Report
	a. display by name    b. display by title
	c. display by bop name d. display by preference
	q. quit
	Enter your choice: a
	Wimp Macho
	Raki Rhodes
	Celia Laiter
	Hoppy Hipman
	Pat Hand
	Next choice: d
	Wimp Macho
	Junior Programmer
	MIPS
	Analyst Trainee
	LOOPY
	Next choice: q
	Bye!
*/



#include <iostream>

// Benevolent Order of Programmers name structure 

const int strsize = 100;
const int ListSize = 4;

struct bop {
	char fullname[strsize];		// real name
	char title[strsize];		// job title
	char bopname[strsize];		// secret BOP name
	int preference;				// 0 = fullname, 1 = title, 2 = bopname
};

int main()
{
	using namespace std;
	bop *bop_list = new bop[ListSize];
													// new array of BOP initialization
	strcpy ( bop_list[0].fullname, "John Smith" );
	strcpy ( bop_list[0].title, "Master" );
	strcpy ( bop_list[0].bopname, "KILLER" );
	bop_list[0].preference = 0;

	strcpy ( bop_list[1].fullname, "Jane Smith" );
	strcpy ( bop_list[1].title, "GrossMaster" );
	strcpy ( bop_list[1].bopname, "CUSROMER" );
	bop_list[1].preference = 1;

	strcpy ( bop_list[2].fullname, "Mike Bad" );
	strcpy ( bop_list[2].title, "Slave" );
	strcpy ( bop_list[2].bopname, "DadBad" );
	bop_list[2].preference = 2;

	strcpy ( bop_list[3].fullname, "Silvester Stallone" );
	strcpy ( bop_list[3].title, "Painkiller" );
	strcpy ( bop_list[3].bopname, "Mommy" );
	bop_list[3].preference = 3;

	char input;
	cout << "Benevolent Order of Programmers Report\n";
	cout << "    a. display by name    b. display by title\n    c. display by bop name d. display by preference\n    q. quit" << endl;
	cout << "Enter your choice: ";
	input = 'c';
	while ( cin >> input ) 
	{	
		switch (input)
		{
		case 'a':	for ( int i = 0; i < ListSize; i++)
					{
						cout << bop_list[i].fullname << endl;
					} break;
		case 'b':	for ( int i = 0; i < ListSize; i++)
					{
						cout << bop_list[i].title << endl;
					} break;
		case 'c':	for ( int i = 0; i < ListSize; i++)
					{
						cout << bop_list[i].bopname << endl;
					} break;
		case 'd':	for ( int i = 0; i < ListSize; i++)
					{
						switch ( bop_list[i].preference )
						{ 
							case 0 : cout << bop_list[i].fullname << endl;
									break;
							case 1 : cout << bop_list[i].title << endl;
								break;
							case 2 : cout << bop_list[i].bopname << endl;
								break;
							default: cout << "Unexpected user preference." << endl;
						}
					} break;
		case 'q': exit(0);
		default: cout << "Please enter a a, b, c, d or q: ";
		}
		cout << "\nEnter your choice: ";
	}


	system("pause");
	return 0; 
}
