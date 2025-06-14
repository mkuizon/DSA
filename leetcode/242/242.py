def isAnagram(s,t):
    letters = {}
    for i in s:
        if i not in letters:
            letters[i] = 1
        else:
            letters[i] += 1
    
    for i in t:
        if i in letters:
            letters[i] -= 1
    

    return True if any(value > 0 for value in letters.values()) else False

s = "o"
t = 'noo'
print(isAnagram(s,t)) 