#include <iostream>
#include <string>
const int Len = 40;

class Golf {
private:
    char fullname_[Len];
    int handicap_;
public:
    // default constructor
    Golf(const char * fullname = (char *) (" "), int handicap = 0);

    // function displays contents of golf structure
    void showgolf() const;

    // interactive version:
    // function solicits name and handicap from user
    // and sets the members of g to the values entered
    // returns 1 if name is entered, 0 if name is empty string
    int setgolf();
    // function resets handicap to new value
    void set_handicap(int handicap);
};