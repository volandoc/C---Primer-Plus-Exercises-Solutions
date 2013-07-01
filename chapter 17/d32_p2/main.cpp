/*
Write a program that copies your keyboard input (up to the simulated end-of-file) to a file named on the command line.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void main() {
    string filename;
    cout << "Please, enter file name: ";
    cin >> filename;
    cin.clear();          //clear buffer
    cout << "Your filename is: " << filename << endl;
    ofstream file;
    file.open(filename.c_str());
    cout << "Please, enter your text: ";
    char ch;
    while (!cin.eof()) {
        cin.get(ch);  //get any char from input buffer
        file << ch;   //input ch to file stream
    }
    file.close();
    cout << "File written and closed. Bye!\n";
    system("pause");
}