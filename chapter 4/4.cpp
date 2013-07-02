#include <iostream>
#include <string>

using namespace std;

int main () {
    /*
    Write a program that asks the user to enter his or her first name and then last name,
    and that then constructs, stores, and displays a third string
    consisting of the user's last name followed by a comma, a space, and first name.
    Use string objects and methods from the string header file.
    A sample run could look like this:
    Enter your first name: Flip
    Enter your last name: Fleming
    Here's the information in a single string: Fleming, Flip
    */
    string fName, lName, splitName;
    cout << "Enter your first name: ";
    getline(cin, fName);
    cout << "Enter your last name: ";
    getline(cin, lName);
    splitName = lName + ", " + fName;
    cout << "Here's the information in a single string: "<< splitName << endl;

    system ("pause");
}