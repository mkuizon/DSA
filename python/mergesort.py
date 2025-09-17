def merge(s1,s2,s):
    # this is where the two sorted arrays are placed together to merge
    i = j = 0

    while i+j < len(s):
        if j == len(s2) or (i < len(s1) and s1[i] <= s2[j]):
            s[i+j] = s1[i]
            i+=1
        else:
            s[i+j] = s2[j]
            j+=1
    

def merge_sort(s):
    n = len(s)
    if n < 2:
        return # list is already sorted
    
    # divide
    mid = n//2

    s1 = s[0:mid] # copying the first half
    s2 = s[mid:n] # copying the second half

    #conquer with recursion
    merge_sort(s1) # sort copy of first half
    merge_sort(s2) # sort second half

    # merge the results
    merge(s1,s2,s)

    return s

s = [1,34,64,2,8,4,101,7]
print(merge_sort(s))
    
