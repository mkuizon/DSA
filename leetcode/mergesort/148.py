class Node:
    def __init__(self, x):
        self.data = x
        self.next = None
    
def split(head):
    fast = head # moving two steps
    slow = head # moving one step

    while fast.next and fast.next.next:
        fast = fast.next.next # moves two steps ahead of list
        slow = slow.next # will hit the middle of list

    second = slow.next # start of second half
    slow.next = None # disconnects first half and secondn half
    return second

def merge(first, second):
    
    # if either linked list is empty
    if not first:
        return second
    if not second:
        return first
    
    if first.data < second.data:
        first.next = merge(first.next, second)
        return first
    else:
        second.next = merge(first, second.next)
        return second
    
def mergeSort(head):

    # base case: if list is empty or one node size

    if not head or not head.next:
        return head
    
    # divide into halves

    second = split(head)

    # recursive conquer each half
    head = mergeSort(head)
    second = mergeSort(second)

    return merge(head,second)

def merge_sort():
    pass

if __name__ == "__main__":

    head = Node(13)
    head.next = Node(1)
    head.next.next = Node(5)
    head.next.next.next = Node(17)

    head = mergeSort(head)
    
    curr = head
    while curr != None:
        print(curr.data, end=" ")
        if curr.next:
            print("->", end=" ")
        curr = curr.next
