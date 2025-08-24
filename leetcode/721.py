accts = [["John", "email", "email2"], ["John", "email", "monster"]] 

# say we went through one loop
a = {0: ["email", "email2"]}

def merge(a, accts):
    for i in range(1,len(accts[1])):
        if accts[1][i] in a[0]:
            continue
        
        a[0].append(accts[1][i])

if accts[0][0] == accts[1][0]:
    # loop through the emails
    for i in range(1,len(accts[1])):
        if accts[1][i] in a[0]:
            print("confirm")
            merge(a,accts)
            break
        
print(a)
        