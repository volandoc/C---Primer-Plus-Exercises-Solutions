/*
Redo Listing 9.9, replacing the character array with a string object.
The program should no longer have to check whether the input string fits,
and it can compare the input string to "" to check for an empty line.
*/

// static.cpp -- using a static local variable
#include <iostream>
#include <string>
using namespace std;
// function prototype
void strcount(const string & str);

int main() {
    string input;

    cout << "Enter a line:\n";
    while (getline(cin, input)&& input != "") {
        cout << "Enter next line (empty line to quit):\n";
        strcount(input);
    }
    cout << "\nBye\n";

    system("pause");
    return 0;
}

void strcount(const string & str) {
    static int total = 0;        // static local variable

    cout << "\"" << str <<"\" contains " << str.length() << " characters\n";
    total += str.length();
    cout << total << " characters total\n";
}
