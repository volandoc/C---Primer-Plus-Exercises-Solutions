/*
Redo Listing 16.3 so that it gets it words from a file.
One approach is to use a vector object instead of an array of string.
Then you can use push_back() to copy how ever many words are in your data file into the vector object and use the size() member to determine the length of the word list.
Because the program should read one word at a time from the file, you should use the >> operator rather than getline().
The file itself should contain words separated by spaces, tabs, or new lines.
*/

#include <iostream>
#include <fstream> // include fstream to read files
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector> // include vector to contain array of words read from file

using namespace std;

int main() {
    std::srand(std::time(0));

    ifstream fin; // ifstream object to read a file
    string str_finput; // string buffer to read one word at a time from file
    string filename; // filename to open
    vector<string> words; // container to store words read from file

    cout << "Enter filename with words to guess: "; // get the filename
    (cin >> filename).get();

    fin.open(filename); // open it
    if (fin.fail())
        cout << "Error opening file: " << filename << " not found!\n"; // if invalid file name or not found - display the error
    else {
        while(!fin.eof()) { // reading from file until EOF is reached
            fin >> str_finput; // read one word at a time
            words.push_back(str_finput); // immediately store the word in vector array
        }

        fin.close(); // close the file
    }

    if (words.size() > 0 && words.size() < 2 && words[0].length() < 2) // if file was opened but did not contain any words (less than 2 chars in length, it is error!
        cout << "No words to guess or file is empty!\n"; // display error msg
    else if (words.size() > 0 && words[0].length() > 2) {
        cout << "Total words loaded: " << words.size() << endl; // display total # of words loaded to vector array
        char play;
        cout << "Will you play a word game? <y/n> ";
        cin >> play;
        play = tolower(play);
        while (play == 'y') {
            string target = words[std::rand() % words.size()]; // get the random word from vector array, same syntax as with regular array
            int length = target.length(); // FOR THE REST OF COMMENTS FOR THIS PROGRAM SEE THE TEXTBOOK :)
            string attempt(length, '-');
            string badchars;
            int guesses = 6;
            cout << "Guess my secret word. It has " << length
                 << " letters, and you guess\n"
                 << "one letter at a time. You get " << guesses
                 << " wrong guesses.\n";
            cout << "Your word: " << attempt << endl;
            while (guesses > 0 && attempt != target) {
                char letter;
                cout << "Guess a letter: ";
                cin >> letter;
                if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos) {
                    cout << "You already guessed that. Try again.\n";
                    continue;
                }
                int loc = target.find(letter);
                if (loc == string::npos) {
                    cout << "Oh, bad guess!\n";
                    --guesses;
                    badchars += letter; // add to string
                } else {
                    cout << "Good guess!\n";
                    attempt[loc]=letter;
                    // check if letter appears again
                    loc = target.find(letter, loc + 1);
                    while (loc != string::npos) {
                        attempt[loc]=letter;
                        loc = target.find(letter, loc + 1);
                    }
                }
                cout << "Your word: " << attempt << endl;
                if (attempt != target) {
                    if (badchars.length() > 0)
                        cout << "Bad choices: " << badchars << endl;
                    cout << guesses << " bad guesses left\n";
                }
            }
            if (guesses > 0)
                cout << "That's right!\n";
            else
                cout << "Sorry, the word is " << target << ".\n";
            cout << "Will you play another? <y/n> ";
            cin >> play;
            play = tolower(play);
        }
    }

    cout << "Bye\n";
    system("pause");
    return 0;
}