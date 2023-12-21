/*
Lab 4
Jayne Tan and Harmony Trinh
The purpose of this lab is to utilize different types of traversal methods within
a binary search tree.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include "bst.cpp"
#include <fstream>
using namespace std;
int main(){
    ofstream bstoutput("output.txt");

    BST bst;
    bst.insert(Dollar(57.12));
    bst.insert(Dollar(23.44));
    bst.insert(Dollar(87.43));
    bst.insert(Dollar(68.99));
    bst.insert(Dollar(111.22));
    bst.insert(Dollar(44.55));
    bst.insert(Dollar(77.77));
    bst.insert(Dollar(18.36));
    bst.insert(Dollar(543.21));
    bst.insert(Dollar(20.21));
    bst.insert(Dollar(345.67));
    bst.insert(Dollar(36.18));
    bst.insert(Dollar(48.48));
    bst.insert(Dollar(101.00));
    bst.insert(Dollar(11.00));
    bst.insert(Dollar(21.00));
    bst.insert(Dollar(51.00));
    bst.insert(Dollar(1.00));
    bst.insert(Dollar(251.00));
    bst.insert(Dollar(151.00));

    bst.setOuputStream(bstoutput);
    bst.print();
    bst.setOuputStream(std::cout);
    bst.print();

    
    while (true) {
        cout << "Enter a to add, s to search, and d to delete followed by a dollar value; or p to print or e to exit the program: " << endl;

        char userin;
        cin >> userin;
    
        if(userin == 'p'){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            bst.setOuputStream(bstoutput);
            bst.print();
            bst.setOuputStream(std::cout);
            bst.print();
        }else if(userin == 'e'){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            bst.setOuputStream(bstoutput);
            bst.print();
            bst.setOuputStream(std::cout);
            bst.print();
            bstoutput.close();
            break;
        }

        double value;
        cin >> value;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        switch (userin) {
            case 'a':
                bst.insert(value);
                break;
            case 's':
                if(bst.search(value) != nullptr){
                    cout << value << " is found" << endl;
                    //bstoutput << value << " is found" << endl;
                }else{
                    cout << value << " is not found" << endl;
                    //bstoutput << value << " is not found" << endl;
                }
                break;
            case 'd': 
                bst.remove(value);
                break;
            default:
                cout << "Incorrect input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
        }
    
    }
};