def commonPrefix(words):
    min_length = float('inf')

    for word in words:
        if len(word) < min_length:
            # finding the length always overrights the infinity
            min_length = len(word)

    i= 0
    while i < min_length:
        for word in words:
            if word[i] != words[0][i]:
                return word[:1]
        i +=1

    return word[:i]