#include <iostream>
#include "d16_p1_header.h"
using namespace std;
struct golf;

// non-interactive version:
// function sets golf structure to provided name, handicap
// using values passed as arguments to the function
void setgolf(golf & g, const char * name, int hc)
{
	strcpy_s(g.fullname, name);
	g.handicap = hc;
	cout << "Done function setgolf.\n";
	cout << "full name: " << g.fullname << " hc: "<< g.handicap << endl;
}
// interactive version:
// function solicits name and handicap from user
// and sets the members of g to the values entered
// returns 1 if name is entered, 0 if name is empty string
int setgolf(golf & g)
{
	int hc;
	cout << "Please, enter player name: ";
	cin.getline(g.fullname, Len);
	if ( g.fullname[0] == ' ' || g.fullname[0] == '\0') // not fully clear check, if user enters whitespace and then name - input terminates
		{
			cout << "Empty string, data input terminated.";
			return 0;
		}
	else
	{
		cout << "Please, enter player handicap: ";
		cin >> g.handicap;

		cout << "You entered: " << g.fullname << " " << g.handicap;
		return 1;
	}
	cout << "Some bad error!";
	return 0;
}
// function resets handicap to new value
void handicap(golf & g, int hc)
{
	g.handicap = hc;
	cout << "\nDone function handicap.\n";
	cout << "New " << g.fullname << " handicap: "<< g.handicap << endl;
}
// function displays contents of golf structure
void showgolf(const golf & g)
{
	if ( g.fullname[0] == ' ' || g.fullname[0] == '\0') // not fully clear check, if user enters whitespace and then name - input terminates
		cout << "No data for this player.\n";
	else
	{
		cout << g.fullname << " handicap is " << g.handicap << " points.\n";
	}
}