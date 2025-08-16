def compress(chars):
    s = ""

    count = 0 # this is the count for the current 
    idx = 0 # hmm len(s) could be used for index?
    chars.append(0)

    for i in range(len(chars)):
        if chars[idx] == chars[i]:
            count+=1
        
        else:
            # if it is different, we need to append the current letter, and the count
            s += str(chars[idx]) + str(count)

            count = 1
            idx = i
    
    for i in range(len(s)):
        chars[i] = s[i]


    return len(s)

chars = ["a","a","b","b","c","c","c"]
print(chars[:compress(chars)])
