/*
Write a program that opens two text files for input and one for output.
The program should concatenate the corresponding lines of the input files, use a space as a separator, and write the results to the output file.
If one file is shorter than the other, the remaining lines in the longer file should also be copied to the output file.
For example, suppose the first input file has these contents:
    eggs kites donuts
    balloons hammers
    stones

    And suppose the second input file has these contents:
    zero lassitude
    finance drama

    The resulting file would have these contents:
    eggs kites donuts zero lassitude
    balloons hammers finance drama
    stones
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void main() {
    string f1, f2;
    string temp;
    ifstream file_in1, file_in2;
    file_in1.open("1.txt");
    file_in2.open("2.txt");
    ofstream file_out;
    file_out.open("out.txt");
    if (file_in1.is_open() && file_in2.is_open()) {
        while (!file_in1.eof() || !file_in2.eof()) {
            if (file_in1.peek() != EOF) {
                getline(file_in1, temp);
                file_out << temp;
                if (file_in2.peek() != EOF) {     //get rid of ended whitespace
                    file_out << " ";
                }
            } else if (file_in2.peek() != EOF) { //put whitespace when first file is ended
                file_out << " ";
            }
            if (file_in2.peek() != EOF) {
                getline(file_in2, temp);
                file_out << temp << "\n";       //getline drops \n so we restore it
            } else if (file_in1.peek() != EOF) {//put \n if second file is ended
                file_out << "\n";
            }
        }
        file_in1.close();
        file_in2.close();
        file_out.close();
        cout << "File written and closed. See in out.txt. Bye!\n";
    } else cout << "File not found, program terminated!\n";
    system("pause");
}