def reverseVowels(s: str) -> str:
    vowel = ["a", "e", "i", "o", "u"]
    out = [x for x in s]
    print(out)
    # two pointers
    left = 0
    right = len(s) -1
    while left < right:

        print(f"current letter: {right} : {out[right]} | {left} : {out[left]}")


        if out[right].lower() in vowel:
            if out[left].lower() in vowel:
                # if they are both ccurrently vowels, swap
                out[right], out[left] = out[left], out[right]
                # since they both swap we can add on both
                left += 1
            else:
                left += 1
                continue
        right -= 1


    return "".join(out)

word = "icecream"

print(reverseVowels(word))

s = 'a'

s = s + 'b'

print(s)
