// stonewt.cpp -- Stonewt methods
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs,  Mode my_mode) {
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode = my_mode;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, Mode my_mode) {
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn +lbs;
    mode = my_mode;
}

Stonewt::Stonewt() {        // default constructor, wt = 0
    stone = 0;
    pounds = pds_left = .0;
    mode = F_POUNDS;
}

Stonewt::~Stonewt() {       // destructor
}

void Stonewt::setMode (Mode m) {
    this->mode = m;
    /*    cout << "Mode " << m << endl;*/
}

ostream & operator << (ostream & os, const Stonewt & st) {
    if ( st.mode == Stonewt::STONE ) {
        os << st.stone << " stone, " << st.pds_left << " pounds\n";
    } else if ( st.mode == Stonewt::F_POUNDS ) {
        os << st.pounds << " pounds\n";
    } else if ( st.mode == Stonewt::I_POUNDS ) {
        os << (int) st.pounds << " full pounds\n";
    } else
        os << "\nSome horrible error!\n";
    return os;
}

Stonewt & operator + ( const Stonewt & st1, const Stonewt & st2 ) {
    double summ_pounds = st1.pounds + st2.pounds;
    double summ_stones = summ_pounds/st1.Lbs_per_stn;
    double summ_lbs_left = fmod(summ_pounds,st1.Lbs_per_stn);
    if (st1.mode == Stonewt::STONE) {
        Stonewt summ((int) summ_stones, summ_lbs_left);
        return  summ;
    } else if ( (st1.mode == I_POUNDS) || (st1.mode == F_POUNDS) ) {
        Stonewt summ(summ_pounds);
        return  summ;
    } else {
        cout << "OMG, some horrible error!\n";
    }
}

Stonewt & operator - ( const Stonewt & st1, const Stonewt & st2 ) {
    double summ_pounds = st1.pounds - st2.pounds;
    double summ_stones = summ_pounds/st1.Lbs_per_stn;
    double summ_lbs_left = fmod(summ_pounds,st1.Lbs_per_stn);
    if (st1.mode == Stonewt::STONE) {
        Stonewt summ((int) summ_stones, summ_lbs_left, Stonewt::STONE);
        return  summ;
    } else if ( (st1.mode == I_POUNDS) || (st1.mode == F_POUNDS) ) {
        Stonewt summ(summ_pounds, F_POUNDS);
        return  summ;
    } else {
        cout << "OMG, some horrible error!\n";
    }
}

Stonewt & operator * ( const Stonewt & st1, const double n ) {
    double summ_pounds = st1.pounds * n;
    double summ_stones = summ_pounds/st1.Lbs_per_stn;
    double summ_lbs_left = fmod(summ_pounds,st1.Lbs_per_stn);
    if (st1.mode == Stonewt::STONE) {
        Stonewt summ((int) summ_stones, summ_lbs_left, Stonewt::STONE);
        return  summ;
    } else if ( (st1.mode == I_POUNDS) || (st1.mode == F_POUNDS) ) {
        Stonewt summ(summ_pounds, F_POUNDS);
        return  summ;
    } else {
        cout << "OMG, some horrible error!\n";
    }
}