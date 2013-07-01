#include "vintage.h"

VintagePort::VintagePort() : Port("none","vintage",0) {
    nickname = new char [std::strlen("nonick")+1];
    std::strcpy(nickname,"nonick");
    year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br,"vintage",b) {
    nickname = new char [std::strlen(nn)+1];
    std::strcpy(nickname,nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp) {
    nickname = new char [std::strlen(vp.nickname)+1];
    std::strcpy(nickname,vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator =(const VintagePort & vp) {
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char [std::strlen(vp.nickname)+1];
    std::strcpy(nickname,vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const {
    std::cout << "\nNickname: " << nickname;
    std::cout << "\nYear: " << year;
    Port::Show();
}

std::ostream & operator<<(ostream & os, const VintagePort & vp) {
    os << vp.nickname << ", " << vp.year << ", ";
    os << (const Port &) vp;
    return os;
}