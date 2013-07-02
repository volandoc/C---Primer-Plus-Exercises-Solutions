#include <iostream>
#include <cmath>

using namespace std;

int main () {
    /*Write a program that asks the user to enter the number of seconds as an integer value
        (use type long,or,if available,long long) and that then displays the equivalent time
        in days, hours, minutes, and seconds.
        Use symbolic constants to represent the number of hours in the day,
        the number of minutes in an hour,and the number of seconds in a minute.
        The output should look like this:
        Enter the number of seconds: 31600000
        31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds*/

    long int seconds = 0;
    int days, hours,minutes, secondsLast = 0;

    const int HoursInDay = 24;
    const int MinutesInHour = 60;
    const int SecondsInMinute = 60;
    const int SecondsInHour = SecondsInMinute*MinutesInHour;
    const int SecondsInDay = SecondsInHour*HoursInDay;

    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "Enter the number of seconds: ";
    cin >> seconds;

    days = seconds/(HoursInDay*MinutesInHour*SecondsInMinute);
    hours = (seconds-days*SecondsInDay)/SecondsInHour;
    minutes = (seconds-days*SecondsInDay-hours*SecondsInHour)/SecondsInMinute;
    secondsLast = seconds-days*SecondsInDay-hours*SecondsInHour-minutes*SecondsInMinute;

    cout << seconds << " seconds = "
         << days << " days, " << hours << " hours, " << minutes << " minutes, "
         << secondsLast << " seconds.";


    cin.get();
    cin.get();
}