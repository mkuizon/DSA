def InsertionSort(arr):
    for i in range(len(arr)):
        j = i
        while (j>0) and (arr[j]<arr[j-1]):
            arr[j],arr[j-1]=arr[j-1],arr[j]
            j -=1
        
    return arr


def shellSort(arr, gaps):
    size = len(arr)
    for gap in gaps:
        for i in range(gap):
            print(InsertionSort(arr))

arr = [46,82,62,37,12,54,49,38]
print(shellSort(arr,[5,3,1]))