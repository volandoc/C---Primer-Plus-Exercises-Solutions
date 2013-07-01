/*
Rewrite the Stonewt class (Listings 11.16 and 11.17)
so that it has a state member that governs whether the object is interpreted in stone form,
integer pounds form, or floating-point pounds form. Overload the
<<operator to replace the show_stn() and show_lbs() methods.

Overload the addition, subtraction, and multiplication operators so that one can add, subtract, and multiply Stonewt values.

Test your class with a short program that uses all the class methods and friends.
*/

// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
using namespace std;
enum my_Mode {STONE, I_POUNDS, F_POUNDS};

class Stonewt {
public:
    enum Mode {STONE, I_POUNDS, F_POUNDS};
    // STONE for stone, I_POUNDS for integer pounds, F_POUNDS for float pounds
    enum {Lbs_per_stn = 14};      // pounds per stone
public:
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;
    Mode mode;// entire weight in pounds
public:
    Stonewt(double lbs, Mode mode = F_POUNDS);          // constructor for double pounds
    Stonewt(int stn, double lbs, Mode mode = STONE); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    /*
        void show_lbs() const;        // show weight in pounds format
        void show_stn() const;        // show weight in stone format
        */
    void setMode (Mode m);
    friend ostream & operator << (ostream & os, const Stonewt & st);
    friend Stonewt & operator + ( const Stonewt & st1, const Stonewt & st2 );
    friend Stonewt & operator - ( const Stonewt & st1, const Stonewt & st2 );
    friend Stonewt & operator * ( const Stonewt & st1, const double n );
    friend Stonewt & operator * ( const double n, const Stonewt & st1 ) {
        return st1 * n;
    };

};
#endif
