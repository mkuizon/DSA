#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    // Node() : data(0), left(nullptr), right {}
    // Node(int x) : data(x), right(nullptr) {}
    // Node(int x, Node *left) : data(x), next(next) {}
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


Node* insert(Node* root, int data) {
    if (root == nullptr) {
        root = new Node(data);
        return root; // when we return we point to that address
    }

    else if (data <= root->data) {
        root->left = insert(root->left,data);
        // here were checking if the root (curr node) is greater than - so we make
        // a left child, we create new node for left child and when it is returned
        // the root is pointing to the left child
    }

    else if (data >= root->data) {
        root->right = insert(root->right,data);
    }
    
    return root;
    

}

Node* PreOrder(Node* root) { // preorder traversal
    // ex creating copy of tree
    if (root == nullptr) {
        return root;
    }
    cout << root->data << endl;
    root->left = PreOrder(root->left);
    root->right = PreOrder(root->right);
}

Node* PostOrder(Node* root) { 
    // like for deleting the tree
    if (root == nullptr) {
        return root;
    }

    root->left = PreOrder(root->left);
    root->right = PreOrder(root->right);

    cout << root->data << endl;
}

Node* InOrder(Node* root)  {
    // when u want a sorted order of BST
    if (root == nullptr) {
        return root;
    }

    root->left = PreOrder(root->left);

    cout << root->data << endl;
    root->right = PreOrder(root->right);
}

Node* LevelOrder(Node* root) {
    // process
    if (root == nullptr) {return root;}
    queue<Node*> Q;

    while (!Q.empty()) {
        Node* current = Q.front();
        cout << current->data << " ";
        if (current->left != nullptr) Q.push(current->left);
        if (current->right != nullptr) Q.push(current->right);
        Q.pop();
    }
}
Node* Delete(Node* root, int data) {
    
    if (root == nullptr) { // this is the base case
        return root; // when there is no tree
    }

    else if (data < root->data) {
        root->left = Delete(root->left, data);
    }

    else if (data > root->data) {
        root->right = Delete(root->right, data);
    }

    else { // here is when we finally find the data durign the recursive call
        if (root->left == nullptr && root->right == nullptr) {
            // case 1: there is no child
            delete root;
            root = nullptr;
            return root;

        // case 2: one child
        } else if (root->left == nullptr) { // if the left child is null, were going to make this current 
            // node be the right child now - basically delete current(found) node and moving right child subtree up
            struct Node* temp = root;
            root = root->right; // were going to the right child
            delete temp;
            return root;
        } else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left; // going to the left chiild]
            delete temp;// deleteing the prev root which the address is now stored in temp
            return root; // were returning the left child now
        }
        // case 3: 2 children
        else {
            Node* temp = FindMin(root->right); // here we have to find the min child of this root
            root->data = temp->data; // replacing the node with min child
            root->right = Delete(root->right, temp->data); // deleting that min child of rightchild
        }   
          
    }

    return root;
}

//
Node* FindMin(Node* root) {
    // the min will always be on the left side in a BST
    // we find the min of the right child bc
    // it will always be less than all of the right child successors
    // and more than all of left
    while (root->left != nullptr) { // check if left child is null
        // while it isnt null we keep going
        root = root->left;

        // once the next left child is null itll stop and return that current node
    }

    return root;
}
int main() {
    cout << "testing testing" << endl;

    Node* root = nullptr; // creating an empty tree


}   