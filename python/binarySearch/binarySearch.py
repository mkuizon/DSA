# list has to be sorted already
print("Binary Search: ")

def binary_search(a_list, item):
    first = 0
    last = len(a_list) - 1

    while first <= last:
        midpoint = (first + last) // 2
        if a_list[midpoint] == item:
            return True
        elif item < a_list[midpoint]:
            last = midpoint - 1
        else:
            first = midpoint + 1

    return False

arr = [1,2,3,4,5,6,7,8,9]
find = 4
print(binary_search(arr, find)) 
