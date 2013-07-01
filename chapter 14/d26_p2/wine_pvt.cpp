#include "wine_pvt.h"

Wine::Wine() : std::string("empty"), years(0), PairArray(ArrayInt(), ArrayInt()) {
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : std::string(l), years(y), PairArray(ArrayInt(yr,y), ArrayInt(bot,y)) {
}

Wine::Wine(const char * l, int y) : std::string(l), years(y), PairArray(ArrayInt(0,y), ArrayInt(0,y)) {
}

void Wine::GetBottles() {
    if (years < 1)
        std::cout << "\nNo years to enter data for or invalid number!";
    else {
        std::cout << "Enter " << (const std::string)(*this) << " data for " << years << " year(s): " << std::endl;
        for (int i = 0; i < years; i++) {
            std::cout << "Enter year: ";
            (std::cin >> PairArray::first()[i]).get();
            std::cout << "Enter bottles for that year: ";
            (std::cin >> PairArray::second()[i]).get();
        }
    }
}

void Wine::Show() const {
    using namespace std;
    cout << "\nWine: " << (const std::string)(*this) << endl;
    cout << "\tYear";
    cout << "\tBottles" << endl;
    for (int i = 0; i < years; i++)
        cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i] << endl;

}