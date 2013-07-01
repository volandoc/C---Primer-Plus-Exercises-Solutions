#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main ()
{
	/*
	William Wingate runs a pizza-analysis service.
	For each pizza, he needs to record the following information:
	The name of the pizza company, which can consist of more than one word
	The diameter of the pizza
	The weight of the pizza

	Devise a structure that can hold this information
	and write a program that uses a structure variable of that type.
	
	The program should ask the user to enter each of the preceding items of information,
	and then the program should display that information.
	Use cin(or its methods) and cout.
	*/
	struct pizza
	{
		char name[250];
		float diameter;
		float weight;
	}; 

	pizza newpizza;
	cout << "Enter pizza company name     = ";
	cin.getline(newpizza.name, 250);
	cout << "Enter pizza diameter = ";
	cin >> newpizza.diameter;
	cout << "Enter pizza weight   = ";
	cin >> newpizza.weight;
	cout << endl;

	cout << "pizza company name     = " << newpizza.name << endl
		 << "pizza company diameter = " << newpizza.diameter << endl
		 << "pizza company weight   = " << newpizza.weight << endl << endl;

	system ("pause");
}