/*
Write a program that counts the number of characters up to the first $ in input and that leaves the $in the input stream.
*/
#include <iostream>
using namespace std;
void main() {
    char ch;
    int chars=0; //first char will be left to count.
    cout << "Enter string terminate by $: ";
    //Finding no. of lines
    while((ch = cin.peek()) != '$' && ch != '\n') {
        chars++;
        cin.get(ch);
    }
    cout<< "Number of characters: " <<chars << endl;
    system("pause");
}