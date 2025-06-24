class ListNode:
    def __init__(self,x):
        self.val = x
        self.next = None

def hasCycle(head):

    checks = {}
    while head:
        checks[head.val] += 1
        head = head.next

    return any(x > 1 for x in checks.values())

dummy = ListNode(-1)
head = ListNode(3)
dummy.next = head
dummy = dummy.next
h2 = ListNode(2)
head = head.next
head = h2
head = head.next
head = ListNode(0)
head = head.next
head = ListNode(4)
head.next = h2

print(hasCycle(dummy))