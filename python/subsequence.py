
def isSubsequence(s,t):
    s_length = len(s)
    t_length = len(t)

    if s == "":
        print(True)
    elif t == "":
        print(False)

    count = 0
    for i in range(t_length):
        if s[count] == t[i]:
            count += 1
            if count == s_length:
                return True
                
        
    
    return False

a = "b"
b="abc"
isSubsequence(a,b)