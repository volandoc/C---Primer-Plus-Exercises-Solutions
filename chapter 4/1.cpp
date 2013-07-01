/*
Write a C++ program that requests and displays information
as shown in the following example of output:
	What is your first name? Betty Sue
	What is your last name? Yewe
	What letter grade do you deserve? B
	What is your age? 22
	Name: Yewe, Betty Sue
	Grade: C
	Age: 22

Note that the program should be able to accept first names
that comprise more than one word.
Also note that the program adjusts the grade downward - that is,up one letter.
Assume that the user requests an A,a B,or a C so that you don't have to worry
about the gap between a D and an F.
*/
#include <iostream>
#include <string>

using namespace std;

int main ()
{
	struct student
	{
		string firstName;
		string lastName;
		char grade;
		short age;
	};

	student newstudent;

	cout << "What is your first name? ";
	getline(cin, newstudent.firstName);
	cout << "What is your last name? ";
	getline(cin, newstudent.lastName);
	cout << "What letter grade do you deserve? ";
	cin >> newstudent.grade;
	cout << "What is your age? ";
	cin >> newstudent.age;

	cout << "Name: " << newstudent.firstName << ", " << newstudent.lastName << endl;
	newstudent.grade +=1;
	cout << "Grade: " << newstudent.grade <<endl;
	cout << "Age: " << newstudent.age <<endl;


	system ("pause");
}