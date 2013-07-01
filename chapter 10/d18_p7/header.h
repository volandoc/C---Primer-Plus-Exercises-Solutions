#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
/*
A Betelgeusean plorg has these properties:
Data
A plorg has a name with no more than 19 letters.
A plorg has a contentment index (CI),which is an integer.
Operations
A new plorg starts out with a name and a CI of 50.
A plorg 's CI can change.
A plorg can report its name and CI.
The default plorg has the name "Plorga".
Write a Plorg class declaration ( including data members and member function prototypes ) that represents a plorg. Write the function definitions for the member functions. Write a short program that demonstrates all the features of the Plorg class.
*/
class Plorg
{
private:
	char name_[19];
	double CI_;
public:
	Plorg(char *name = (char *) "Plorga", double CI = 50) { strcpy(name_, name); CI_ = CI; }; 
	void showPlorg() const; // shows current Plorg name and CI
	void setCI(const int n); // set Plorg CI to new value
};