accts = [["John", "email", "email2"], ["John", "email", "monster"], ["Melo", "menso", "mero"], ["Judy", "junester"], ["Melo", "mopther", "mero", "wierdo"], ['John', "jokester"]] 

# say we went through one loop
a = {0: accts[0][1:]}
final = []

names = [accts[0][0]]


def merge(a, accts, accts_index, a_index):
    for i in range(1,len(accts[accts_index])):
        if accts[accts_index][i] in a[a_index]:
            continue
        
        a[a_index].append(accts[accts_index][i])

for i in range(1, len(accts)):
    # how do we check if the current account name is a key?
    for x in list(a):
        if accts[i][0] == accts[x][0]:
            for b in range(1,len(accts[i])):
                if accts[i][b] in a[x]:
                    print("confirm")
                    merge(a,accts,i,x)
                    break
        else:
            # if its not, then add it to the hash map

            a[i] = accts[i][1:]

def finalize(final, lista, index,a):
     
    current = [a[index][0]]


    current += sorted(lista)

    final.append(current)



for i in a.keys():
    finalize(final,a[i],i,accts)


print(a)
print(f"FINAL\n{final}")
        

# sike, i have to implement a queue in some way