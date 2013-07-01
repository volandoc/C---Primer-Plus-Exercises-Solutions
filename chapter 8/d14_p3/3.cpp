/*
Write a function that takes a reference to a string object as its parameter and that converts the contents of the string to uppercase. Use the toupper() function described in Table 6.4 of Chapter 6. Write a program that uses a loop which allows you to test the function with different input.
	A sample run might look like this: 
Enter a string (q to quit): go away
	GO AWAY
	Next string (q to quit): good grief!
	GOOD GRIEF!
	Next string (q to quit): q
	Bye.
*/
#include <iostream>
#include <string>
using namespace std;

void my_to_upper(const string& str );
int main ()
{
	string str;
	cout << "Enter a string (q to quit): ";
	while ((cin >> str)&&(str != "q"))
	{
		my_to_upper(str);
		cout << "New string (q to quit): ";
	}
	system("pause");
}

void my_to_upper(const string& str )
{
	string upper_str = str;
	for (int i = 0; i < str.size(); i++)
	{
		upper_str[i] = toupper(str[i]);
	}
	cout << upper_str << endl;
}