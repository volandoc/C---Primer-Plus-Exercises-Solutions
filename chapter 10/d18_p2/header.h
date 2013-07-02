#include <string>

class Person {
private:
    static const int LIMIT = 25;
    std::string lname; // Person's last name
    char fname[LIMIT]; // Person's first name
public:
    Person() {
        lname = "";
        fname[0] = '\0';
        std::cout << "\nUsing default constructor.\nInitialisation done.\n";
    } // #1
    Person(const std::string & ln, const char * fn = "Hey you"); // #2
    // the following methods display lname and fname
    void Show() const; // first name last name format
    void FormalShow() const; // last name, first name format
};