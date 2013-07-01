/*
Modify the Tv and Remote classes as follows:
    a. Make them mutual friends.
    b. Add a state variable member to the Remote class that describes whether the remote
    control is in normal or interactive mode.
    c. Add a Remote method that displays the mode.
    d. Provide the Tv class with a method for toggling the new Remote member. This
    method should work only if the TV is in the on state.
    Write a short program that tests these new features.
*/

#include "tv.h"

int main() {
    using namespace std;
    Tv s27;
    cout << "Initial settings for 27\"TV: \n";
    s27.settings();

    Remote red;
    red.disp_mode();

    s27.changeRmode(red);
    s27.onoff();
    s27.settings();
    s27.changeRmode(red);
    red.disp_mode();
    red.onoff(s27);
    s27.changeRmode(red);

    red.onoff(s27);
    s27.changeRmode(red);
    red.disp_mode();

    system("pause");
    return 0;
}