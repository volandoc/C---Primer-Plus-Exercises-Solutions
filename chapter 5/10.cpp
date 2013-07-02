/*
Write a program using nested loops that asks the user
to enter a value for the number of rows to display.

It should then display that many rows of asterisks,
with one asterisk in the first row, two in the second row, and so on.

For each row, the asterisks are preceded by the number of periods
needed to make all the rows display a total number of characters
equal to the number of rows.

A sample run would look like this:
    Enter number of rows: 5
    ....*
    ...**
    ..***
    .****
    *****
*/


#include <iostream>
#include <string>
using namespace std;
int main () {
    string tmp;
    int rows = 0;
    cout << "Enter number of rows: ";
    cin >> rows;
    for ( int i = 0; i < rows; i++) {
        tmp += ".";                        //taking string of '.'-s with 'row' length
    }
    for ( int i = rows-1; i < -1; i--) {  // throwing down the last element of string and iterate thought 'tmp' backwards to 0 including it
        tmp[i] = (char) 42;                // changing 'i' element to char '*' = 42
        cout << tmp << endl;
    }

    cout  << endl;
    system("pause");
}