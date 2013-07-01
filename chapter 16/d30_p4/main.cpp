/*
Write a function with an old-style interface that has this prototype:
int reduce(long ar[], int n);
The actual arguments should be the name of an array and the number of elements in the array.
The function should sort an array, remove duplicate values, and return a value equal to the number of elements in the reduced array. Write the function using STL functions.
(If you decide to use the general unique() function, note that it returns the end of the resulting range.)
Test the function in a short program.
*/

#include <iostream>
#include <algorithm>
#include <ostream>

using namespace std;

const int NUM = 18; // number of elements in original array
int reduce(long [], int); // prototype of reduce function

int main() {
    long arr[NUM] = {1, 1, 2, 3, 45, 5, 4, 11, 45, 70, 9, 47, 48, 47, 73, 90, 11, 48};

    int i = 0;

    for (i = 0; i < NUM; i++) // display the contents of original array
        cout << arr[i] << " ";
    int newNUM = reduce(arr, NUM); // reduce array and store the number of new sequence elements into variable
    cout << "\nNumber of elements in arr[] after reduce: " << newNUM << endl; // disp the info
    cout << "Array after sort & duplicates removal: "; // display sorted & unique original array
    for (i = 0; i < newNUM; i++) // dupe values are still in array after newNUM but not displayed, STL functions such as erase can be used with list or vector list if needed
        cout << arr[i] << " ";
    cout << "\n";

    system("pause");
    return 0;
}

int reduce(long ar[], int n) {
    sort(ar, ar + n); // sort the array
    return unique(ar, ar + n) - ar; // remove duplicate values and immediately return the # of elements of the newly unique and sorted array
}