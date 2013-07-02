/*
Write a program that reads keyboard input to the @symbol
and that echoes the input except for digits,
converting each uppercase character to lowercase, and vice versa. (Don't forget the cctype family.)
*/

#include <iostream>
#include <string>
#include <cctype>

int main () {
    using namespace std;
    cout << "Enter text for lowercase output, and type @"
         " to terminate input.\n";
    char ch, corrected;

    cin.get(ch);                // get first character
    while (ch != '@') {          // test for sentinel
        if(!isdigit(ch)) {  // is it a digit?
            corrected = tolower(ch);
            cout << corrected;
        }
        cin.get(ch);            // get next character
    }
    cout << "Program terminated.\n\n";

    system("pause");
}