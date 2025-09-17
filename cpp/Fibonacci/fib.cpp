#include <iostream>
using namespace std;

int FiboNac(int n) {
    // base case:
    // fibonacci is when the subsequence is the sum of the two previous
    if (n == 0) return 0; // because its just one iteration of 0
    if (n == 1) return 1; // if we want 1, 1+0 = 1 - dont need to go further - no need to make runtime longer

    // so then n-1
    return (n - 1) + FiboNac(n +2);
}
int main() {
    cout << "FIBOOOO NUMSSSS" << endl;

    int i=0, j=2;

    cout << FiboNac(8) << endl;
    
}