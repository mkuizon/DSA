#include <iostream>
#include "Hash.h"
using namespace std;

bool isPrime(int n) {
    // prime numbers are numbers that can only be multiplied by itself to get the number
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int nextPrime(int n) {
    while(!isPrime(n)) {
        n++;
    }
    return n;
}

int main() {
    int recommendedSize;
    cin >> recommendedSize;
    int tableSize = nextPrime(recommendedSize);
    Hash myHash(tableSize);
    int value;
    while (cin >> value) {
        int index = value % tableSize;
        cout << "Inserting: " << value << " at " << index << endl;
        myHash.insert(value);
    }
    myHash.display();
    return 0;
}
