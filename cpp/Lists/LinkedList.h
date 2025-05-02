#ifndef LINKEDLIST_H
#pragma once
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next; // Removed default initializer
};

class LinkedList {
public:
    LinkedList();                      // Default Constructor
    ~LinkedList();                     // Destructor

    void Append(int value);            // Add a value to the end of the list
    int Get(int index);                // Return the value at the index requested, or 0
    bool Find(int value);              // Returns true if the value is found and false if not
    void Insert(int index, int value); // Insert value at index
    bool IsEmpty();                    // True if the list is currently empty
    void Print();
    bool Delete(int value);            // Delete the first occurrence of value; true if successful
    bool DeleteAt(int index);          // Delete the value at the location; true if successful
    int Size();                        // Number of elements in the list

private:
    Node* head;                        // Items are linked to the head
    int size;
};

// Implementation
LinkedList::LinkedList() : head(nullptr), size(0) {}

LinkedList::~LinkedList() {
   Node* current = head;
   while (current != nullptr) {
      Node* temp = current;
      current = current->next;
      delete temp;
   }
}

void LinkedList::Append(int value) {
   Node* newNode = new Node;
   newNode->value = value;
   newNode->next = nullptr;
    
   if (head == nullptr) {
      head = newNode;
   }
   else {
      Node* current = head;
      while (current->next != nullptr) {
         current = current->next;
      }
      current->next = newNode;
   }
   size++;
}

int LinkedList::Get(int index) {
   if (index < 0 || index >= size) {
      return 0;
   }
   Node* current = head;
   for (int i = 0; i < index; i++) {
      current = current->next;
   }
   return current->value;
}

bool LinkedList::Find(int value) {
   Node* current = head;
   while (current != nullptr) {
      if (current->value == value) {
         return true;
      }
      current = current->next;
   }
   return false;  
} 

void LinkedList::Insert(int index, int value) {
   if (index < 0 || index > size) {
     return;
   }
   if (index == 0) {
      Node* newNode = new Node;
      newNode->value = value;
      newNode->next = head;
      head = newNode;
   } else {
      Node* current = head;
      for (int i = 0; i < index - 1; i++) {
            current = current->next;
      }
      Node* newNode = new Node;
      newNode->value = value;
      newNode->next = current->next;
      current->next = newNode;
   }
   size++;
}

bool LinkedList::IsEmpty() { 
    return size == 0;
}

void LinkedList::Print() {
   Node* current = head;
   while (current != nullptr) {
      cout << current->value;
      if (current->next != nullptr) {
         cout << "->";
      }
      current = current->next;
   }
   cout << endl;
}

bool LinkedList::Delete(int value) {
   if (head == nullptr) {
      return false;
   }
   if (head->value == value) {
      Node* temp = head;
      head = head->next;
      delete temp;
      size--;
      return true;
   }
   Node* current = head;
   while (current->next != nullptr) {
         if (current->next->value == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
            return true;
         }
      current = current->next;
   }
   return false;
}

bool LinkedList::DeleteAt(int index) {
   if (index < 0 || index >= size) {
      return false;
   }
   if (index == 0) {
      Node* temp = head;
      head = head->next;
      delete temp;
   } else {
      Node* current = head;
      for (int i = 0; i < index - 1; i++) {
         current = current->next;
      }
      Node* temp = current->next;
      current->next = current->next->next;
      delete temp;
   }
   size--;
   return true;
}

int LinkedList::Size() { 
    return size; 
}

#endif  
