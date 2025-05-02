#append to end of string - O(n)
s = 'hello'
b = s + 'z'
print(b)

# check if something in string
if 'f' in s:
    print(True)

#finding length is O(1)
#len(str)

for i in range(len(s)):
    print(s[i])

rest = 2
print(s[2::]) 

a = "abcdef"
b = "abc"

if b in a:
    print(True)
else:
    print(False)
print(len(b)%len(a))
print(a[(len(b)%len(a)):])
print("-----------")
#base_case
def GCD_Strings(a, b):
    if a + b != b + a:
        return ""
    if len(a) == len(b):
        return a
    if len(a) > len(b):
        return GCD_Strings(a[len(b):], b)
    return GCD_Strings(b[len(a):], a)

print('test')

GCD_Strings(a,b)

print("-----------")

    
