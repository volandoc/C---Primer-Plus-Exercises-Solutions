#include "tv.h"

bool Tv::volup() {
    if (volume < MaxVal) {
        volume++;
        return true;
    } else
        return false;
}

bool Tv::voldown() {
    if (volume > MinVal) {
        volume--;
        return true;
    } else
        return false;
}

void Tv::chanup() {
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown() {
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const {
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if (state == On) {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
             << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
             << (input == TV? "TV" : "VCR") << endl;
    }
}

bool Tv::changeRmode(Remote & r) {
    if (state == Off) {
        std::cout << "Tv is Off, remote mode cannot be changed!\n";
        return false;
    } else {
        r.i_mode = (r.i_mode == r.Normal)? r.Interactive: r.Normal;
        return true;
    }
}