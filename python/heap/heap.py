class BinaryHeap: # MIN HEAP - can be used as priority queue
    def __init__(self):
        self.heap = []

    def percolateUp(self, i):
        while (i - 1) // 2 >= 0: 
            # the heap is being created using a list:
            # [parent root, child, child, grandchild(child 1 child), grandchild(child 1), grandchild(child2)]
            # to find index of parent:
            parent_idx = (i-1) //2
            # we need to check if parent is greater or not
            if self.heap[i] < self.head[parent_idx]:
                # if the parent is larger than i(child), swap them
                self.heap[i], self.heap[parent_idx] = self.heap[parent_idx], self.heap[i]
            
            # setting i as parent now, since we swapped
            i = parent_idx

    def insert(self, item):
        self.heap.append(item) # gets appended to the end of the list
        self.percolateUp(len(self.heap) - 1) # index of what was just inserted

    def percolateDown(self, i):
        while 2 * i + 1 < len(self.heap):
            # getting their smaller child
            smaller_child = self.get_min_child(i)

            if self.heap[i] > self.heap[smaller_child]:
                # swap them
                self.heap[i], self.heap[smaller_child] = self.heap[smaller_child], self.heap[i]

            else:
                break

            i = smaller_child

    def get_min_child(self, i):
        if 1 +i +2> len(self.heap) - 1:
            # if second child is greater than last index, if there is only one child
            return 2 * i +1 # return that child
        

        if self.heap[2*i+1] < self.heap[2*i+2]:
            # if child 1 is less than child 2
            return 2 * i +1 # return child 1
        
        return 2 * i + 2
    


    def delete(self):
        self.heap[0], self.heap[-1] = self.heap[-1], self.heap[0]
        result = self.heap.pop()
        self.percolateDown(0)
        return result
    

    def heapify (self, not_heap):
        self.heap = not_heap[:]

        i = len(self.heap) //2 -1

        while i>=0:
            self.percolateDown(i)
            i = i -1

    def is_empty(self):
        return not bool(self.heap)
        
    
a_heap = BinaryHeap()
a_heap.heapify([9, 5, 6, 2, 3])

while not a_heap.is_empty():
    print(a_heap.delete())