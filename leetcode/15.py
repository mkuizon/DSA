def threesum(nums):
    nums.sort()
    triplets = []
    for i in range(len(nums)-2):
        # iterating through array, making sure to be within the index
        if nums[i] > 0:
            break # since the array is sorted. if the first index is > 0, it wont equal 0

        if i > 0 and nums[i] == nums[i-1]: # skipping duplicates of i
            # skipping duplicates so that the other pointers can touch them
            continue

        # two pointers to navigate the array
        #left moves towards the end, right moves inward
        left, right = i + 1, len(nums) -1
        
        while left < right:
            sum = nums[i] + nums[left] + nums[right] # calculating the current sum
            if sum < 0: # if sum is less than, then we need a larger number, so left moves
                left +=1
            elif sum > 0: # if sum is greater than, we need a smaller number, right moves
                right -= 1
            else:
                # if it ==0, append the numbers to resulting array
                triplets.append([nums[i],nums[left],nums[right]]) 
                # continuing the search for more triplets in this index i
                left,right = left+1, right -1

                while left < right and nums[left] == nums[left-1]:
                    left+=1
                
                while left < right and nums[right] == nums[right+1]:
                    right-=1

        


    return triplets

         

nums = [-1,0,1,2,-1,-4]
print(threesum(nums))
print("hell yeah")