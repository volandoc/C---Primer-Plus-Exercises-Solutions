/*
Begin with the following structure declaration:
struct chaff
{
    char dross[20];
    int slag;
};

Write a program that uses placement new to place an array of two such structures in a buffer. Then assign values to the structure members (remembering to use strcpy() for the char array) and use a loop to display the contents. Option 1 is to use a static array, like that in Listing 9.10, for the buffer. Option 2 is to use regular new to allocate the buffer.
*/

#include <iostream>
#include <new>
using namespace std;
struct chaff {
    char dross[20];
    int slag;
};
char buffer1[500];
const int n = 2; // array quantity
void show(const chaff & );

int main () {
    chaff * pd1;

    pd1 = new (buffer1) chaff [n];
    // variant 2

    // pd1 = new chaff [n];

    // end of variant 2
    strcpy(pd1[0].dross, "dross1");
    strcpy(pd1[1].dross, "dross2");
    pd1[0].slag = 10;
    pd1[1].slag = 11;

    for ( int i = 0; i < n; i++) {
        show(pd1[i]);
    }


    system("pause");
}

void show(const chaff & my_chaff) {
    cout << "Chaff dross: " << my_chaff.dross << ". Chaff slag: " << my_chaff.slag << endl;
}