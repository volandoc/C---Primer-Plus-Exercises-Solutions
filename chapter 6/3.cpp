/*
Write a precursor to a menu-driven program.
The program should display a menu offering four choices,
each labeled with a letter.

If the user responds with a letter other than one of the four valid choices,
the program should prompt the user to enter a valid response until the user complies.

Then the program should use a switch to select a simple action
based on the user's selection.

A program run could look something like this:
Please enter one of the following choices:
c) carnivore p) pianist
t) tree g) game
f
Please enter a c, p, t, or g: q
Please enter a c, p, t, or g: t
A maple is a tree.
*/

#include <iostream>

int main()
{
	using namespace std;
	char input;
	bool flag = false;
	cout << "Please enter one of the following choices:\n c) carnivore p) pianist\n t) tree g) game\n q to quit" << endl;
	input = 'c';
	while ( cin >> input ) 
	{	
		switch (input)
			{
			case 'c': cout << "A carnivore is an animal.\n";
				break;
			case 'p': cout << "A pianist is a musician.\n";
				break;
			case 't': cout << "A maple is a tree.\n";
				break;
			case 'g': cout << "A game is interesting.\n";
				break;
			case 'q': exit(0);
			default: cout << "Please enter a c, p, t, or g: ";
			}
	}

	system("pause");
	return 0; 
}
