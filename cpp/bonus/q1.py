

def sequence(num):
    count = 1
    while (num != 1):
        if num % 2 == 0: #even
            num = num //2
        else:
            num = (3*num) + 1
        
        count += 1
    

    return count

n = 13
print(sequence(n))

x = 1
longest = 0 
num = 0
while (x != 1234567):
     
    current = sequence(x)

    if (current > longest):
        longest = current
        num =x
    
    x += 1

print(longest)
print(num)