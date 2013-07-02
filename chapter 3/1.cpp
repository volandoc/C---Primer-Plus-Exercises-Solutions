#include <iostream>
#include <cmath>

using namespace std;

int main () {
    /*Write a short program that asks for your height in integer inches
        and then converts your height to feet and inches.
        Have the program use the underscore character to indicate
        where to type the response.
        Also use a const symbolic constant to represent the conversion factor.*/

    const int InchesInFoot = 12;
    int heightInInches = 0;
    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "Please, enter your height in inches: ___" << "\b\b\b";
    cin >> heightInInches;
    cout << "Your height is: " << heightInInches/InchesInFoot << " foots "
         << heightInInches%InchesInFoot << " inches." << endl;

    /*Write a short program that asks for your height in feet and inches
        and your weight in pounds. (Use three variables to store the information.)*/

    const double convInchesToMeter = 0.0254;
    const double convLBtoKG = 2.2;
    int heightInFoots = 0;
    int weightInPounds = 0;
    //Let`s reset value.
    heightInInches = 0;
    cout << "Please, enter your height (foots): _" << "\b";
    cin >> heightInFoots;
    cout << "Please, enter your height (inches): __" << "\b\b";
    cin >> heightInInches;
    cout << "Please, enter your weight (pounds): __" << "\b\b";
    cin >> weightInPounds;

    /*Have the program report your body mass index (BMI).
        To calculate the BMI, first convert your height in feet and inches
        to your height in inches (1 foot = 12 inches).*/
    heightInInches +=heightInFoots*InchesInFoot;

    /*Then convert your height in inches to your height in meters
        by multiplying by 0.0254.*/
    const double MetersInInch = 0.0254;
    double heightInMeters = heightInInches*MetersInInch;

    /*Then convert your weight in pounds into your mass in kilograms
        by dividing by 2.2.*/
    double weightInKg = weightInPounds/2.2;

    /*Finally,compute your BMI by dividing your mass in kilograms
        by the square of your height in meters.*/
    double BMI = weightInKg/pow(heightInMeters,2);

    cout << "Your BMI is: " << BMI << endl;

    /*Use symbolic constants to represent the various conversion factors.
        Done*/

    cin.get();
    cin.get();
}