#include <iostream>
using namespace std;
#include <utility>

int main() {


    cout << "Hello World!!!!" << endl;

    pair<int,int> dirs[4] = {{1,0}, {0,1}};

    for (auto it : dirs) {
        cout << "First: " << it.first << " | Second: " << it.second <<endl;
    }

    const int dir2[4][3] = {{1,2,3}, {4,5,6}, {6,7,8}, {9,10,11}};
    cout << endl;
    for (auto all : dir2) {
        cout << all[0] << " " << all[1] << " " << all[2] << endl;
    }

    return 0;
}