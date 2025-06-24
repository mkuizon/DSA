def isValid(s: str) -> bool:
    #  building t ckets = ['(','[','{']
    # closing_brackets
    brackets = {
        '(' : ')',
        '[' : ']',
        '{' : '}'
    } 

    stack = []

    for i in range(len(s)):
        # checking if the bracket is a key - the opening brackets
        if s[i] in brackets.keys():
            stack.append(s[i])  
            print(stack)
            # break # gonna break the loop to go to next
        # if the bracket is a closing bracket and it matches the top of stack - pop that stack value
        if s[i] in brackets.values():
            if s[i] == brackets[stack[len(stack)-1]]:
                stack.pop()
            else:
                return False
        
        
    if len(stack) == 0:
        return True
    else:
        return False


 

s ="()[]{}"
print(isValid(s))