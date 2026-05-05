#include <iostream>
#include <fstream>
#include <string>
#include "Space.h"
#include "LivingSpace.h"
#include "CommercialSpace.h"
#include "RealEstate.h"
#include "Exception.h"
using namespace std;

int main() {
    RealEstate agency("Agency");
    int choice;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Input information" << endl;
        cout << "2. Load from file" << endl;
        cout << "3. Show all spaces" << endl;
        cout << "4. Calculate total price" << endl;
        cout << "5. Find absolute sizes" << endl;
        cout << "6. Sort by size (operator<)" << endl;
        cout << "7. Find big owners (> 2 properties)" << endl;
        cout << "8. Split into Living and Commercial" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int type;
            cout << "1 - LivingSpace, 2 - CommercialSpace: ";
                cin >> type;
            
            Space* s = nullptr;
            try {
                if (type == 1) s = new LivingSpace();
                else if (type == 2)s = new CommercialSpace();
                else
                    throw Exception("type not possible");
                cin >> *s;
                agency.add(s);
                break;
            }
            catch (Exception& e) {
                cout << "Problem with entering: " << e.what();
                delete s;
            }
            break;
        }

        case 2:
            agency.load();
            cout << "Data loaded from file." << endl;
            break;

        case 3:
            agency.print();
            break;

        case 4:
            cout << "Total Sum of all properties: " << agency.totalSum() << endl;
            break;

        case 5:
            agency.findAbsolutes();
            break;

        case 6:
            agency.sort();
            cout << "Sorted" << endl;
            break;

        case 7:
            agency.findBigOwners();
            break;

        case 8: {
            Space** living = nullptr, ** comm = nullptr;
            int lSize = 0, cSize = 0;

            agency.split(living, lSize, comm, cSize);

            cout << "\n--- Living Spaces (" << lSize << ") ---" << endl;
            for (int i = 0; i < lSize; i++) living[i]->write(cout);

            cout << "\n--- Commercial Spaces (" << cSize << ") ---" << endl;
            for (int i = 0; i < cSize; i++) comm[i]->write(cout);

            delete[] living;
            delete[] comm;
            break;
        }

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);
    return 0;
}