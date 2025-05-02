a = [1, 2 , 3]

# append - adding to element to end of array O(1)
a.append(4)

# a = [1, 2, 3, 4]

# pop - deleting element at the end of array O(1)
a.pop()

# insert at position - O(n) - bc it shifts the elements of the array
a.insert(2,6)
# a = [1,2,6,3] - inserts 6 but since memory sees array with
# 4 elements, the 4 goes away

# modify an element O(1)
a[0] = 7
print(a)

# accessing an array O(1)
print(a[2])

# if an element is in the array O(n)
if 7 in a:
    print(True)


#--------------
names = ["micah", "abdul", "joseph", "aiden", "rick", "nithin"]

# looping through an array = O(n)

ur_name = input("what is your name? ")

for i in names:
    if ur_name == i:
        print("Your name is in the database! ")
        break
    else:
        ans = input("add name to data base? ")
        if ans == 'y' or ans == "Y":
            names.append(ur_name)
            break
        else:
            print("name needs to be added to database!")
            break
        
        
    