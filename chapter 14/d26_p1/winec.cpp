#include "winec.h"

Wine::Wine() : winelabel("empty"), years(0), bt(ArrayInt(), ArrayInt()) {
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : winelabel(l), years(y), bt(ArrayInt(yr,y), ArrayInt(bot,y)) {
}

Wine::Wine(const char * l, int y) : winelabel(l), years(y), bt(ArrayInt(0,y), ArrayInt(0,y)) {
}

void Wine::GetBottles() {
    if (years < 1)
        std::cout << "\nNo years to enter data for or invalid number!";
    else {
        std::cout << "Enter " << winelabel << " data for " << years << " year(s): " << std::endl;
        for (int i = 0; i < years; i++) {
            std::cout << "Enter year: ";
            (std::cin >> bt.first()[i]).get();
            std::cout << "Enter bottles for that year: ";
            (std::cin >> bt.second()[i]).get();
        }
    }
}

void Wine::Show() const {
    using namespace std;
    cout << "\nWine: " << winelabel << endl;
    cout << "\tYear";
    cout << "\tBottles" << endl;
    for (int i = 0; i < years; i++)
        cout << "\t" << bt.first()[i] << "\t" << bt.second()[i] << endl;

}