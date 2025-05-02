// Implement the Deque here
#ifndef DEQUE_H
#define DEQUE_H
#include <exception>

class InvalidDequeOperation : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid operation on an empty Deque";
    };
};

template <typename T>
struct Node { // doubly linked
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}

};

template <typename T>
class Deque {
    public:
        Deque() : head(nullptr), tail(nullptr) {}
        ~Deque();
        void PushBack(const T& item);
        void PushFront(const T& item);
        T PopBack();
        T PopFront();
        T Back() const;
        T Front() const;
        bool IsEmpty() const;
    private:
        Node<T>* head; // front node ptr
        Node<T>* tail; // rear node

};

template <typename T>
Deque<T>::~Deque() {
    // freeing all the nodes
    while (!IsEmpty()) {
        PopFront();
    }
}

template <typename T>
void Deque<T>::PushBack(const T& item) {
    Node<T> * newNode = new Node<T>(item);
    if (IsEmpty()) {
        // if the Deque is empty, the first node is the front and rear
        head = newNode;
        tail = newNode;
    } else {
        // pushing to the tail
        tail->next = newNode; // current tail's next pointer points to new node
        newNode->prev = tail; // newNode prev ptr points to tail (last node in)
        tail = newNode; // tail is now the new node
    }
}

template <typename T>
void Deque<T>::PushFront(const T& item) {
    Node<T> * newNode = new Node<T>(item);
    if (IsEmpty()) {
        // if the Deque is empty, the first node is the front and rear
        head = newNode;
        tail = newNode;
    } else {
        // pushing to the head
        newNode->next = head; // new next pointsd to current head
        head->prev = newNode; // current head prev pts to new
        head = newNode; // new node set as head
    }
}

template <typename T>
T Deque<T>::PopBack() { // remove from tail of Deque
    if (IsEmpty()) {
        // throwing error since nothing to remove
        throw InvalidDequeOperation();
    }

    Node<T>* temp = tail; // holding current tail for deletion
    T retrieve = tail->data; // storing tail value to return
    tail = tail->prev; // now the tail pointer is the node before
    // if Deque is empty after removing front
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head=nullptr;
    }
    delete temp;
    return retrieve;
}

template <typename T>
T Deque<T>::PopFront() {
    if (IsEmpty()) {
        // throwing error since nothing to remove
        throw InvalidDequeOperation();
    }
    Node<T>* temp = head;         // holding current head for deletion
    T retrieve = head->data;        // ttoring head value to return
    head = head->next;              // update head
    if (head != nullptr) {
        head->prev = nullptr;
    } else {

        tail = nullptr;
    }
    delete temp;
    return retrieve;
}

template <typename T>
T Deque<T>::Back() const {
    // returning back value
    if (IsEmpty()) {
        throw InvalidDequeOperation();
    }
    return tail->data;
}

template <typename T>
T Deque<T>::Front() const {
    // returning front value
    if (IsEmpty()) {
        throw InvalidDequeOperation();
    }
    return head->data;
}


template <typename T>
bool Deque<T>::IsEmpty() const {
    return head==nullptr;
}

#endif
