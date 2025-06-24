#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
	BinaryTree<int> bt;
	bt.Insert(6);
	bt.Insert(2);
	bt.Insert(9);
	bt.Insert(8);
	bt.Insert(1);
	bt.Insert(4);
	bt.Insert(5);
   cout << "Inorder:" << endl;
   bt.Inorder(cout);
	bt.Remove(4);
	cout << "Preorder:" << endl;
	bt.Preorder(cout);
	bt.Remove(6);
	cout << "Postorder:" << endl;
	bt.Postorder(cout);

	return 0;
}