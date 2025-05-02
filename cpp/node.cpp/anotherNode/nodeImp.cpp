#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

void sortLinked(Node* link) {
    vector<int> sortedn;

    Node* current = link;
    while (current != nullptr) {
        sortedn.push_back(current->data);
        current = current->next;
    }

    sort(sortedn.begin(), sortedn.end());

    Node* head = new Node(-1);
    Node* curr  = head;
    for (int i = 0; i < sortedn.size(); i++) {
        curr->next = new Node(sortedn[i]);
        curr = curr->next;
    }

    Node* temp = head->next;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << "->";
        } 
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1,12,31,4,5,6,7};

    Node* dummy = new Node(-1); // head
    Node* current = dummy; 
    for (int i = 0; i < nums.size(); i++) {
        current->next = new Node(nums[i]);
        current = current->next;
    }

    
    //printing the new linked list:
    Node* temp = dummy->next; // skip dummy node (-1)
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << "->";
        } 
        temp = temp->next;
    }
    cout << endl;

    Node* dummy2 = dummy->next;
    sortLinked(dummy2);


    //freeing memory:
    Node* to_delete;
    while (dummy != nullptr) {
        to_delete = dummy;
        dummy = dummy->next;
        delete to_delete;
    }

    return 0;
}