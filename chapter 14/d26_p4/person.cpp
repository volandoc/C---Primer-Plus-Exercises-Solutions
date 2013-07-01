#include "person.h"

Card::Card(char st, int fc) {
    CheckAndSet(st, fc);
}

void Card::CheckAndSet(char st, int fc) { // check for valid arguments to set the card, if invalid, set suit to clubs, and face value to 1
    if ((tolower(st) != 'c') && (tolower(st) != 'd') && (tolower(st) != 'h') && (tolower(st) != 's')) {
        std::cout << "\nInvalid suit! The card is now set to clubs - c.";
        suit = 'c';
    } else
        suit = tolower(st);

    if ((fc < 1) || (fc > 13)) {
        std::cout << "\nInvalid face value! The new value of card is 1.";
        face = 1;
    } else
        face = fc;

}

std::string Card::getsuit() const { // return full string of suit based on first character of suit
    std::string tempstring;
    if (suit == 'c')
        tempstring = "Clubs";
    else if (suit == 'd')
        tempstring = "Diamonds";
    else if (suit == 'h')
        tempstring = "Hearts";
    else
        tempstring = "Spades";
    return tempstring;
}

void Person::Set() {
    std::cout << "\nEnter first name: ";
    (std::cin >> firstname).get();
    std::cout << "Enter last name: ";
    (std::cin >> lastname).get();
}

void Gunslinger::Show() const {
    Person::Show();
    std::cout << "\nDraw time: " << drawtime << std::endl;
    std::cout << "Gun notches: " << notches;
}

void Gunslinger::Set() {
    Person::Set();
    std::cout << "Enter draw time: ";
    (std::cin >> drawtime).get();
    std::cout << "Enter gun notches: ";
    (std::cin >> notches).get();
}

Card PokerPlayer::Draw() const { // returns a Card value with random face and suit values
    char tempst;

    int rndface = 1+int(13*rand()/(RAND_MAX + 1.0)); // generate Card face values, from 1 to 13
    int rndsuit = 1+int(4*rand()/(RAND_MAX + 1.0)); // generate suit value from 1 to 4: Hearts or Diamonds or Spades or Clubs

    switch(rndsuit) {
    case 1  :
        tempst = 'c';
        break;

    case 2  :
        tempst = 'd';
        break;

    case 3  :
        tempst = 'h';
        break;

    case 4  :
        tempst = 's';
        break;

    default :
        tempst = 'c';
    }

    return Card(tempst, rndface); // initialize and return card with random values
}

std::ostream & operator<<(std::ostream & os, const Person & p) { // friend functions to display First & Last for use with cout <<
    os << p.firstname << " " << p.lastname;
    return os;
}