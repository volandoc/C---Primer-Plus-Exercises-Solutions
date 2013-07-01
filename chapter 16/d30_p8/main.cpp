/*
Mat and Pat want to invite their friends to a party. They ask you to write a program that does the following:
    • Allows Mat to enter a list of his friends' names. The names are stored in a container and then displayed in sorted order.
    • Allows Pat to enter a list of her friends' names. The names are stored in a second container and then displayed in sorted order.
    • Creates a third container that merges the two lists, eliminates duplicates, and displays the contents of this container.
*/

#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>


using namespace std;

int main() {
    string input;                                       // keyboard input string
    ostream_iterator<string, char> out(cout, "\n");     // output iterator to display container elements
    set<string> mats_friends;                           // container set to hold list of Mat's friends
    // set - is used because it automatically sorts the elements and allows only unique items in it
    cout << "Enter guest list for Mat (s to stop): \n";
    while (getline(cin,input) && input != "s")          // enter friends until "s" is entered for the name
        mats_friends.insert(input);                     // store a friend in container set
    cout << "Mat's friends list: " << endl;
    copy(mats_friends.begin(), mats_friends.end(), out);// display entered friends for Mat by using iterator out

    set<string> pats_friends;                           // Pat's friend container set
    cout << "\nEnter guest list for Pat (s to stop): \n";
    while (getline(cin,input) && input != "s")          // get friends for Pat
        pats_friends.insert(input);                     // store them in Pat's container set
    cout << "Pat's friends list: " << endl;
    copy( pats_friends.begin(), pats_friends.end(), out );// and display Pat's friends

    set<string> comb_friends;                           // this set holds both unique and sorted list of Mat's and Pat's friends
    set_union( mats_friends.begin(), mats_friends.end(), pats_friends.begin(), pats_friends.end(), insert_iterator<set<string>> (comb_friends, comb_friends.begin()) ); // copy mat's and pat's friends into comb_friends set
    cout << "\nPat's and Mat's friends who are welcome to Party: \n"; // set automatically sorts & removes duplicate values
    copy( comb_friends.begin(), comb_friends.end(), out ); // display the final merged, sorted, and unique list of friends of Mat and Pat

    system("pause");
    return 0;
}