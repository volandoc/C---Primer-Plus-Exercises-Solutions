#include <iostream>
#include <string>
namespace SALES {
const int QUARTERS = 4;
class Sales {
private:
    double sales_[QUARTERS];
    double max_;
    double min_;
    double average_;
public:
    Sales();
    Sales(const double [], int n = 4);

    // display all information in structure s
    void showSales() const;

    // gathers sales for 4 quarters interactively, stores them
    // in the sales member of s and computes and stores the
    // average, maximum, and minimum values
    void setSales();

    // copies the lesser of 4 or n items from the array
    // to the sales member of s and computes and stores the
    // average, maximum, and minimum values of the entered items;
    // remaining elements of sales, if any, set to 0
    void setSales(const double [], int);
};
}