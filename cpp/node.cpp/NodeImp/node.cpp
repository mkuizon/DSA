#include <iostream>
using namespace std;
#include <unordered_set>

struct Node {
    int value;
    Node* next;

};

// finding the difference in two linked lists
// assuming value only shows up once in lists
Node* findDifference(Node* list1, Node* list2) {
    Node* current, *working = nullptr;
    bool unique = false, unique2 = false;
    //int holder;
    while (list1 != nullptr) {
        unique = true; // we assume 1 is unique atm
        current = list2;
        while (current != nullptr) {
            // check is node from list1 is unique
            if (list1->value == current->value) {
                unique = false; // list1 node is not unique
              //  holder = list1->value; // holding the value that is not unique 
                break;
            }

            // if (list2->value){

            // }
        }

        if (unique == true){
            working = list1;
            working->next = nullptr;
            working = working->next;
        }

        list1 = list1->next;
    }

    while (list2 != nullptr) {
        current = working;

        while (current!=nullptr) {
            if (current->value != list2->value) {
                working->next = nullptr;
                working = working->next;
                working = list2;
            }

        }
        list2 = list2->next;
    }
    return working;


}


// Regular function to safely delete a node only if it hasn't been deleted yet.
void safeDelete(Node* ptr, unordered_set<Node*>& freed) {
    if (ptr && freed.find(ptr) == freed.end()) {
        delete ptr;
        freed.insert(ptr);
    }
}

int main() {
    // --- Create list 1 ---
    Node* trial = new Node;
    trial->value = 1;
    trial->next = nullptr;

    Node* n = new Node;
    n->value = 3;
    trial->next = n;
    n->next = nullptr;

    Node* m = new Node;
    m->value = 2;
    n->next = m;
    m->next = nullptr;

    Node* o = new Node;
    o->value = 5;
    m->next = o;
    o->next = nullptr;
    
    // --- Create list 2 ---
    Node* t = new Node;
    t->value = 1;
    t->next = nullptr;
    
    Node* u = new Node;
    u->value = 6;
    t->next = u;
    u->next = nullptr;  

    Node* v = new Node;
    v->value = 2;
    v->next = o;  // Reuse node o from list 1

    Node* w = new Node;
    w->value = 5;
    // For demonstration, we link w to o as well.
    w->next = o;

    Node* x = new Node;
    x->value = 7;
    x->next = nullptr;
    // (Note: The code sets w->next to o twice, which might be a mistake. Adjust as needed.)

    // --- Print list 1 ---
    {
        Node* curr = trial;  // Use a temporary pointer to traverse
        while (curr != nullptr) {
            cout << curr->value;
            if (curr->next == nullptr)
                cout << "\n";
            else{
                cout << " -> ";
            }
            curr = curr->next;
        }
        cout << endl;
    }

    // --- Print list 2 ---
    {
        Node* curr = t;  // Use a temporary pointer to traverse list 2
        while (curr != nullptr) {
            cout << curr->value;
            if (curr->next != nullptr)
                cout << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }

    // --- Free Memory ---
    // Use an unordered_set to record which nodes have been deleted.
    unordered_set<Node*> freed;

    // Delete nodes in list 1:
    {
        Node* curr = trial;
        while (curr != nullptr) {
            Node* next = curr->next;
            safeDelete(curr, freed);
            curr = next;
        }
    }

    // Delete nodes in list 2:
    {
        Node* curr = t;
        while (curr != nullptr) {
            Node* next = curr->next;
            safeDelete(curr, freed);
            curr = next;
        }
    }

    // Also, delete the nodes that were created but never inserted into any list chain.
    safeDelete(u, freed);
    safeDelete(v, freed);
    safeDelete(w, freed);
    safeDelete(x, freed);

    return 0;
}
