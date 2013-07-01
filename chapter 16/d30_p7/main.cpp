/*
A common game is the lottery card.
The card has numbered spots of which a certain number are selected at random.
Write a Lotto() function that takes two arguments.
The first should be the number of spots on a lottery card, and the second should be the number of spots selected at random.
The function should return a vector object that contains, in sorted order, the numbers selected at random.

For example, you could use the function as follows:
vector winners;
winners = Lotto(51,6);

This would assign to winners a vector that contains six numbers selected randomly from the range 1 through 51.
Note that simply using rand() doesn't quite do the job because it may produce duplicate values.
Suggestion: Have the function create a vector that contains all the possible values, use random_shuffle(), and then use the beginning of the shuffled vector to obtain the values.
Also write a short program that lets you test the function.
*/

#include <iostream>
#include <vector>         // include vector for vector template
#include <algorithm>      // include algorithm header to use with sort, random_shuffle, and find STL functions

using namespace std;

typedef vector<int> Ticket;       // Ticket is now vector<int> for ease of use, holds lottery numbers (array)

Ticket Lotto(int, int);     // function returns vector<int> (or Ticket), first int argument is a max range (from 1 to max range) to draw Lottery numbers, and second int argument is how many spots or numbers to guess to win the lotto
void DisplayTicket(const Ticket &); // display ticket or vector<int> array

int main() {

    int lotMaxR, winN, matchingN = 0; // lotMaxR = max range number for lottery numbers to be drawn, from 1 to lotMaxR

    do {
        cout << "Enter lottery range, from 1 to (5 or greater): "; // ask to input maximum range of possible lottery draw number
    } while(cin >> lotMaxR && lotMaxR < 5); // get proper number from user until 5 or more is entered

    do {
        cout << "Enter how many numbers to draw (2 or greater): "; // ask for how many spots on the lotto card or winning numbers to draw in lottery play
    } while(cin >> winN && winN < 2);  // ask for input until 2 or number is entered

    Ticket winners = Lotto(lotMaxR,winN); // generate random numbers  for winning numbers
    Ticket myticket = Lotto(lotMaxR,winN); // generate random numbers for user's playing ticket, something like QuickPick

    cout << "Winning numbers: ";
    DisplayTicket(winners); // display winning numbers
    cout << "Your ticket numbers: ";
    DisplayTicket(myticket); // display playing user's numbers

    cout << "Number(s) matched on your ticket: "; // display matching numbers from both arrays (lottery drawn numbers and user's quick pick)
    for (int i = 0; i < winN; i++)
        if (find(winners.begin(), winners.end(), myticket[i]) != winners.end()) { // compare each winning number to user's picked numbers
            cout << myticket[i] << " "; // if matched, display the number
            matchingN++; // and increase the number of matched numbers
        }

        if (matchingN == 0) // if no numbers were matched display the message
            cout << "None" << endl;
        else
            cout << endl;

        if (matchingN == winN && matchingN > 5) // if all winning numbers guessed correctly and the total number of them is 6 or more - almost impossible win, display epic congratulations message!
            cout << "You've guessed all numbers!!! BEER IS ON ME!";
        else if (matchingN == winN && matchingN == 2 ) // special occasion: if out of 2 winning numbers 2 guessed correctly, display FREE ticket prize msg
            cout << "Congratulations, you've won min 2x2 game! Prize: 10 FREE tickets!" << endl;
        else if (matchingN > 5) // display messages for each number of correctly guessed numbers, the greater the number the more fun and expensive prize....or maybe not :)
            cout << "Congratulations, You've guessed " << matchingN << " winning numbers!!!" << endl;
        else
            switch(matchingN) {
            case 5:
                cout << "Congratilations, You've guessed 5 winning numbers!!!!" << endl;
                break;

            case 4:
                cout << "Congratulations, You've guessed 4 winning numbers!!" << endl;
                break;

            case 3:
                cout << "Congratulations, You've guessed 3 winning numbers!!" << endl;
                break;

            default:
                cout << "You've guessed " << matchingN << " winning number(s)!!" << endl;
                break;
        }

        cout << "\nBye!\n"; // all is done, good bye
        system("pause");
        return 0;
}

Ticket Lotto(int Tot, int Ran) { // generate and return randomized & sorted array of lottery numbers
    Ticket temp; // create a ticket that will be returned once generated with random lottery numbers with respect to arguments passed to function
    int i = 0;

    if (Tot < 5) { // check for the first argument passed to function
        cout << "Invalid number range, resetting to default: [1-5]" << endl; // if range of lottery number max is below 5, change it to min allowed - 5
        Tot = 5;
    }

    if (Ran < 2) { // check the second argument, if less than 2, set it to default value of 2, we need at least 2 winning numbers to play with
        cout << "Invalid ticket request, setting number of winning numbers to default - 2." << endl;
        Ran = 2;
    }

    for (i = 0; i < Tot; i++) // generate non-random sequence of numbers from 1 to Tot and store it in vector<int> array
        temp.push_back(i+1);

    for (i = 0; i < Ran; i++) // shuffle the numbers "Ran" many times to have better randomization of numbers
        random_shuffle(temp.begin(), temp.end());

    temp.erase(temp.begin()+Ran, temp.end()); // erase unnecessary numbers from Ran+, numbers from 1 to Ran are kept in.
    sort(temp.begin(), temp.end()); // finally, sort the numbers

    return temp; // and return the sorted and randomized array
}

void DisplayTicket(const Ticket & t) { // function displays victor<int> array or defined as Ticket
    for (int i = 0; i < t.size(); i++) // go through each element until t.size(), the max number of elements, is reached
        cout << t[i] << " "; // display the element
    cout << endl;
}