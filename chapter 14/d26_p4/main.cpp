/*
A Person class holds the first name and the last name of a person.
In addition to its constructors, it has a Show() method that displays both names.
A Gunslinger class derives virtually from the Person class.
It has a Draw() member that returns a type double value representing a gunslinger's draw time.
The class also has an int member representing the number of notches on a gunslinger's gun.
Finally, it has a Show() function that displays all this information.

A PokerPlayer class derives virtually from the Person class.
It has a Draw() member that returns a random number in the range 1 through 52, representing a card value.
(Optionally, you could define a Card class with suit and face value members and use a Card return value for Draw().)
The PokerPlayer class uses the Person show() function.

The BadDude class derives publicly from the Gunslinger and PokerPlayer classes.
It has a Gdraw() member that returns a bad dude's draw time and a Cdraw() member that returns the next card drawn. It has an appropriate Show() function.
Define all these classes and methods, along with any other necessary methods (such as methods for setting object values) and test them in a simple program similar to that in Listing 14.12.
*/
#include "person.h"

const int SIZE = 4;

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;
    std::srand(unsigned(std::time(0)));

    Person pn = Person("Guest", "Danny");
    Gunslinger gs = Gunslinger("Gunslinger", "Jim",(1+int(8*rand()/(RAND_MAX + 1.0))),5); // Gunslinger's drawtime is random
    PokerPlayer pp = PokerPlayer("Poker player", "Mike");
    BadDude bd = BadDude("Bad Dude", "Tom",(1+int(8*rand()/(RAND_MAX + 1.0))),6); // Bad Dude's drawtime is random

    Person * inSaloon[SIZE] = {&pn, &gs, &pp, &bd}; // array of pointers to Person based classes
    int i;


    cout << "Today's visitors in Saloon: " << endl;
    for (i = 0; i < SIZE; i++) {
        cout << "\nVisitor #" << i+1 << ": ";
        inSaloon[i]->Show(); // display all visitors using their own Show() method
        cout << endl;
    }

    // The game between two classes that have method to draw a Card
    Card ppCard;  // Poker player's card
    Card bdCard;  // Bad Dude's card
    std::string ppSUIT = "p"; // Poker Player's card suit, initially set to random value non-equal to that of Bad Dude's suit, for loop purposes
    std::string bdSUIT = "d"; // Bad Dude's initial card suit
    int ppWINS = 0; // total # of wins for Poker Player
    int bdWINS = 0; // and same for Bad Dude
    int Draw = 0; // total number of Draws
    int cashPRIZE = 0; // cash prize for the poker game

    cout << "\n*--- THE POKER GAME BETWEEN [" << pp << "] AND [" << bd << "] BEGINS! ---*";  // the game intro text
    cout << "\nGame rounds: " << SIZE << endl; // total game rounds = SIZE
    for (i = 0; i < SIZE; i++) {
        cout << "\nRound " << i+1;
        while (ppSUIT != bdSUIT) { // draw cards until Poker players and Bad Dude's card suit match each other, like Diamonds = Diamonds
            cashPRIZE += 10; // increase cash prize of game  with every card drawing loop, + $10
            ppCard = pp.Draw(); // get Poker Player's drawn card
            bdCard = bd.Cdraw(); // get Bad Dude's drawn card
            ppSUIT = ppCard.getsuit(); // get the suit
            bdSUIT = bdCard.getsuit();
            cout << "\nPP's card: " << ppSUIT << ", " << ppCard.getface() << ". BD's card: " << bdSUIT << ", " << bdCard.getface(); // display drawn cards info
            cout << "\nCash prize: $" << cashPRIZE; // currenct cash prize info
        }
        cout << "\n\n=== Suit MATCH! Comparing face values: ===\n";
        cout << pp << " drew: " << ppSUIT << ", " << ppCard.getface() << endl;// display card values at round end when suits match each other
        cout << bd << " drew: " << bdSUIT << ", " << bdCard.getface() << endl; // same here for Bad Dude
        if (ppCard.getface() > bdCard.getface()) { // compare card face values, round is won if face value is bigger
            cout << pp << " Wins!" << endl; // if face value of Poker Player is bigger, he wins
            ppWINS++;

        } else if (ppCard.getface() < bdCard.getface()) { // if face value of Bad Dude's card is bigger, he wins
            cout << bd << " Wins!" << endl;
            bdWINS++;
        } else {
            cout << "It's a DRAW!" << endl; // otherwise it's a draw
            Draw++;
            cashPRIZE -= 10; // for each draw, $10 is withdrawn from total cash prize
        }

        ppSUIT = "p"; // reset SUIT loop values needed for the generation of new card values
        bdSUIT = "d";
    }

    cout << "\n === THE GAME ENDED! ==" << endl; // after all rounds display the totals
    cout << pp << " won " << ppWINS << " time(s)!" << endl;
    cout << bd << " won " << bdWINS << " time(s)!" << endl;
    cout << "Draw: " << Draw << " time(s)!" << endl;
    if (bdWINS > ppWINS) // Who won the most times get the total cash prize
        cout << bd << " walked away with cash prize of $" << cashPRIZE << endl; // if Bad Dude wins, he takes all money and freely leaves the bar
    else if (bdWINS == ppWINS)
        cout << "It's a draw, two players won equal amount of games, everyone keeps their money!"; // if nobody wins, everyone keeps their money
    else {
        cout << pp << " won the cash prize of $" << cashPRIZE << endl;
        cout << "... however, " << bd << " is bitter and won't let him get the money....!!!"; // if Poker Player wins, Bad Dude being a bad dude, uses gun to get the cash prize
        cout << "\n...then " << gs << " comes to rescue and starts a duel with " << bd << endl;// here Gunslinger comes to rescues and starts a duel with Bad Dude

        if (gs.Draw() < bd.Gdraw()) // if Gunslinger drew faster (drawtime is less) then he gets Bad Dude on the run
            cout << gs << " drew gun faster and forced " << bd << " to flee.";
        else if (gs.Draw() > bd.Gdraw()) // if Bad Dude drew gun faster, Gunslinger is shot and Bad Dude gets the money
            cout << bd << " drew gun faster and shot the Gunslinger, then took all cash prize money and ran away.";
        else // otherwise, they shoot and injure each other, while Poker Player leaves the saloon with money to avoid further trouble
            cout << gs << " and " << bd << " drew guns at same time and shot each other. Cash prize is left with winner of game.";
    }

    system("pause");
    return 0;
}