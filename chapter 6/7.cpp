/*
Write a program that reads input a word at a time until a lone q is entered.

The program should then report the number of words that began with vowels, the number that began with consonants, and the number that fit neither of those categories.

One approach is to use isalpha() to discriminate between words beginning with letters and those that don’t and then use an if or switch statement to further identify those passing the isalpha() test that begin with vowels.

A sample run might look like this:
Enter words (q to quit):
The 12 awesome oxen ambled quietly across 15 meters of lawn. q
5 words beginning with vowels
4 words beginning with consonants
2 others
*/

#include <iostream>
#include <string> 


int main()
{
	using namespace std;
	string str;
	int vowel_iter, consonants_iter, other_iter;
	vowel_iter = consonants_iter = other_iter = 0;
	cout << "Enter words (q to quit): \n";
	while ( ( cin >> str ) && ( str != "q" ) )
	{
		str[0] = tolower(str[0]);				// for caps character on start of sentences and names
		if ( str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u' || str[0] == 'y' )
			vowel_iter++;
		else if ( str[0] == 'b' || str[0] == 'c' || str[0] == 'd' || str[0] == 'f' || str[0] == 'g' || str[0] == 'h' || str[0] == 'j' || str[0] == 'k' || str[0] == 'l' || str[0] == 'm' || str[0] == 'n' || str[0] == 'p' || str[0] == 'q' || str[0] == 'r' || str[0] == 's' || str[0] == 't' || str[0] == 'v' || str[0] == 'w' || str[0] == 'x' || str[0] == 'z' )
			consonants_iter++;
		else
			other_iter++;
	}
	cout << vowel_iter << " words beginning with vowels\n";
	cout << consonants_iter << " words beginning with consonants\n";
	cout << other_iter << " others\n";

	cout << "\nProgram terminated.\n";
	system("pause");
	return 0; 
}
