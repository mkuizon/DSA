def rob(nums):
        n = len(nums)
        dp = [0] * len(nums)
        dp[0] = nums[0] # its the only house, so rob it
        if n >= 2: # only covers more than two houses
            dp[1] = max(dp[0], nums[1]) # determine if rob the first or the second house
            
            for i in range(2, len(nums)):
                dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        
        return dp[len(nums)-1]

nums = [1,2,3,1]
