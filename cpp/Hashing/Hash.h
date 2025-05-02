#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include "List.h"

using namespace std;

class Hash {
private:
    int size;
    vector<List> table;
    int hashFunction(int key) const {
        return key % size;
    }
public:
    Hash(int s) : size(s), table(s) {}
    void insert(int key) {
        int index = hashFunction(key);
        table[index].insertAtEnd(key);
    }
    void display() const {
        cout << "***** Hash Table *****" << endl;
        for (int i = 0; i < size; i++) {
            cout << i;
            if (!table[i].empty()) {
                cout << " --> ";
                table[i].display();
            }
            cout << endl;
        }
        cout << "**********************" << endl;
    }
};

#endif
