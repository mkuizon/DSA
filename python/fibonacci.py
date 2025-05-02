def fibonacci1(n, memo={}):
    if n <= 1: 
        return n

    if n not in memo:
        memo[n] = fibonacci1(n-1,memo) + fibonacci1(n-2, memo)
    # basically returns a list of all the numbers that lead to n 
    print(memo)
    return memo[n]

def fibonacci(n):
    if n <= 1:
        return n
    dp = [0] * (n+1)
    dp[1] = 1
    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    print(dp)
    return dp[n]

print(f"{fibonacci(10) = }")  # Output: 55

#  print(f"{fibonacci1(8) = }")