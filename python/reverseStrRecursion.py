def rreverse(s):
    # base case
    if s == "":
        return s
    if s == s[::-1]:
        return True
    else:
        return rreverse(s[1:]) + s[0]

s = "micahg"
print(s)
print(s[::-1])

print(f"recursive check: {rreverse(s)}")

print("------------")
1`                      2`