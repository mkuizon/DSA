def binaryTreePaths(root):
        # find all root to leaf paths

        paths = []

        def traverse(root, stri, paths):
            if root == None:
                paths.append(stri) # append the current string since root is none and go backwards
                return

            
            if root.left == None or root.right == None: 
                stri += str(root.val)
            else: # if it does have kids
                stri += str(root.val) + "->"
            
            traverse(root.left, stri, paths)
            traverse(root.right,stri, paths)

        stri = ""
        traverse(root, stri, paths)

        return paths

