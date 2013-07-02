#include <iostream>
#include <cstring>

using namespace std;

int main () {
    /*
    Write a program that asks the user to enter his or her first name and then last name,
    and that then constructs, stores, and displays a third string,
    consisting of the user's last name followed by a comma, a space, and first name.
    Use char arrays and functions from the cstring header file.
    A sample run could look like this:
        Enter your first name: Flip
        Enter your last name: Fleming
        Here's the information in a single string: Fleming, Flip
    */
    char fName [40], lName [40];
    char splitName [80];
    cout << "Enter your first name: ";
    cin.get( fName, 20 ).get();
    cout << "Enter your last name: ";
    cin.get( lName, 20 ).get();
    strcpy(splitName, fName);
    strcat(splitName, ", ");
    strcat(splitName, lName);
    cout << "Here's the information in a single string: "<< splitName << endl;

    system ("pause");
}