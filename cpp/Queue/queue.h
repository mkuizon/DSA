// Implement the Queue here
#ifndef QUEUE_H
#define QUEUE_H
#include <exception>

class InvalidQueueOperation : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid operation on an empty queue";
    };
};

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(const T& data) : data(data), next(nullptr) {}

};

template <typename T>
class Queue {
    public:
        Queue() : frontPtr(nullptr), rearPtr(nullptr) {}
        ~Queue();
        void Enqueue(const T& item);
        T Dequeue();
        T Front();
        bool IsEmpty();
    private:
        Node<T>* frontPtr; // front node ptr
        Node<T>* rearPtr; // rear node

};

template <typename T>
Queue<T>::~Queue() {
    // freeing all the nodes
    while (!IsEmpty()) {
        Dequeue();
    }
}

template <typename T>
void Queue<T>::Enqueue(const T& item) {
    Node<T> * newNode = new Node<T>(item);
    if (IsEmpty()) {
        // if the queue is empty, the first node is the front and rear
        frontPtr = newNode;
        rearPtr = newNode;
    } else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
}

template <typename T>
T Queue<T>::Dequeue() { // remove from front of queue
    if (IsEmpty()) {
        // throwing error since nothing to remove
        throw InvalidQueueOperation();
    }

    Node<T>* temp = frontPtr; // holding current front for deletion
    T retrieve = frontPtr->data; // storing front value to return
    frontPtr = frontPtr->next; // now the front pointer is the node after
    // if queue is empty after removing front
    if (frontPtr == nullptr) {
        rearPtr = nullptr;
    }
    delete temp;
    return retrieve;
}

template <typename T>
T Queue<T>::Front() {
    // returning front value
    if (IsEmpty()) {
        throw InvalidQueueOperation();
    }
    return frontPtr->data;
}

template <typename T>
bool Queue<T>::IsEmpty() {
    return frontPtr==nullptr;
}

#endif
