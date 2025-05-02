//
//  ArrayList.h
//  ArrayList
//
//  Created by Micah Kuizon on 2/1/25.
//
#ifndef ARRAYLIST_H

#pragma once
#include <iostream>
using namespace std;

template<typename T>
class ArrayList {
   public:
      ArrayList();                     // Default Constructor
      ~ArrayList();                    // Destructor
      
      void Append(T value);            // Add a value to the end of the list
      T At(int index, T value);        // Return the element at index or the default value
      int Capacity();                  // Return the current maximum capacity of the array list
      int Find(T value);               // Return index of first occurrence of value or -1 if not found
      void Insert(int index, T value); // Insert value at index
      bool IsEmpty();                  // True if the list is currently empty
      void Print();
      bool Remove(T value);            // Find the first occurrence of value and remove the value; true if success
      bool RemoveAt(int index);        // Remove the value at the specified index; true if success
      int Size();                      // Number of elements in the list

   private:
      T* list;                         // Items are stored in this dynamic array
      int size, capacity;
};

// Add your code here
// constructor
template<typename T>
ArrayList<T>::ArrayList() {
   capacity = 8; // default capacity
   size = 0;
   list = new T[capacity];
}

// destructor
template<typename T>
ArrayList<T>::~ArrayList() {
   delete[] list;
}

// adding value to end of list
template<typename T>
void ArrayList<T>::Append(T value) {
   if (size >= capacity) {
      // double the capacity if size is equal to capacity
      capacity *= 2;
      T* newList = new T[capacity];
      
      // creating the new list
      for (int i =0; i < size; i++) {
         newList[i] = list[i];
   }
   delete[] list;
   list = newList;
}
   // adding value to the list
   list[size] = value;
   size++;
}

// return element at index or default value
template<typename T>
T ArrayList<T>::At(int index, T value) {
   if (index < 0 || index >= size) {
      return value;
   }
   return list[index];
}

// return max cap of list
template<typename T>
int ArrayList<T>::Capacity() {
   return capacity;
   }

// return index of value
template<typename T>
int ArrayList<T>::Find(T value) {
   for (int i = 0; i < size; i++) {
      if (list[i] == value) {
         return i;
      }
   }
   return -1;
   
}
// If the index is at or beyond the end of the list, add the item to the end of the list (increase the size if necessary).
//If the index is in the middle of the list, shift the current and subsequent items before adding the new item.
//If the index is negative, do not add the item to the list.
// insert val at index
template<typename T>
void ArrayList<T>::Insert(int index, T value) {
   // if index is negative:
   if (index < 0) {
      return;
   }
   // beyond list:
   if (index >= size) {
      Append(value);
      return; }
   
   // expanding cap if needed
   if (size >= capacity) {
      capacity *= 2;
      T* newList = new T[capacity];
      for (int i = 0; i < size; i++) {
         newList[i] = list[i];
      }
      delete[] list;
      list = newList;
   }
   
   // middle of list
   for (int i = size; i > index; i--) {
      list[i] = list[i - 1];
   }
   
   list[index] = value;
   size++;

}

template<typename T>
bool ArrayList<T>::IsEmpty() {
   return size == 0;
   }

template<typename T>
void ArrayList<T>::Print() {
   for (int i = 0; i < size; i++) {
      cout << list[i];
      if (i < size - 1) {
         cout << ", ";
         }
   }
   cout << endl;
}

template<typename T>
bool ArrayList<T>::Remove(T value) {
   int index = Find(value);
   if (index == -1) {
      return false;
   }
   return RemoveAt(index);
   
}

template<typename T>
bool ArrayList<T>::RemoveAt(int index) {
   if (index < 0 || index >= size) {
      return false;
   }

   for (int i = index; i < size - 1; i++) {
      list[i] = list[i + 1];
   }
   size--;
   return true;
   
}

template<typename T>
int ArrayList<T>::Size() {
   return size;
}

#endif
   
