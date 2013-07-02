/*
Write a program that uses an array of char and a loop to read one word at a time until the word done is entered.
The program should then report the number of words entered (not counting done).
A sample run could look like this:
    Enter words (to stop, type the word done):
    anteater birthday category dumpster
    envy finagle geometry done for sure
    You entered a total of 7 words.

You should include the cstring header file and use the strcmp()function to make the comparison test.
*/


#include <iostream>
#include <cstring>
using namespace std;
int main () {
    char tmp[200];
    int i = 0;
    cout << "Enter words (to stop, type the word done): " << endl;
    cin >> tmp;
    while (strcmp("done", tmp)) {
        i++;
        cin >> tmp;
    }
    cout << "You entered a total of " << i << " words." << endl;
    cout  << endl;
    system("pause");
}