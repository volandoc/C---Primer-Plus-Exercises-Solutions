/*
A palindrome is a string that is the same backward as it is forward.
For example, "tot" and "otto" are rather short palindromes.
Write a program that lets a user enter a string and that passes to a bool function a reference to the string.
The function should return true if the string is a palindrome and false otherwise.
At this point, don't worry about complications such as capitalization, spaces, and punctuation.
That is, this simple version should reject "Otto" and "Madam, I'm Adam."
Feel free to scan the list of string methods in Appendix F for methods to simplify the task.
*/

#include <iostream>
#include <string>

using namespace std;

bool ispalindrome(const string &); // function takes a string ref and returns true if string is palindrome

int main() {
    string my;

    cout << "Enter words (case and punctuation sensitive), q to quit: ";
    while (cin >> my && my != "q") { // enter words until q is entered
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
    string temp = st; // save original string to a temporary string
    reverse(temp.begin(), temp.end()); // reverse the temporary
    cout << "\nReversed: " << temp << endl; // display it

    if (temp == st) // if reversed = original
        return true; // then it is palindrome
    else
        return false; // otherwise, it is not
}