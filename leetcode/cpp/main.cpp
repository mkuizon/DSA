#include <iostream>
using namespace std;

bool determine(bool a, bool b){
    if (a && b) { return true;} else {return false;}

};

int main() {
    bool a = true;
    bool b = false;

    cout << determine(a,b) << endl;
    

    return -1;

}