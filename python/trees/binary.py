'''
Implementation of a regular ol binary tree

'''

class BinaryTree:
    def __init__(self, root_obj): # parameter is the initial root
        self.key = root_obj
        self.left = None
        self.right = None   
    #constructors instantiate a class and set up the object's initial state
    #think of the python class constructor as the node struct in cpp

    def insert_left(self, new_node):
        if self.left is None:
            self.left = BinaryTree(new_node)
        else:
            new_child = BinaryTree(new_node)
            new_child.left = self.left
            self.left = new_child

    def insert_right(self, new_node):
        if self.right is None:
            self.right = BinaryTree(new_node)
        else: # if the node already exists, we push the the exisitng chid down one level in the tree
            new_child = BinaryTree(new_node) # setting up a new node
            new_child = self.right 
            self.right= new_child

    def get_root_val(self):
        return self.key

    def set_root_val(self, new_obj):
        self.key = new_obj

    def get_left_child(self):
        return self.left_child

    def get_right_child(self):
        return self.right_child
    
    def preorder(self, tree):
        if tree:
            print(self.key)
    

tree = BinaryTree("a")
print(tree.get_root_val())
tree.insert_left("b")

