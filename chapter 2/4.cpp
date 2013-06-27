/*
Write a program that asks the user to enter his or her age.
The program then should display the age in months:
	Enter your age: 29
	Your age in months is 384.
*/
#include <iostream>
using namespace std;

int main ()
{

	int age;
	cout << "Please, enter your age in years:" << std::endl;
	cin >> age;
	cout << age << " years is " << age*12 << " months.";

	cin.get();
	cin.get();
}