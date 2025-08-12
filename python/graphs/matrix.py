import numpy as np

row = 3
col = 3
mastric = np.array([[1,2,3],
                   [4,5,6],
                   [7,8,9]])

print(mastric)

# iterating throught the matrix:

movements = [1,-1,1,-1]

# o(n^2) - iterating in order each col in row
for row in mastric:
    for col in row:
        print(col)

print("-----------")

# using numpt nditer
for i in np.nditer(mastric):
    print(i)

