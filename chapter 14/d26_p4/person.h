#include <iostream>
#include <string>
#include <cctype>
#include <ctime>

#ifndef PERSON_H_
#define PERSON_H_

class Card {
private:
    char suit; // card Suit
    int face; // card Face value
public:
    Card() : suit('c'), face(2) {} // initialize suit character to first letter of Suit, and face to int value
    Card(char st, int fc);
    std::string getsuit() const; // getsuit returns full string name of card suit
    int getface() const {
        return face;    // return int value of face with range of 1-13, 13 is Joker, or the highest value
    }
    void CheckAndSet(char st, int fc); // checks for validity of values and sets the card to those values
};

class Person {
private:
    std::string firstname; // first
    std::string lastname; // last
public:
    Person(std::string fn = "not first", std::string ln = "not last") : firstname(fn), lastname(ln) {}
    virtual void Show() const {
        std::cout << firstname << " " << lastname;   // display first & last names
    }
    virtual void Set();
    virtual ~Person() {}
    friend std::ostream & operator<<(std::ostream & os, const Person & p); // friend, display first & last names, used for cout <<
};

class Gunslinger : virtual public Person {
private:
    double drawtime;
    int notches;
public:
    Gunslinger(std::string fn = "gun", std::string ln = "slinger", double drt = 1.0, int nchs = 6) : Person(fn, ln), drawtime(drt), notches(nchs) {}
    Gunslinger(const Person & ps, double drt = 1.0, int nchs = 6) : Person(ps), drawtime(drt), notches(nchs) {}
    virtual double Draw() const {
        return drawtime;    // returns drawtime
    }
    virtual void Show() const;
    virtual void Set();
    virtual ~Gunslinger() {}
};

class PokerPlayer : virtual public Person {
public:
    PokerPlayer(std::string fn = "poker", std::string ln = "player") : Person(fn, ln) {}
    PokerPlayer(const Person & ps) : Person(ps) {}
    virtual Card Draw() const; // returns Card with random face and suit values
    virtual ~PokerPlayer() {}
};

class BadDude : public Gunslinger, public PokerPlayer {
public:
    BadDude(std::string fn = "bad", std::string ln = "dude", double drt = 2.0, int nchs = 5) : Person(fn, ln), Gunslinger(fn, ln, drt, nchs), PokerPlayer(fn, ln) {}
    BadDude(const Person & ps, double drt, int nchs) : Person(ps), Gunslinger(ps,drt,nchs), PokerPlayer(ps) {}
    BadDude(Gunslinger & gs) : Gunslinger(gs) {}
    virtual double Gdraw() const {
        return Gunslinger::Draw();    // returns drawtime, not to confuse with Cdraw() method
    }
    virtual Card Cdraw() const {
        return PokerPlayer::Draw();    // returns Card with random values (suit + face)
    }
    virtual void Show() const {
        Gunslinger::Show();
    }
    virtual void Set() {
        Gunslinger::Set();
    }
};

#endif