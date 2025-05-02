#include <iostream>
#include <string>
#include "LinkedList.h"
#include "DoublyLinkedList.h"
using namespace std;

// remember the parameter dt has to be what it is ex LinkedList
// & - pass by reference - gives direct access to the object
// pass by value - creates a copy
// const - the function promises not to modify the object
//--------------------------------------------------------------
// int countOccurancesLL(Node* first, Node* second) {
//     int count = 0;

//     Node* current;
//     while(first != nullptr) {
//         current = second;
//         while(current != nullptr){
//             if(first->value==current-> value){
//                 count++;
//             }
//             current = current->next;
//         }
//         first = first->next;   
//     }
//     return count;
    
// }
//--------------------------------------------------------------
int SumOfDigits(int n){
//     int sum = 0;
//     string s = to_string(n);
//     int size = s.size();
//     for (int i = 0; i < size; i++) {
//         int digit = s[i] - '0';
//         sum += digit;
//     }
//     return sum;
// im actually a dumb ass.
/*
    if i take the remainder % 10, it gives me the number
    GOOOOOOOSHHHHHHHdfhkjdsfjkalsdhfjlksahdlf
*/


// recursively:
    // base case:
    if (n < 10) return n;
    return n % 10 + SumOfDigits(n/10);
}

int main () {
    cout << "Practice testt" << endl;
    cout << endl;

    cout << "Recursion of sum of digits output: " << SumOfDigits(2) << endl;

    // LinkedList List1;
    // LinkedList List2;
    // List1.Append(1);
    // List1.Append(2);
    // List1.Append(3);
    // List1.Append(4);
    
    // cout << "List 1: ";
    // List1.Print();
    // cout << endl; 

    // List2.Append(2);
    // List2.Append(4);
    // List2.Append(6);
    // List2.Append(1);
    // List2.Append(5);

    // cout << "List 2:";
    // List2.Print();
    // cout << endl;

    DoublyLinkedList<int> list;
   
    list.Append(1);
    list.Append(3);
    list.Append(5);
    list.Append(7);
    list.Append(9);
    
    list.Print();
    list.PrintReverse();
    
 
    return 0;

}

