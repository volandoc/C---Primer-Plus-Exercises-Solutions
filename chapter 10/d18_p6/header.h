#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

class Move {
private:
    double x_;
    double y_;
public:
    Move(double a = 0, double b = 0) {
        x_ = a;
        y_ = b;
    }; // sets x, y to a, b
    void showmove() const; // shows current x, y values
    Move add(const Move & m);
    // this function adds x of m to x of invoking object to get new x,
    // adds y of m to y of invoking object to get new y, creates a new
    // move object initialized to new x, y values and returns it
    void reset(double a = 0, double b = 0); // resets x,y to a, b
};