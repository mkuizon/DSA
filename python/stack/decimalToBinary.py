from stack import Stack

def divide_by_two(num):
    s = Stack()
    '''so basically we have our number , num that we're
    converting to binary. 


    '''
    while num > 0:
        remain = num % 2
        s.push(remain)
        num = num // 2 # make sure to also change the num itself

    binaryNum = ""

    # while there are items in stack
    while not s.is_empty():
        binaryNum = binaryNum + str(s.pop())

    return binaryNum

print(divide_by_two(233))
print(1%26)