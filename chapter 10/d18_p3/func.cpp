#include "header.h"


    Golf::Golf(const char * fullname , int handicap)
    {
        std::cout << "\nUsing default constructor.\n";
        strcpy_s(fullname_, fullname);
        handicap_ = handicap;
        std::cout << "Initialization done.\n";
/*        std::cout << fullname_ << " " << handicap_ << std::endl; //test string*/

    }

    // function displays contents of golf structure
    void Golf::showgolf() const
    {
        if ( fullname_[0] == ' ' || fullname_[0] == '\0') // not fully clear check, if user enters whitespace and then name - input terminates
            std::cout << "No data for this player.\n";
        else
        {
            std::cout << this->fullname_ << " handicap is " << this->handicap_ << " points.\n";
        }
    }

// interactive version:
// function solicits name and handicap from user
// and sets the members of g to the values entered
// returns 1 if name is entered, 0 if name is empty string
int Golf::setgolf()
{
    int hc;
    std::cout << "Please, enter player name: ";
    std::cin.getline(this->fullname_, Len);
    if ( this->fullname_[0] == ' ' || this->fullname_[0] == '\0') // not fully clear check, if user enters whitespace and then name - input terminates
    {
        std::cout << "Empty string, data input terminated.\n";
        return 0;
    }
    else
    {
        std::cout << "Please, enter player handicap: ";
        std::cin >> this->handicap_;

        std::cout << "You entered: " << this->fullname_ << " " << this->handicap_ << std::endl;
        return 1;
    }
    std::cout << "Some bad error!";
    return 0;
}

// function resets handicap to new value
void Golf::set_handicap(int handicap)
{
    this->handicap_ = handicap;
    std::cout << "\nDone function handicap.\n";
    std::cout << "New " << this->fullname_ << " handicap: "<< this->handicap_ << std::endl;
}