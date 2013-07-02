/*
Write a template function max5()
that takes a sits argument an array of five items of type T
and returns the largest item in the array.
(Because the size is fixed, it can be hard-coded into the loop instead of being passed as an argument.)

Test it in a program that uses the function with an array of five int value and an array of five double values.
*/

#include <iostream>
using namespace std;

template <typename T>
T max_func(const T a[5]) {
    T my_max = 0;
    for (int i = 0; i < 5; i++) {
        if (a[i] > my_max)
            my_max = a[i];
    }
    return my_max;
}

int main() {
    int my_int[5] = { 1, 2, 3, 4, 5 };
    double my_double[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    cout << max_func(my_int) << endl;
    cout << max_func(my_double) << endl;
    system("pause");
    return 0;
}

