#include <iomanip>
#include <iostream>

#include "Dollar.cpp"
/*
* Lab 5
* Harmony Trinh & Jayne Tan
* The purpose of this lab is to use hash table with quadratic probing to find a user input Dollar object.
*/
class hash_table {
private:
    Dollar** data;
    const int size;
    const int hash_m;
    const int hash_n;
    int collisionCount;

public:
    hash_table(int s, int m, int n)
        : size(s), hash_m(m), hash_n(n), collisionCount(0) {
        data = new Dollar * [size];

        for (int i = 0; i < size; i++) {
            data[i] = nullptr;
        }
    }

    hash_table() = delete;
    hash_table(const hash_table&) = delete;

    ~hash_table() {
        for (int i = 0; i < size; i++) {
            delete data[i];
        }

        delete data;
    }

    int add(Dollar d) {
        int index_base = d.get_whole() * hash_m + hash_n * d.get_fraction();
        for (int i = 0; i < size; i++) {
            int index = (index_base + i * i) % size;
            if (data[index] == nullptr) {
                data[index] = new Dollar(d);
                return index;
            }
            else {
                collisionCount++;
            }
        }
        return -1;
    }

    int find(Dollar d) {
        int index_base = d.get_whole() * hash_m + hash_n * d.get_fraction();
        for (int i = 0; i < size; i++) {
            int index = (index_base + i * i) % size;
            if (data[index] != nullptr) {
                return index;
            }
        }
        return -1;
    }
    int getCollisionCount() const {
        return collisionCount;
    }
};