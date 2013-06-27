/*Write a C++ program that asks for a distance in furlongs and converts it to yards.
(One furlong is 220 yards.)*/
#include <iostream>
using namespace std;

int main ()
{

	float furlongs;
	cout << "Please, enter distance in furlongs (float value):" << std::endl;
	cin >> furlongs;
	cout << furlongs << " furlongs is about " << furlongs*220 << " yards.";

	cin.get();
	cin.get();
}