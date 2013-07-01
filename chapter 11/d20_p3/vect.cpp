// vect.cpp -- methods for the Vector class
#include <cmath>
#include "vect.h"   // includes <iostream>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
// compute degrees in one radian
const double Rad_to_deg = 45.0 / atan(1.0);
// should be about 57.2957795130823

// private methods
// calculates magnitude from x and y

// set x from polar coordinate
void Vector::set_x(double mag, double ang) {
    if (mode == RECT)
        x_ = mag;
    else if (mode == POL)
        x_ = mag * cos(ang);
    else {
        cout << "Incorrect 3rd argument to Vector() -- ";
        cout << "vector set to 0\n";
        x_ = y_ = 0.0;
        mode = RECT;
    }
}

// set y from polar coordinate
void Vector::set_y(double mag, double ang) {
    if (mode == RECT)
        y_ = mag;
    else if (mode == POL)
        y_ = mag * sin(ang);
    else {
        cout << "Incorrect 3rd argument to Vector() -- ";
        cout << "vector set to 0\n";
        x_ = y_ = 0.0;
        mode = RECT;
    }
}

// public methods
Vector::Vector() {           // default constructor
    x_ = y_ = 0.0;
    mode = RECT;
}

// construct vector from rectangular coordinates if form is r
// (the default) or else from polar coordinates if form is p
Vector::Vector(double n1, double n2, Mode form) {
    mode = form;
    if (form == RECT) {
        x_ = n1;
        y_ = n2;
    } else if (form == POL) {
        set_x(n1, n2);
        set_y(n1, n2);
    } else {
        cout << "Incorrect 3rd argument to Vector() -- ";
        cout << "vector set to 0\n";
        x_ = y_ = 0.0;
        mode = RECT;
    }
}

// reset vector from rectangular coordinates if form is
// RECT (the default) or else from polar coordinates if
// form is POL
void Vector:: reset(double n1, double n2, Mode form) {
    mode = form;
    if (form == RECT) {
        x_ = n1;
        y_ = n2;
    } else if (form == POL) {
        set_x(n1, n2);
        set_y(n1, n2);
    } else {
        cout << "Incorrect 3rd argument to Vector() -- ";
        cout << "vector set to 0\n";
        x_ = y_ = 0.0;
        mode = RECT;
    }
}

Vector::~Vector() {  // destructor
}

void Vector::polar_mode() {  // set to polar mode
    mode = POL;
}

void Vector::rect_mode() {   // set to rectangular mode
    mode = RECT;
}

// operator overloading
// add two Vectors
Vector Vector::operator+(const Vector & b) const {
    return Vector(x_ + b.x_, y_ + b.y_);
}

// subtract Vector b from a
Vector Vector::operator-(const Vector & b) const {
    return Vector(x_ - b.x_, y_ - b.y_);
}

// reverse sign of Vector
Vector Vector::operator-() const {
    return Vector(-x_, -y_);
}

// multiply vector by n
Vector Vector::operator*(double n) const {
    return Vector(n * x_, n * y_);
}

// friend methods
// multiply n by Vector a
Vector operator*(double n, const Vector & a) {
    return a * n;
}

// display rectangular coordinates if mode is RECT,
// else display polar coordinates if mode is POL
std::ostream & operator<<(std::ostream & os, const Vector & v) {
    if (v.mode == Vector::RECT)
        os << "(x,y) = (" << v.x_ << ", " << v.y_ << ")";
    else if (v.mode == Vector::POL) {
        os << "(m,a) = (" << v.magval() << ", "
           << v.angval() * Rad_to_deg << ")";
    } else
        os << "Vector object mode is invalid";
    return os;
}

double Vector::magval() const { // report magnitude
    return sqrt(x_ * x_ + y_ * y_);
}
double Vector::angval() const { // report angle
    if (x_ == 0.0 && y_ == 0.0)
        return 0.0;
    else
        return atan2(y_, x_);
}
}  // end namespace VECTOR
