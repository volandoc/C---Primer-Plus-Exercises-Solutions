/*
Write a program that uses the following functions:
Fill_array() takes as arguments the name of an array of double values and an array size. It prompts the user to enter double values to be entered in the array. It ceases taking input when the array is full or when the user enters non-numeric input, and it returns the actual number of entries.
Show_ array() takes as arguments the name of an array of double values and an array size and displays the contents of the array.
Reverse_ array()takes as arguments the name of an array of double values and an array size and reverses the order of the values stored in the array.
The program should use these functions to fill an array, show the array, reverse the array, show the array, reverse all but the first and last elements of the array, and then show the array.
*/

#include <iostream>

using namespace std;

int fill_array( double [], const int);
void show_array( const double [], const int);
void reverse_array( double [], const int);

const int ArrSize = 10;

int main () {

    double arr[ArrSize] = {};
    int my_arrsize = fill_array( arr, ArrSize );
    show_array(arr, my_arrsize);
    reverse_array(arr+1, my_arrsize-2); // reversing array without first and last element
    show_array(arr, my_arrsize);
    cout << endl;
    system("pause");
}

int fill_array(double ar[], const int limit) {
    double temp = 0;
    int i;
    for ( i = 0; i < limit; i++) {
        cout << "Enter double value of array: ";
        cin >> temp;
        if (!cin) {
            cin.clear();
            while ( cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        } else if ( temp < 0 )
            break;
        ar[i] = temp;
    }
    return i;
}
void show_array( const double ar[], const int limit) {
    int i;
    cout << "Showing content of array: ";
    for ( i = 0; i < limit; i++) {
        cout << ar[i] << " ";
    }
}
void reverse_array( double ar[], int limit ) {
    int i,j;
    double temp = 0;
    cout << "\nReversing array...\n";
    for ( i = 0, j = limit-1; i < j; i++, j--) {
        temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }
    cout << "Done!\n";
}