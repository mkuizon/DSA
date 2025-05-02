def binaryRecursion(arr, item):
    if len(arr) == 0:
        return False # if there is nothing in the list
    
    mid = len(arr) // 2
    if arr[mid] == item:
        return True
    elif item < arr[mid]:
        # so checkingn from the first to mid
        return binaryRecursion(arr[:mid], item)
    else:
        return binaryRecursion(arr[mid + 1:], item)
    
test_list = [0, 1, 2, 8, 13, 17, 19, 32, 42]
find1 = 4
find = 19
print(binaryRecursion(test_list, find1)) # returns ralse - not in list
print(binaryRecursion(test_list, find)) # returns true - in list