def calc(grades):
    
    hw = grades[0] * .25
    lab = grades[1] * .2
    reading = grades[3] * .05
    e1 = grades[2] * .1
    e2 = grades[4] * .2
    final = grades[5] *.2

    if grades[5] > grades[4] and grades[5] > grades[2]:
       e1 = grades[2] * .05
       e2 = grades[4] * .15
       final = grades[5] *.3
       print(f"exam grades {e1} {e2} {final}")
    # if final is greated than e2 but less than e1
    elif grades[5] > grades[4] and grades[5] < grades[2]:
       e1 = grades[2] * .1
       e2 = grades[4] * .15
       final = grades[5] *.25
       print(f"exam grades {e1} {e2} {final}")
    # if final is greater and than e1 but less than e2
    elif grades[5] < grades[4] and grades[5] > grades[2]:
        e1 = grades[2] * .5
        e2 = grades[4] * .20
        final = grades[5] *.25
        print(f"exam grades {e1} {e2} {final}")

    gfinal = hw + lab + reading + e1 + e2 + final
    return gfinal
kattis = 16 * 0.5
spring = 10
eval = 5
grades = [100, 97.73, 27.4,94.72, 80, 23]
    
print(calc(grades))
