/*
Do the same problem as given in Programming Exercise 1, but do worry about complications
    such as capitalization, spaces, and punctuation. That is, "Madam, I'm Adam"
    should test as a palindrome. For example, the testing function could reduce the string to
    "madamimadam" and then test whether the reverse is the same. Don't forget the useful
    cctype library. You might find an STL function or two useful although not necessary.
*/

#include <iostream>
#include <string>
#include <cctype> // required for isalpha and tolower functions, although may not be necessary under VS 2010

using namespace std;

bool ispalindrome(const string &); // function takes a string ref and returns true if string is palindrome

int main() {
    string my;

    cout << "Enter words (capitalization and punctuation ignored), q to quit: ";
    while (getline(cin,my) && my != "q") { // enter words until q is entered
        if (ispalindrome(my)) // check if entered word is palindrome
            cout << my << " is palindrome!!\n";
        else
            cout << my << " is not palindrome!!\n";
    }

    cout << "\nThe end!";

    system("pause");
    return 0;
}

bool ispalindrome(const string & st) { // const & reference, we need original string to compare with reversed version
    string temp_orig = st;  // save string value to temporary variable, thus preserving original passed string untouched
    string temp_rev;

    int j = 0;      //let's remove all non-alphabetic symbols from a string
    for (int i = 0; i < st.size(); i++) {    // loop through each character in a string
        if (!isalpha(st[i]))    // if non-alphabetic character is found (such as .!,'), do not store it in a new string
            continue;
        else {
            temp_orig[j] = tolower(st[i]);  // else, if character is alphabetic, convert it to lowercase (to test for equality) and store
            j++;    // increase the index to place the next alphabetic character in the same string being examined, no need to create an extra variable
        }
    }
    temp_orig.resize(j);    // reduce the string to j places, all proper alphabetic character are stored from 0 to j indexes in a string being examined and edited
    temp_rev = temp_orig;   // store the reversed version of alpha-only string to check for equality
    reverse(temp_rev.begin(), temp_rev.end()); // do the reverse operation
    cout << "\nReversed: " << temp_rev << endl; // display it

    if (temp_rev == temp_orig) // if reversed = original
        return true; // then it is palindrome
    else
        return false; // otherwise, it is not
}