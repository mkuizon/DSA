class Stack:
    
    def __init__(self):
        # create a new stack
        self._items = []

    def is_empty(self):
        return not bool(self._items)
        # returns false if stack is filled, true if empty
    
    def push(self,item):
        self._items.append(item)
    
    def pop(self): # remove top stack
        return self._items.pop()
    
    def peek(self): # returns the value at the top of stack
        return self._items[-1]
    
    def size(self):
        return len(self._items)
    