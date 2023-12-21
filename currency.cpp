/*
Lab 4
Jayne Tan and Harmony Trinh
The purpose of this lab is to utilize different types of traversal methods within
a binary search tree.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
//removed using namespace std;

class Currency {
protected:
    int whole;
    int fraction;
    virtual std::string get_type() = 0;

public:
    Currency() {
        whole = 0;
        fraction = 0;
    }
    Currency(double value) {
        if (value < 0)
            throw "Invalid value";
        whole = int(value);
        fraction = std::round(100 * (value - whole));
    }
    Currency(const Currency& currncy) {
        whole = currncy.whole;
        fraction = currncy.fraction;
    }
    int get_whole() {
        return whole;
    }

    int get_fraction() {
        return fraction;
    }

    void set_whole(int w) {
        if (w >= 0)
            whole = w;
    }

    void set_fraction(int f) {
        if (f >= 0 && f < 100)
            fraction = f;
    }

    //Pre: currncy- pointer to Currency object
    //Post: whole and fraction are updated by adding the value of currncy
    //Return: 
    void add(const Currency* currncy) {
        whole += currncy->whole;
        fraction += currncy->fraction;
        if (fraction >= 100) {
            whole++;
            fraction %= 100;
        }
    }

    //Pre: currncy- pointer to Currency object
    //Post: whole and fraction are updated by subtracting the value of currncy
    //Return: 
    void subtract(const Currency* currncy) {
        if (!isGreater(*currncy))
            throw "Invalid Subtraction";
        whole -= currncy->whole;
        if (fraction < currncy->fraction) {
            fraction = fraction + 100 - currncy->fraction;
            whole--;
        }
        else {
            fraction -= currncy->fraction;
        }
    }

    //Pre: currncy- pointer to Currency object
    //Post:
    //Reurn: true or false
    bool isEqual(const Currency& currncy) const {
        return (currncy.whole == whole) && (currncy.fraction == fraction);
    }

    //Pre: currncy- pointer to Currency object
    //Post:
    //Return: true or false
    bool isGreater(const Currency& currncy) const{
        if (whole < currncy.whole)
            return false;
        if (whole == currncy.whole && fraction < currncy.fraction)
            return false;
        return true;
    }

    //formatting changes so output is able to be printed in both the file and the screen
    void print(std::ostream& os) {
        /*std::cout << whole << "."
            << std::left << std::fixed
            << std::setprecision(2) << std::setw(2) << std::setfill('0') << fraction
            << " " << get_type() << " ";
        */
        os << whole << "."
            << std::left << std::fixed
            << std::setprecision(2) << std::setw(2) << std::setfill('0') << fraction
            << " " << get_type() << " ";
    }
};