#include "stock2.h"
// constructors
Stock::Stock() { // default constructor
    company = new char [strlen("no name")+1];
    std::strcpy(company,"no name");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}
Stock::Stock(const char * co, int n, double pr) {
    company = new char[strlen(co)+1];
    std::strcpy(company,co);
    if (n < 0) {
        std::cerr << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    } else
        shares = n;

    share_val = pr;
    set_tot();
}

// copy constructor
Stock::Stock(const Stock & st) {
    company = new char[strlen(st.company)+1];
    std::strcpy(company,st.company);
    shares = st.shares;
    share_val = st.share_val;
    total_val = st.total_val;
    set_tot();
}

// assignment constructor
Stock & Stock::operator=(const Stock & st) {
    if (this == &st)
        return *this;
    delete [] company;
    company = new char[strlen(st.company)+1];
    std::strcpy(company,st.company);
    shares = st.shares;
    share_val = st.share_val;
    total_val = st.total_val;
    set_tot();
    return *this;
}

// class destructor
Stock::~Stock() { // quiet class destructor
    delete [] company;
}
// other methods
void Stock::buy(int num, double price) {
    if (num < 0) {
        std::cerr << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}
void Stock::sell(int num, double price) {
    using std::cerr;
    if (num < 0) {
        cerr << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    } else if (num > shares) {
        cerr << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}
void Stock::update(double price) {
    share_val = price;
    set_tot();
}

const Stock & Stock::topval(const Stock & s) const {
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}

std::ostream & operator<<(std::ostream & os, const Stock & s) {
    os << "Company: " << s.company
       << " Shares: " << s.shares << std::endl
       << " Share Price: $" << s.share_val
       << " Total Worth: $" << s.total_val << std::endl;
    return os;
}