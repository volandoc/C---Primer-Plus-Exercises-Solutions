/*
Consider the class definitions of Programming Exercise 5 in Chapter 14, "Reusing Code in C++".
If you haven't yet done that exercise, do so now. Then do the following:
Write a program that uses standard C++ I/O and file I/O in conjunction with data of types employee, manager, fink, and highfink, as defined in Programming Exercise 5 in Chapter 14.

The program should be along the general lines of Listing 17.17 in that it should let you add new data to a file.
The first time through, the program should solicit data from the user, show all the entries, and save the information in a file.

On subsequent uses, the program should first read and display the file data, let the user add data, and show all the data.
One difference is that data should be handled by an array of pointers to type employee.
That way, a pointer can point to an employee object or to objects of any of the three derived types.

Keep the array small to facilitate checking the program; for example, you might limit the array to 10 elements:
const int MAX = 10; // no more than 10 objects
...
employee * pc[MAX];

For keyboard entry, the program should use a menu to offer the user the choice of which type of object to create.

The menu should use a switch to use new to create an object of the desired type
and to assign the object's address to a pointer in the pc array.
Then that object can use the virtual setall() function to elicit the appropriate data from the user:
pc[i]->setall(); // invokes function corresponding to type of object

To save the data to a file, devise a virtual writeall() function for that purpose:
for (i = 0; i < index; i++)
pc[i]->writeall(fout);// fout ofstream connected to output file

Note :Use text I/O, not binary I/O, for Programming Exercise 6.
(Unfortunately, virtual objects include pointers to tables of pointers to virtual functions, and write() copies this information to a file. An object filled by using read() from the file gets weird values for the function pointers, which really messes up the behavior of virtual functions.)

Use a newline character to separate each data field from the next; this makes it easier to identify fields on input.
Or you could still use binary I/O, but not write objects as a whole.
Instead, you could provide class methods that apply the write() and read() functions to each class member individually rather than to the object as a whole.
That way, the program could save just the intended data to a file.
The tricky part is recovering the data from the file.
The problem is, how can the program know whether the next item to be recovered is an employee object, a manager object, a finktype, or a highfinktype?
One approach is, when writing the data for an object to a file, precede the data with an integer that indicates the type of object to follow.
Then, on file input, the program can read the integer and then use switch to create the appropriate object to receive the data:

enum classkind{Employee, Manager, Fink, Highfink}; // in class header
...
int classtype;
while((fin >> classtype).get(ch)){ // newline separates int from data
switch(classtype) {
case Employee : pc[i] = new employee;
: break;

Then you can use the pointer to invoke a virtual getall() function to read the information:
pc[i++]->getall();
*/
#include "emp.h"

using namespace std;
int main(int argc, char * argv[]) {
    string filename;
    fstream myFile;
    cout << "Please enter your choice: \n";
    cout << "a: select file;                   b: start employers input;\n";
    cout << "c: show employers list;           q: save file and(or) quit.\n";
    char choise;
    while ((cin >> choise) && (choise != 'q')) { // start of service menu
        switch (choise) {
        case 'a': {
            if (myFile.is_open()) { // if another file is already open
                myFile.close();     // close old file
            }
            cout << "Please enter filename: ";
            cin >> filename;
            myFile.open(filename.c_str(), fstream::in | fstream::out | fstream::app); //open new file for input, output from the EOF
        }
        break;
        case 'b': {
            if (myFile.is_open()) {
                cout << "\nHere must be module for data input and writing to file.\n";
                // write_employer(myFile); // need to write this method. void write_employer(&fstream); write employers from keyboard to file in redacted manner.
            } else cout << "You need first to open file!\n";
        }
        break;
        case 'c': {
            if (myFile.is_open()) {
                cout << "Here must be data from file: \n";
                // getall(myFile); // need to write this method. void getall(const &fstream); Shows all data from file in redacted manner.
            } else cout << "You need first to open file!\n";
        }
        break;
        default : {
        }
        } // end of switch

        cout << "Please enter your choice: \n";                                    //interface in cycle
        cout << "a: select file;                   b: start employers input;\n";
        cout << "c: show employers list;           q: save file and(or) quit.\n";
    } // end of service menu

    myFile.close();
    cout << "Program terminated.\n";
    system("pause");
    /*    myFile.write(filename.c_str(), sizeof(char)*filename.size());*/
}


/*
// main class from emp project
int main(void) {
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl;
    ma.ShowAll();
    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew"); // recruitment?
    hf.ShowAll();
    cout << "Press a key for next phase:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();
    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
    tri[i]->ShowAll();

    system("pause");
    return 0;
}
*/


/*
Listing 17.17
// count.cpp -- counting characters in a list of files
#include <iostream>
#include <fstream>
#include <cstdlib>          // or stdlib.h
int main(int argc, char * argv[]) {
    using namespace std;
    if (argc == 1) {        // quit if no arguments
        cerr << "Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }

    ifstream fin;              // open stream
    long count;
    long total = 0;
    char ch;

    for (int file = 1; file < argc; file++) {
        fin.open(argv[file]);  // connect stream to argv[file]
        if (!fin.is_open()) {
            cerr << "Could not open " << argv[file] << endl;
            fin.clear();
            continue;
        }
        count = 0;
        while (fin.get(ch))
            count++;
        cout << count << " characters in " << argv[file] << endl;
        total += count;
        fin.clear();           // needed for some implementations
        fin.close();           // disconnect file
    }
    cout << total << " characters in all files\n";

    return 0;
}
*/
