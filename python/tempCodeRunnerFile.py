n = [123,312,43,1,3,4]

print(f"original list: {n}")
# bubble sort
lenn = len(n)
for i in range(lenn-1, 0, -1):
    for j in range(i):
        if n[j] > n[j+1]:
            n[j], n[j+1] = n[j+1], n[j]

print(f"sorted list: {n}")

# test
new = [12,432,4,13,5]
# switchingposition
print(new)
new[1], new[2] = new[2], new[1]
print(new)