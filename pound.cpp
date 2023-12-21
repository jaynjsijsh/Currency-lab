/*
* Lab 2
* Harmony Trinh & Jayne Tan
* The purpose of this lab is to demonstrate currency conversion using different classes, inheritance, and polymorphism.
*/
#include <iostream>
#include <string>
#include "dollar.cpp"
using namespace std;

class Pound : public Currency {
protected:
    string type = "Pound";
    string get_type() {
        return type;
    }
public:
    Pound() : Currency() {  }
    Pound(double value) : Currency(value) { }
    Pound(Dollar &currncy) : Currency(currncy) { }
};