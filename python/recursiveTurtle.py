import turtle

#visualizing recursion

def draw_spiral(myTurtle, lenline):
    if lenline > 0:
        myTurtle.forward(lenline)
        myTurtle.right(90)
        draw_spiral(myTurtle, lenline - 5)

myTurtle = turtle.Turtle()
window = turtle.Screen()
draw_spiral(myTurtle, 100)
window.exitonclick()