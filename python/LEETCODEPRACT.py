word1 = "ab"
word2 = "pqrs"
len1 = len(word1)
len2 = len(word2)
use = 0

#whichever length is longer is what we want to use
if len1 > len2:
    use = len2
    usew = word1 # this is the word to add the rest of
else:
    use = len1
    usew = word2
print(use)
new = ""
for i in range(use):
    new += word1[i]
    new += word2[i]

print(new + usew[use:]) # continuing from index to the rest of the letters