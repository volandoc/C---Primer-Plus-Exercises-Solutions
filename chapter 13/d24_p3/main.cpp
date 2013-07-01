/*
Revise the base DMA-lacks DMA-has DMAclass hierarchy so that all three classes are derived from an ABC.
Test the result with a program similar to the one in Listing 13.10.
That is, it should feature an array of pointers to the ABC and allow the user to make runtime decisions as to what types of objects are created.
Add virtual View() methods to the class definitions to handle displaying the data.
*/

#include "dma.h"

const int LEN = 40; // max length of Label, Rating, Color, and Style strings
const int ITEMS = 4; // total of 4 items to be entered

int main() {
    using namespace std;

    char templabel[LEN], tempcolor[LEN], tempstyle[LEN], choice;
    int temprating = 0;

    ABC_DMA * pt[ITEMS]; // array of abstract base class pointers

    for (int i = 0; i < ITEMS; i++) {
        cout << "\nEnter 1 for Shirt, 2 for Balloon, 3 for Map: ";
        while ((cin >> choice).get() && (choice != '1' && choice != '2' && choice != '3')) { // make sure choice is correct
            cout << "Enter either 1, 2, or 3. : ";
        }

        cout << "\nItem #" << i + 1 << " Label: "; // Label and Rating are for all three classes
        cin.getline(templabel,LEN);
        cout << "Item #" << i + 1 << " Rating: ";
        (cin >> temprating).get();

        switch(choice) {
        case '1':
            pt[i] = new baseDMA (templabel, temprating); // if Shirt is chosen, baseDMA class
            break;

        case '2':
            cout << "Item #" << i + 1 << " Color: "; // if Balloon is chosen, lacksDMA class
            cin.getline(tempcolor,LEN);
            pt[i] = new lacksDMA(tempcolor, templabel, temprating);
            break;

        case '3':
            cout << "Item #" << i + 1 << " Style: "; // if Map is chosen, hasDMA class
            cin.getline(tempstyle,LEN);
            pt[i] = new hasDMA(tempstyle,templabel, temprating);
            break;
        }

    }

    cout << "\nDisplaying entered items:";
    for (int i = 0; i < ITEMS; i++) {
        cout << "\n--------";
        pt[i]->View();
    }

    for (int i = 0; i < ITEMS; i++)
        delete pt[i]; // deleting all dynamic pointers from array

    system("pause");
    return 0;
}