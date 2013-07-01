#include <iostream>
#ifndef TV_H_
#define TV_H_
class Remote;
class Tv {
public:
    friend class Remote; // Remote can access Tv private parts
    enum {Off, On};
    enum {MinVal,MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, VCR};
    Tv(int s = Off, int mc = 100) : state(s), volume(5),
        maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {
        state = (state == On)? Off : On;
    }
    bool ison() const {
        return state == On;
    }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {
        mode = (mode == Antenna)? Cable : Antenna;
    }
    void set_input() {
        input = (input == TV)? VCR : TV;
    }
    void settings() const; // display all settings
    bool changeRmode(Remote & r);
private:
    int state; // on or off
    int volume; // assumed to be digitized
    int maxchannel; // maximum number of channels
    int channel; // current channel setting
    int mode; // broadcast or cable
    int input; // TV or VCR
};
class Remote {
private:
    int mode; // on or off
    int i_mode;
    enum {Normal, Interactive}; // Normal or Interactive mode
public:
    friend class Tv;
    Remote(int m = Tv::TV) : mode(m), i_mode(Normal) {}
    bool volup(Tv & t) {
        return t.volup();
    }
    bool voldown(Tv & t) {
        return t.voldown();
    }
    void onoff(Tv & t) {
        t.onoff();
    }
    void chanup(Tv & t) {
        t.chanup();
    }
    void chandown(Tv & t) {
        t.chandown();
    }
    void set_chan(Tv & t, int c) {
        t.channel = c;
    }
    void set_mode(Tv & t) {
        t.set_mode();
    }
    void set_input(Tv & t) {
        t.set_input();
    }
    void disp_mode() {
        std::cout << "Remote mode is " << (i_mode == Normal? "Normal.\n" : "Interactive.\n");
    }
};
#endif