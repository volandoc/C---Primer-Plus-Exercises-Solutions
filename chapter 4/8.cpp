#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main () {
    /*
    Part 2 of previous project.
    William Wingate runs a pizza-analysis service.
    For each pizza, he needs to record the following information:
    The name of the pizza company, which can consist of more than one word
    The diameter of the pizza
    The weight of the pizza

    Devise a structure that can hold this information
    and write a program that uses a structure variable of that type.

    The program should ask the user to enter each of the preceding items of information,
    and then the program should display that information.
    Use cin(or its methods) and cout.

    Do Programming Exercise 7 but use new to allocate a structure instead of declaring a structure variable.
    Also have the program request the pizza diameter before it requests the pizza company name.
    */
    struct pizza {
        char name[250];
        float diameter;
        float weight;
    };

    pizza * newpizza = new pizza;
    cout << "Enter pizza diameter = ";
    cin >> newpizza->diameter;
    cin.get();
    cout << "Enter pizza company name = ";
    cin.getline(newpizza->name, 250);
    cout << "Enter pizza weight = ";
    cin >> newpizza->weight;
    cout << endl;

    cout << "Pizza company name     = " << newpizza->name << endl
         << "Pizza company diameter = " << newpizza->diameter << endl
         << "Pizza company weight   = " << newpizza->weight << endl << endl;

    system ("pause");
}