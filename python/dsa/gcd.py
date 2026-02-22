def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
    
a= 8
b= 12
print(gcd(a,b))