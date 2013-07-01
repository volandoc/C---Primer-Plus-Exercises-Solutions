/*
The following is a program skeleton:

#include <iostream>
using namespace std;
#include <cstring> // for strlen(), strcpy()
struct stringy {
	char * str; // points to a string
	int ct; // length of string (not counting '\0')
};
// prototypes for set(), show(), and show() go here
int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing); // first argument is a reference,
	// allocates space to hold copy of testing,
	// sets str member of beany to point to the
	// new block, copies testing to new block,
	// and sets ct member of beany
	show(beany); // prints member string once
	show(beany, 2); //prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing); // prints testing string once
	show(testing, 3); // prints testing string thrice
	show("Done!");
	return 0;
}



Complete this skeleton by providing the described functions and prototypes.
Note that there should be two show() functions, each using default arguments.
Use const arguments when appropriate. 
Note that set() should use new to allocate sufficient space to hold the designated string.
The techniques used here are similar to those used in designing and implementing classes.
(You might have to alter the header filenames and delete the using directive, depending on your compiler.)
*/

#include <iostream>
using namespace std;
#include <cstring> // for strlen(), strcpy()
struct stringy {
	char * str; // points to a string
	int ct; // length of string (not counting '\0')
};
stringy default = {"Default stringy", 15};

// prototypes for set(), show(), and show() go here
void set(stringy& temp_stringy, char * testing);
void show(char * testing = "This is a string by default.", const int count = 1);
void show(const struct stringy = default, const int count = 1);
int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing); // first argument is a reference,
	// allocates space to hold copy of testing,
	// sets str member of beany to point to the
	// new block, copies testing to new block,
	// and sets ct member of beany
	show(beany); // prints member string once
	show(beany, 2); //prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing); // prints testing string once
	show(testing, 3); // prints testing string thrice
	show("Done!");

	system("pause");
	return 0;
}

void set(stringy& temp_stringy, char * testing)
{
	temp_stringy.str = testing;
	temp_stringy.ct = strlen(temp_stringy.str);
}
void show(char * testing, const int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << testing << endl;
	}
}
void show(const struct stringy str, const int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << str.str << endl;
	}
}