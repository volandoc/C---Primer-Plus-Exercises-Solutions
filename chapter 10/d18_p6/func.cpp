#include "header.h"

void Move::showmove() const { // shows current x, y values
    std::cout << "This object x = " << x_ << " and y = " << y_ << std::endl;
}
Move Move::add(const Move & m) {
    this->x_ += m.x_;
    this->y_ += m.y_;
    return * this;
}
// this function adds x of m to x of invoking object to get new x,
// adds y of m to y of invoking object to get new y, creates a new
// move object initialized to new x, y values and returns it
void Move::reset(double a, double b) { // resets x,y to a, b
    this->x_ = a;
    this->y_ = b;
    std::cout << "Object x and y reset.\n";
    this->showmove();
}