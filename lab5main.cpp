#include <iomanip>
#include <iostream>

#include "hash.cpp"
/*
* Lab 5
* Harmony Trinh & Jayne Tan
* The purpose of this lab is to use hash table with quadratic probing to find a user input Dollar object.
*/
int main() {
    hash_table htbl(29, 2, 3);
  
    Dollar data[] = {
        Dollar(57.12),
        Dollar(23.44),
        Dollar(87.43),
        Dollar(68.99),
        Dollar(111.22),
        Dollar(44.55),
        Dollar(77.77),
        Dollar(18.36),
        Dollar(543.21),
        Dollar(20.21),
        Dollar(345.67),
        Dollar(36.18),
        Dollar(48.48),
        Dollar(101.00),
        Dollar(11.00),
        Dollar(21.00),
        Dollar(51.00),
        Dollar(1.00),
        Dollar(251.00),
        Dollar(151.00)
    };
    int dataSize = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < dataSize; ++i) {
        htbl.add(data[i]);
    }

    std::cout << "Number of data items loaded: " << dataSize << "\n";
    std::cout << "Load factor: " << static_cast<double>(dataSize) / 29 << "\n";
    std::cout << "Number of collisions: " << htbl.getCollisionCount() << "\n";

    while (true) {
        double whole, fractional;
        std::cout << "\nEnter Dollar to search for (whole fractional): ";
        std::cin >> whole >> fractional;

        Dollar searchCurrency(whole + fractional / 100.0);
        int index = htbl.find(searchCurrency);

        if (index != -1) {
            std::cout << "Found at index: " << index << "\n";
        }
        else {
            std::cout << "Invalid Data\n";
        }

        char choice;
        std::cout << "Do you want to check again? (y/n): ";
        std::cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    return 0;
}