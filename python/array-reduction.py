import math

def arrayReduction(arr):

    i = 0
    total_cost = 0
    while i < len(arr):
        print(i)
        m = min(arr)
        x = max(arr)

        sum = m + x

        arr.remove(m)
        arr.remove(x)
        arr.append(sum)

        cost = math.ceil((m + x) / (x-m+1))
        total_cost += cost
        print(total_cost)
        print(arr)
        i += 1

    
    return total_cost

a = [1,2,3,5,6,7]
arrayReduction(a)