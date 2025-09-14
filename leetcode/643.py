def findMaxAverage(nums, k):
    '''
        returning max average value of size k
    '''
    ksum = sum(nums[:k]) # calculating the sum of the first window
    max_avg =  ksum / k # calculating the max average
    end = k
    start = 1
    while end != len(nums):
        ksum = ksum - nums[start-1] + nums[end]
        temp = ksum / k

        if temp > max_avg:
            max_avg = temp
        
        start+=1
        end+=1
    
    return max_avg

print(f"First {findMaxAverage([1,12,-5,-6,50,3], 4)}")

k = [-1]
s = 0
e = 1

print(findMaxAverage(k, e))