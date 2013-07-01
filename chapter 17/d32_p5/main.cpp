/*
Mat and Pat want to invite their friends to a party, much as they did in Programming Exercise 8 in Chapter 16, except now they want a program that uses files. They have asked you to write a program that does the following:
- Reads a list of Mat's friends names from a text file called mat.dat, which lists one friend per line. The names are stored in a container and then displayed in sorted order.
- Reads a list of Pat's friends names from at ext file called pat.dat, which lists one friend perline.The names are stored in a container and then displayed in sorted order.
- Merges the two lists, eliminating duplicates and stores the result in the file matnpat.dat, one friend per line.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;
void main() {
    string input;                                       // input string
    ostream_iterator<string, char> out(cout, "\n");     // output iterator to display container elements
    set<string> mats_friends;                           // container set to hold list of Mat's friends
    set<string> pats_friends;                           // container set to hold list of Pat's friends
    set<string> comb_friends;                           // this set holds both unique and sorted list of Mat's and Pat's friends
    typedef set<string>::const_iterator set_string_iterator;
    cout << "Reading guest list for Mat... \n";
    ifstream mats_friends_file;
    mats_friends_file.open("mat.dat");
    while (mats_friends_file.peek() != EOF) {
        getline(mats_friends_file, input);              // enter friends until End Of File
        mats_friends.insert(input);                     // store a friend in container set
    }
    mats_friends_file.close();                          // close file
    cout << "Mat's friends list: " << endl;
    copy(mats_friends.begin(), mats_friends.end(), out);// display entered friends for Mat by using iterator out

    cout << "Reading guest list for Pat... \n";
    ifstream pats_friends_file;
    pats_friends_file.open("pat.dat");
    while (pats_friends_file.peek() != EOF) {
        getline(pats_friends_file, input);              // enter friends until End Of File
        pats_friends.insert(input);                     // store a friend in container set
    }
    pats_friends_file.close();                          // close file
    cout << "Pat's friends list: " << endl;
    copy(pats_friends.begin(), pats_friends.end(), out);// display entered friends for Mat by using iterator out

    set_union( mats_friends.begin(), mats_friends.end(), pats_friends.begin(), pats_friends.end(), insert_iterator<set<string>> (comb_friends, comb_friends.begin()) ); // copy mat's and pat's friends into comb_friends set
    cout << "\nPat's and Mat's friends who are welcome to Party: \n"; // set automatically sorts & removes duplicate values
    copy( comb_friends.begin(), comb_friends.end(), out ); // display the final merged, sorted, and unique list of friends of Mat and Pat
    cout << "\nStart writing in file.\n";
    ofstream file_out;
    file_out.open("matnpat.dat");
    for (set_string_iterator it = comb_friends.begin(); it != comb_friends.end(); ++it)
    {
        file_out.write(it->c_str(), sizeof(char)*(it->size()));
        file_out << "\n";
        cout << it->c_str() << std::endl;
    }
    file_out.close();
    cout << "\nFile written and closed. See in matnpat.dat. Bye!\n";
    system("pause");
}