import math
def evalRPN(tokens):
    stack = []
    current  = 0


    for i in tokens:
    
        if i == "+":
            current = stack.pop() + stack.pop()
            stack.append(current)
        elif i == "-":
            current = stack.pop() - stack.pop()
            stack.append(current)
        elif i == "/":
            current = stack.pop()
            current = stack.pop() / current
            stack.append(int(current))
        elif i == "*":
            current = stack.pop() * stack.pop()
            stack.append(current)
        else:
            stack.append(int(i))
        
        print(stack)

    return stack[0]

tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
print(evalRPN(tokens))

'''
Want to improve the time 

'''