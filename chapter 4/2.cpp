#include <iostream>
#include <string>

using namespace std;

int main ()
{
	/*
	Rewrite Listing 4.4, using the C++ string class instead of char arrays.
	Listing:
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name:\n";
	cin.getline(name,ArSize);
	cout << "Enter your favorite dessert:\n";
	cin.getline(dessert,ArSize);
	cout << "I have some delicious " << dessert << " for you, " << name << ".\n";
	*/
	string name, dessert;
	cout << "Enter your name:\n";
	getline( cin, name );
	cout << "Enter your favorite dessert:\n";
	getline( cin, dessert );
	cout << "I have some delicious " << dessert << " for you, " << name << ".\n";


	system ("pause");
}