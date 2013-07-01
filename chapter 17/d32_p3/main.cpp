/*
Write a program that copies one file to another. Have the program take the filenames from the command line. Have the program report if it cannot open a file.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void main() {
    string file_in_name, file_out_name;
    cout << "Please, enter input file name: ";
    cin >> file_in_name;
    cin.get();
    ifstream file_in;
    file_in.open(file_in_name.c_str());
    if (file_in.is_open()) {
        cout << "Please, enter output file name: ";
        cin >> file_out_name;
        cin.get();
        cout << "Your input filename is: " << file_in_name << endl;
        cout << "Your output filename is: " << file_out_name << endl;
        ofstream file_out;
        file_out.open(file_out_name.c_str());
        char ch;
        while (file_in.peek() != EOF) {
            file_in.get(ch);  //get any char from input buffer
            file_out << ch;   //input ch to file stream
        }
        file_in.close();
        file_out.close();
        cout << "File written and closed. Bye!\n";
    } else cout << "File not found, program terminated!\n";
    system("pause");
}