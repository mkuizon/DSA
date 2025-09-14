def recur_perm(i, arr, ans):
    #base case: - if we're at the last index
    if len(arr) == i:
        ans.append(arr[:]) # doing arr[:] - you are appending the amended array and not appending the original array - basically creating a shallow copy 
        return
    
    #swap all possible indices and recur
    for ia in range(i, len(arr)):
        # first case: i = 1, ia = 1 - so 1 stays
        arr[i], arr[ia] = arr[ia], arr[i] # 1,2,3
        # recursion for the next index
        recur_perm(i + 1, arr, ans) # go into next: i = 1, arr, ans -> loop from 2 - 3 - just 2. and then 3 so first would be 1,2,3
        arr[i], arr[ia] = arr[ia], arr[i]
        '''
        
        so then next would be 2. 
         > 1 and 2 swaps = 2,1
         > recur which is 3 - 2,1,3
        
        
        
        '''

def perm(arr):
    

    permutations = [] # to store all the permutations in a

    recur_perm(0, arr, permutations)

    return permutations


i = [1,2,3]

# print(perm(i))


'''
the goal here is to find all permutations of the array

'''