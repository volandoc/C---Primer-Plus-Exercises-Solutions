/*
Write a template function maxn() that takes as its arguments an array of items of type T and an integer representing the number of elements in the array and that returns the largest item in the array.

Test it in a program that uses the function template with an array of six int value and an array of four double values.

The program should also include a specialization that takes an array of pointers-to-char as an argument and the number of pointers as a second argument and that returns the address of the longest string.

If multiple strings are tied for having the longest length, the function should return the address of the first one tied for longest.

Test the specialization with an array of five string pointers.
*/

#include <iostream>
#include <cstring>
using namespace std;

template <typename T> T maxn(T a[],const int counter) {
    T my_max = a[0];
    for (int i = 0; i < counter; i++) {
        if (a[i] > my_max)
            my_max = a[i];
    }
    return my_max;
}
template <> char * maxn <char *>(char * a[], const int counter) {
    char * my_max = a[0];
    for (int i = 1; i < counter; i++) {
        if (strlen(a[i]) > strlen(my_max))
            my_max = a[i];
    }
    return my_max;
}

int main() {
    char * str[5] = {"1", "2100", "5", "7", "300"};
    int my_int[6] = { 1, 2, 3, 4, 5, 6 };
    double my_double[4] = { 1.1, 2.2, 3.3, 4.4 };
    cout << maxn(my_int, 6) << endl;
    cout << maxn(my_double, 4) << endl;
    cout << maxn(str, 5) << endl;

    system("pause");
    return 0;
}

