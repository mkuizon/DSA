

def count(amount, coins):
    dp = [0] * (amount + 1)
    dp[0] = 1

    for coin in coins:
        for i in range(coin, amount +1):
            dp[i] += dp[i - coin]
    
    return dp[amount]

coins = [1,2,5,10,20,50,100,200]
amt = 200

print(count(amt,coins))

