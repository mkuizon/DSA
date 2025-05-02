// Add your code here

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

template<typename T>
struct node {
    T value;
    node<T>* next;
    node<T>* previous;

    node(const T &val) : value(val), next(nullptr), previous(nullptr) {}
};


template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();            // Constructor
    ~DoublyLinkedList();           // Destructor

    void Append(const T &value);
    T& operator[](int index);
    bool Find(const T &value);
    void Insert(int index, const T &value);
    bool IsEmpty() const;
    void Print() const;
    void PrintReverse() const;
    bool Delete(const T &value);
    bool DeleteAt(int index);
    int Size() const;

private:
    node<T>* head;  // Pointer to the first node
    int size;
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), size(0) {}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    node<T>* current = head;
    while (current != nullptr) {
        node<T>* nextnode = current->next;
        delete current;
        current = nextnode;
    }
}

template<typename T>
void DoublyLinkedList<T>::Append(const T &value) {
    node<T>* newnode = new node<T>(value);
    if (head == nullptr) {
        head = newnode;
    } else {
        node<T>* current = head;
        // Traverse to the last node.
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newnode;
        newnode->previous = current;
    }
    size++;
}

template<typename T>
T& DoublyLinkedList<T>::operator[](int index) {
    if (index < 0) {
        index = size + index; // -1 becomes size-1
    }

    
    node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}


template<typename T>
bool DoublyLinkedList<T>::Find(const T &value) {
    node<T>* current = head;
    while (current != nullptr) {
        if (current->value == value)
            return true;
        current = current->next;
    }
    return false;
}

template<typename T>
void DoublyLinkedList<T>::Insert(int index, const T &value) {
    // If inserting at or beyond the end, use Append
    if (index >= size) {
        Append(value);
        return;
    }
    if (index < 0) {
        index = size + index;
        if (index < 0)
            index = 0;
    }
    
    node<T>* newnode = new node<T>(value);
    
  
    if (index == 0) {
        newnode->next = head;
        if (head != nullptr)
            head->previous = newnode;
        head = newnode;
        size++;
        return;
    }
    

    node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    // Link the new node into the list
    node<T>* prevnode = current->previous;
    prevnode->next = newnode;
    newnode->previous = prevnode;
    newnode->next = current;
    current->previous = newnode;
    size++;
}

//returns true if the list is empty
template<typename T>
bool DoublyLinkedList<T>::IsEmpty() const {
    return (head == nullptr);
}

// prints the list in order
template<typename T>
void DoublyLinkedList<T>::Print() const {
    node<T>* current = head;
    while (current != nullptr) {
        cout << current->value;
        if (current->next != nullptr)
            cout << "->";
        current = current->next;
    }
    cout << "\n";
}

//prints the list in reverse order
template<typename T>
void DoublyLinkedList<T>::PrintReverse() const {
    if (head == nullptr) {
        cout << "\n";
        return;
    }
    // go to the tail
    node<T>* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    // traverse backwards
    while (current != nullptr) {
        cout << current->value;
        if (current->previous != nullptr)
            cout << "->";
        current = current->previous;
    }
    cout << "\n";
}

// remove the first occurrence of value
template<typename T>
bool DoublyLinkedList<T>::Delete(const T &value) {
    node<T>* current = head;
    while (current != nullptr) {
        if (current->value == value) {
         
            if (current->previous != nullptr)
                current->previous->next = current->next;
            else
                head = current->next;  // Removing head
            
      
            if (current->next != nullptr)
                current->next->previous = current->previous;
            
            delete current;
            size--;
            return true;
        }
        current = current->next;
    }
    return false;
}

// remove the item at index
template<typename T>
bool DoublyLinkedList<T>::DeleteAt(int index) {

    if (index < 0)
        index = size + index;
    if (index < 0 || index >= size)
        return false;
    
    node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    

    if (current->previous != nullptr)
        current->previous->next = current->next;
    else
        head = current->next;  // current is head
    

    if (current->next != nullptr)
        current->next->previous = current->previous;
    
    delete current;
    size--;
    return true;
}

// return the number of items in the list
template<typename T>
int DoublyLinkedList<T>::Size() const {
    return size;
}

#endif  // DOUBLYLINKEDLIST_H
