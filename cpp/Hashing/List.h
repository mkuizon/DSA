#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;
public:
    List() : head(nullptr) {}
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    void display() const {
        Node* temp = head;
        bool first = true;
        while (temp) {
            if (!first)
                cout << " --> ";
            cout << temp->data;
            first = false;
            temp = temp->next;
        }
    }
    bool empty() const {
        return head == nullptr;
    }
};

#endif
 