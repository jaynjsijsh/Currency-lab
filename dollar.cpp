/*
Lab 4
Jayne Tan and Harmony Trinh
The purpose of this lab is to utilize different types of traversal methods within
a binary search tree.
*/
#include <iostream>
#include <string>
#include "Currency.cpp"
//removed using namespace std;

class Dollar : public Currency {
protected:
    std::string type = "Dollar";
    std::string get_type() {
        return type;
    }
public:
    //constructors
    Dollar() : Currency() {  }
    Dollar(double value) : Currency(value) { }
    Dollar(const Dollar& currncy) : Currency(currncy) { }
};