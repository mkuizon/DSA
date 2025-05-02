#include <iostream>
using namespace std;

// stacks are LIFO - last in first out
struct Node {
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

class LinkedListStack {
    private:
        Node* top;
        int length;
    public:
        LinkedListStack() : top(nullptr), length(0) {};
        ~LinkedListStack() {
            while (!isEmpty()) {
                pop();
            }
        }

        void push(int val) {
            Node* newNode = new Node(val);
            newNode->next = top; // setting next to top since itll be pointing to last node at top of stack (now second)
            // if stack was empty then next would point to nullptr (since top would be null)
            // and then top is now the new node
            top = newNode;
            length++; //increasing length since adding node
        }

        int pop() {
            if (isEmpty()) {
                throw underflow_error("Stack is empty.");
            }

            Node* temp = top;
            int value = top->data; // storing value of top for returning
            top = top->next; // making the new top ptr point to next node (which is the new top of stack)
            delete temp;
            length--;
            return value;


        }

        int peek() {
            if (isEmpty()){
                throw underflow_error("Stack is empty. Nothing to return");
            }
            return top->data;
        }

        bool isEmpty(){
            return top == nullptr;
        }

        int getLength() {
            return length;
        }

        // printing the contents inside the stack:
        void print() {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data;
                if (temp->next != nullptr) {
                    cout << " -> "; 
                }
                temp = temp->next;
                // because stacks are LIFO, it will print from what was last in to first in
            }
        }


};

int main() {
    // creating a stack:

    LinkedListStack stack;
    stack.push(3);
    stack.push(7);
    stack.push(74);

    stack.print();


    return -1;
}