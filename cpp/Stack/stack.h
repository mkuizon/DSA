// Implement the stack here
#ifndef STACK_H
#define STACK_H
#include <exception>
class InvalidStackOperation : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Invalid operation.";
        }
    };

template <typename T>
class Stack{
   public:
      Stack() : capacity(4), size(0) {
         arr = new T[capacity]; }
      ~Stack();
      void Push(const T& item);
      T Pop();
      T Top();
      bool IsEmpty() const;
   private:
      int capacity;
      int size;
      T* arr;
      // function for resizing the capacity of array when the stack is full:
        void Resize() {
            int newCap = capacity * 2;
            T* newArr = new T[newCap];
            
            // copying the old array into new
            for (int i = 0; i < size; i++) {
            newArr[i] = arr[i]; }
            
            // free old arr
            delete[] arr;
            
            arr = newArr;
            capacity = newCap;
        }

};

template <typename T>
Stack<T>::~Stack() {
   delete[] arr;  
}


template <typename T>
void Stack<T>::Push(const T& item) {
   if (size == capacity) {
      Resize();
   }
   
   arr[size++] = item;
}

template <typename T>
T Stack<T>::Pop() {
   if (IsEmpty()) {
    throw InvalidStackOperation();
   }
   return arr[--size];

}

template <typename T>
T Stack<T>::Top() {
    if (IsEmpty()) {
        throw InvalidStackOperation();
    }
    return arr[size-1];
}

template <typename T>
bool Stack<T>::IsEmpty() const {
    return size == 0;
}
   
#endif
   
   
   
      
      