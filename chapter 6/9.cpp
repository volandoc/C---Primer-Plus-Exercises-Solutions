/*
Do Programming Exercise 6 but modify it to get information from a file.

The first item in the file should be the number of contributors,
and the rest of the file should consist of pairs of lines,
with the first line of each pair being a contributor's name and the second line being a contribution.
That is, the file should look like this:
4
Sam Stone
2000
Freida Flass
100500
Tammy Tubbs
5000
Rich Raptor
55000
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


int main() {
    using namespace std;
    struct contributors {
        string fullname ;
        double contribution;
    };

    ifstream inFile("test.txt");
    // Check file existing and in condition
    if ( !inFile.is_open() ) {
        cout << "Could not open the file" << endl;
        cout << "\nProgram terminated.\n";
        exit(EXIT_FAILURE);
    }

    int input;
    cout << "The Society for the Preservation of Rightful Influence welcomes you.\n";
    int contributors_number = 0;
    inFile >> contributors_number;
    inFile.get();
    cout << "Patrons number: " << contributors_number;
    cout << "\nMaking list of patrons...\n";
    contributors * con_list = new contributors [contributors_number];   // dynamic list of contributors
    cout << "Success\n";

    while ( inFile ) {
        for ( int i = 0; i < contributors_number; i++ ) { // input of patrons data
            getline( inFile, con_list[i].fullname , '\n' );
            inFile >> con_list[i].contribution;
            inFile.get();
        }
    }
    inFile.close();

    int g_patrons = 0;                            // grand patrons iterators
    cout << "\nGrand patrons: \n";
    for ( int i = 0; i < contributors_number; i++ ) {
        if ( con_list[i].contribution >= 10000 ) {
            cout << con_list[i].fullname << endl;
            g_patrons++;
        }
    }
    if ( g_patrons == 0 )                    // if no grand patrons - return "none"
        cout << "none\n";
    int patrons = 0;                        // patrons iterators
    cout << "\nPatrons: ";
    for ( int i = 0; i < contributors_number; i++ ) {
        if ( con_list[i].contribution < 10000 ) {
            cout << con_list[i].fullname << endl;
            patrons++;
        }
    }
    if ( patrons == 0 )                        // if no patrons - return "none"
        cout << "none\n";


    cout << "\nProgram terminated. Thank you.\n";
    system("pause");
    return 0;
}