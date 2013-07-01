/*
Do the same problem as described in Programming Exercise 4, except make it a template
function:
template
    int reduce(T ar[], int n);
Test the function in a short program, using both a long instantiation and a string
    instantiation.
*/

#include <iostream>
#include <algorithm>
#include <ostream>
#include <string>

using namespace std;

const int NUM = 18; // number of elements in original array
const int NUM2 = 9;

template <class T>
void display_array(T [], int n); // template used to display the contents of array T with n elements

template <class T>
int reduce(T [], int n); // reduce template for array of type T with n elements

int main() {
    long arr[NUM] = {1, 1, 2, 3, 45, 5, 4, 11, 45, 70, 9, 47, 48, 47, 73, 90, 11, 48}; // array of long(S)
    string city[NUM2] = {"new york", "washington", "philadelphia",
                         "new york", "miami", "washington", "tampa", "los angeles", "miami"
                        }; // array of strings

    cout << "Arr array: ";
    display_array(arr, NUM); // display contents of long array
    cout << "\nCities array: ";
    display_array(city, NUM2); // display contents of string array
    int arrNewNum = reduce(arr, NUM); // reduce long array and get the number of sorted & unique elements
    int cityNewNum = reduce(city, NUM2); // same reduce for string array
    cout << "\n\nArr after reduce: ";
    display_array(arr, arrNewNum); // display newly sorted long array
    cout << "Total unique Arr elements: " << arrNewNum; // display the number of new sorted & unique elements
    cout << "\n\nCities after reduce: ";
    display_array(city, cityNewNum); // display newly sorted string array
    cout << "Total unique City elements: " << cityNewNum; // display the number of new sorted & unique elements
    cout << "\n";
    system("pause");
    return 0;
}

template <class T>
int reduce(T ar[], int n) {
    sort(ar, ar + n); // sort the array
    return unique(ar, ar + n) - ar; // remove duplicate values and immediately return the # of elements of the newly unique and sorted array
}

template <class T>
void display_array(T ar[], int n) {
    for (int i = 0; i < n; i++) // go through every element of array
        cout << ar[i] << " "; // and display its contents
    cout << endl;
}