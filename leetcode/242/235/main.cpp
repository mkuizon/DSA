#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < root->val && q->val < root->val) {
        // Both nodes are in the left subtree
        return lowestCommonAncestor(root->left, p, q);
    }

    if (p->val > root->val && q->val > root->val) {
        // Both nodes are in the right subtree
        return lowestCommonAncestor(root->right, p, q);
    }

    // If split happens here, root is the LCA
    return root;
}


int main() {


    // creating binary tree
        // Level 0
    TreeNode* root = new TreeNode(6);

    // Level 1
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    // Level 2
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    // Level 3
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    // Confirm tree construction (in-order traversal)
    // function<void(TreeNode*)> inorder = [&](TreeNode* node) {
    //     if (!node) return;
    //     inorder(node->left);
    //     cout << node->val << " ";
    //     inorder(node->right);
    // };

    // cout << "Inorder traversal: ";
    // inorder(root);  // Should print: 0 2 3 4 5 6 7 8 9
    // cout << endl;


    TreeNode* lca = lowestCommonAncestor(root, root->left, root->left->right); // LCA of 2 and 4
    cout << "LCA value: " << lca->val << endl;



    return 0;
}