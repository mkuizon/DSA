#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct TreeNode {
    T value;
    TreeNode<T>* parent, *left, *right;
    TreeNode(T val, TreeNode<T>* par = nullptr)
        : value(val), parent(par), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
public:
    BinaryTree();                     // Default Constructor
    ~BinaryTree();                    // Destructor

    void Insert(T value);            // Add a value into the tree
    bool Find(T value);              // Return true if the value is found
    bool IsEmpty();                  // True if the list is currently empty
    void Preorder(ostream& out);     // Output the pre-order traversal      
    void Inorder(ostream& out);      // Output the in-order traversal      
    void Postorder(ostream& out);    // Output the post-order traversal      
    bool Remove(T value);            // Find the value and remove the value; true if successful

private:
    TreeNode<T>* root;               // Root pointer

    void clear(TreeNode<T>* node);   // helper to delete all nodes
    TreeNode<T>* insertRec(TreeNode<T>* node, T value, TreeNode<T>* parent);  // recursive insert
    TreeNode<T>* findNode(TreeNode<T>* node, T value);   // recursive find
    void preorderRec(TreeNode<T>* node, ostream& out); // recursive preorder
    void inorderRec(TreeNode<T>* node, ostream& out); // recursive inorder
    void postorderRec(TreeNode<T>* node, ostream& out);    // recursive postorder
    TreeNode<T>* findMin(TreeNode<T>* node);               // find min in right subtree
    bool removeRec(TreeNode<T>*& node, T value);           // recursive remove
};

// Default Constructor
template<typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

// Destructor
template<typename T>
BinaryTree<T>::~BinaryTree() {
    clear(root);
}

// Add a value into the tree
template<typename T>
void BinaryTree<T>::Insert(T value) {
    root = insertRec(root, value, nullptr);
}

// Return true if the value is found
template<typename T>
bool BinaryTree<T>::Find(T value) {
    return findNode(root, value) != nullptr;
}

// True if the list is currently empty
template<typename T>
bool BinaryTree<T>::IsEmpty() {
    return root == nullptr;
}

// Output the pre-order traversal      
template<typename T>
void BinaryTree<T>::Preorder(ostream& out) {
    preorderRec(root, out);
    out << endl;
}

// Output the in-order traversal      
template<typename T>
void BinaryTree<T>::Inorder(ostream& out) {
    inorderRec(root, out);
    out << endl;
}

// Output the post-order traversal      
template<typename T>
void BinaryTree<T>::Postorder(ostream& out) {
    postorderRec(root, out);
    out << endl;
}

// Find the value and remove the value; true if successful
template<typename T>
bool BinaryTree<T>::Remove(T value) {
    return removeRec(root, value);
}

// helper to delete all nodes
template<typename T>
void BinaryTree<T>::clear(TreeNode<T>* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

// recursive insert
template<typename T>
TreeNode<T>* BinaryTree<T>::insertRec(TreeNode<T>* node, T value, TreeNode<T>* parent) {
    if (!node) return new TreeNode<T>(value, parent);

    if (value < node->value)
        node->left = insertRec(node->left, value, node);
    else if (value > node->value)
        node->right = insertRec(node->right, value, node);
    return node;
}

// recursive find
template<typename T>
TreeNode<T>* BinaryTree<T>::findNode(TreeNode<T>* node, T value) {
    if (!node) return nullptr;
    if (value == node->value) return node;
    if (value < node->value)
        return findNode(node->left, value);
    else
        return findNode(node->right, value);
}

// recursive preorder
template<typename T>
void BinaryTree<T>::preorderRec(TreeNode<T>* node, ostream& out) {
    if (!node) return;
    out << node->value << " ";
    preorderRec(node->left, out);
    preorderRec(node->right, out);
}

// recursive inorder
template<typename T>
void BinaryTree<T>::inorderRec(TreeNode<T>* node, ostream& out) {
    if (!node) return;
    inorderRec(node->left, out);
    out << node->value << " ";
    inorderRec(node->right, out);
}

// recursive postorder
template<typename T>
void BinaryTree<T>::postorderRec(TreeNode<T>* node, ostream& out) {
    if (!node) return;
    postorderRec(node->left, out);
    postorderRec(node->right, out);
    out << node->value << " ";
}

// find min in right subtree
template<typename T>
TreeNode<T>* BinaryTree<T>::findMin(TreeNode<T>* node) {
    while (node && node->left) node = node->left;
    return node;
}

// recursive remove
template<typename T>
bool BinaryTree<T>::removeRec(TreeNode<T>*& node, T value) {
    if (!node) return false;

    if (value < node->value) {
        return removeRec(node->left, value);
    } else if (value > node->value) {
        return removeRec(node->right, value);
    } else {
        if (!node->left && !node->right) {
           // no child
            delete node;
            node = nullptr;
            
            
            // one child 
        } else if (!node->left) {
            TreeNode<T>* temp = node;
            node = node->right;
            delete temp;
        } else if (!node->right) {
            TreeNode<T>* temp = node;
            node = node->left;
            delete temp;
            
            // two child
        } else {
            TreeNode<T>* successor = findMin(node->right);
            node->value = successor->value;
            removeRec(node->right, successor->value);
        }
        return true;
    }
}
