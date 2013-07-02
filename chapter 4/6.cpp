#include <iostream>
#include <string>

using namespace std;

int main () {
    /*
    The CandyBar structure contains three members, as described in Programming Exercise 5.
    Write a program that creates an array of three CandyBarstructures,
    initializes them to values of your choice,
    and then displays the contents of each structure.
    */
    struct CandyBar {
        string name;
        float weight;
        int calories;
    };

    CandyBar candy[3];
    candy[0].name = "Cheesecake";
    candy[0].weight = 1.5;
    candy[0].calories = 2000;

    candy[1].name = "Cookies";
    candy[1].weight = 0.25;
    candy[1].calories = 300;

    candy[2].name = "Ice cream";
    candy[2].weight = 0.5;
    candy[2].calories = 1100;

    cout << "CandyBar 1 name     = " << candy[0].name << endl
         << "CandyBar 1 weight   = " << candy[0].weight << endl
         << "CandyBar 1 calories = " << candy[0].calories << endl << endl;

    cout << "CandyBar 2 name     = " << candy[1].name << endl
         << "CandyBar 2 weight   = " << candy[1].weight << endl
         << "CandyBar 2 calories = " << candy[1].calories << endl << endl;


    cout << "CandyBar 3 name     = " << candy[2].name << endl
         << "CandyBar 3 weight   = " << candy[2].weight << endl
         << "CandyBar 3 calories = " << candy[2].calories << endl << endl;

    system ("pause");
}