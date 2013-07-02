#include <iostream>
using namespace std;

class complex {
private:
    double r_;
    double i_;

public:
    complex(double r = 0, double i = 0) {
        r_ = r;
        i_ =i;
    }
    void setReal(double r) {
        this->r_=r;
    };
    void setImaginary(double i) {
        this->i_=i;
    };
    friend ostream & operator << (ostream & os, const complex & co);
    friend istream & operator >> (istream & os, complex & co);
    friend complex operator + (const complex & co1, const complex & co2);
    friend complex operator - (const complex & co1, const complex & co2);
    friend complex operator * (const complex & co1, const complex & co2);
    friend complex operator * (const complex & co1, const  double n);
    friend complex operator * (const double n, const complex & co1) {
        return co1 * n;
    };
    friend complex operator ~ (const complex & co);
};