/*
Write a three-file program based on the following namespace:
namespace SALES
{
    const int QUARTERS = 4;
    struct Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };
    // copies the lesser of 4 or n items from the array ar
    // to the sales member of s and computes and stores the
    // average, maximum, and minimum values of the entered items;
    // remaining elements of sales, if any, set to 0
    void setSales(Sales & s, const double ar[], int n);
    // gathers sales for 4 quarters interactively, stores them
    // in the sales member of s and computes and stores the
    // average, maximum, and minimum values
    void setSales(Sales & s);
    // display all information in structure s
    void showSales(const Sales & s);
}

The first file should be a header file that contains the namespace.

The second file should be a source code file that extends the namespace to provide definitions for the three prototyped functions.

The third file should declare two Sales objects. It should use the interactive version of setSales() to provide values for one structure and the non-interactive version of setSales() to provide values for the second structure. It should display the contents of both structures by using showSales().
*/
#include <iostream>
#include "4_header.h"

using namespace SALES;
using std::cout;
using std::endl;
int main () {
    double ar[4] = {1.11, 2.22, 3.33, 4.44};
    Sales my_sales;
    setSales(my_sales, ar, 4);
    showSales(my_sales);
    cout << endl;

    Sales my_sales2;
    setSales(my_sales2);
    showSales(my_sales2);

    cout << endl;
    system("pause");
}