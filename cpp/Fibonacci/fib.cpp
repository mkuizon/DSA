#include <iostream>
using namespace std;

int FiboNac(int n) {
    // base case:
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    return (n - 1) + FiboNac(n +2);
}
int main() {
    cout << "FIBOOOO NUMSSSS" << endl;

    int i=0, j=1;

    cout << i << " " << j;
    
}