class Queue:
    def __innit__(self):
        self._items = []
    
    def is_empty(self):
        return not bool(self._items)
    
    def enqueue(self, item):
        self._items.insert(0, item)
    
    def dequeue(self):
        return self._items.pop()
    
    def size(self):
        return len(self._items)
    