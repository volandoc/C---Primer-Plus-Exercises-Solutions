/*
The Benevolent Order of Programmers maintains a collection of bottled port. To describe it, the BOP Portmaster has devised a Port class, as declared here:

#include <iostream>
using namespace std;
class Port
{
private:
    char * brand;
    char style[20]; // i.e., tawny, ruby, vintage
    int bottles;
public:
    Port(const char * br = "none", const char * st = "none", int b = 0);
    Port(const Port & p); // copy constructor
    virtual ~Port() { delete [] brand; }
    Port & operator=(const Port & p);
    Port & operator+=(int b); // adds b to bottles
    Port & operator-=(int b); // subtracts b from bottles, if available
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend ostream & operator<<(ostream & os, const Port & p);
};


TheShow() method presents information in the following format:
Brand: Gallo
Kind: tawny
Bottles: 20

The operator<<() function presents information in the following format (with no newline character at the end):
Gallo, tawny, 20

The Port master completed the method definitions for the Port class and then derived the VintagePort class as follows before being relieved of his position for accidentally routing a bottle of '45 Cockburn' to someone preparing an experimental barbecue sauce:

       class VintagePort : public Port // style necessarily = "vintage"
       {
       private:
           char * nickname; // i.e., "The Noble" or "Old Velvet", etc.
           int year; // vintage year
       public:
           VintagePort();
           VintagePort(const char * br, int b, const char * nn, int y);
           VintagePort(const VintagePort & vp);
           ~VintagePort() { delete [] nickname; }
           VintagePort & operator=(const VintagePort & vp);

           void Show() const;
           friend ostream & operator<<(ostream & os, const VintagePort & vp);
       };


       You get the job of completing the VintagePort work.
           a. Your first task is to recreate the Port method definitions because the former Portmaster immolated his upon being relieved.
           b. Your second task is to explain why certain methods are redefined and others are not.
           c. Your third task is to explain why operator=() and operator<<()are not	virtual.
           d. Your fourth task is to provide definitions for the VintagePort methods.
*/

#include <iostream>
#include "port.h"
#include "vintage.h"

int main() {
    using namespace std;

    Port sample1;
    Port sample2("Kings","Bright",30);
    Port sample3("NewOne","DarkRed",15);
    VintagePort sample4("Valley",10,"Family",1957);
    Port sample5(sample4);

    sample4 += 10;
    sample3 -= 5;
    sample1 = sample5;

    Port * pts[5] = {&sample1,&sample2,&sample3,&sample4,&sample5};

    for (int i = 0; i < 5; i++) {
        cout << "Sample#" << i+1 << ":" << endl;
        pts[i]->Show();
        cout << endl << endl;
    }

    cout << endl;
    VintagePort sample6("BlueCastle",20,"NewType",1920);

    cout << sample2 << endl;
    cout << sample6 << endl;

    cout << "\nBottle counts:\n";
    for (int i = 0; i < 5; i++)
        cout << "Sample #" << i + 1 << ": " << pts[i]->BottleCount() << " bottles " << endl;

    system("pause");
    return 0;
}