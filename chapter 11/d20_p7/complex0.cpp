#include "complex0.h"

ostream & operator << (ostream & os, const complex & co) {
    os << "(" << co.r_ << ", " << co.i_ << "i)";
    return os;
}

istream & operator >> (istream & os, complex & co) {
    using std::cin;
    using std::cout;
    double real, imaginary;
    cout << "real: ";
    cin >> real;
    cout << "imaginary: ";
    cin >> imaginary;
    co.setReal(real);
    co.setImaginary(imaginary);
    return os;
}

complex operator + (const complex & co1, const complex & co2) { //Addition: a + c = (A + C,(B + D)i)
    complex add(co1.r_+co2.r_, co1.i_+co2.i_);
    return add;
}

complex operator - (const complex & co1, const complex & co2) { //Subtraction: a - c = (A - C,(B - D)i)
    complex subs(co1.r_-co2.r_, co1.i_-co2.i_);
    return subs;
}

complex operator * (const complex & co1, const complex & co2) { //Multiplication: a ×c = (A ×C - B×D,(A×D + B×C)i)
    complex mult( (co1.r_ * co2.r_ - co1.i_ * co2.i_) , (co1.r_ * co2.i_ + co1.i_ * co2.r_));
    return mult;
}

complex operator * (const complex & co1, const  double n) {   //Multiplication: (x a real number):x ×c = (x×C,x×Di)
    complex mult( co1.r_ * n , co1.i_ * n );
    return mult;
}

complex operator ~ (const complex & co) {                       //Conjugation: ~a = (A,- Bi)
    complex conj( co.r_ , -co.i_ );
    return conj;
}