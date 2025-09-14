def largestAltitude(gain):
    
    gains = [0]
    gains.extend(gain)
    highest = 0 # setting 0 as highest since its the starting point

    for i in range(1,len(gains)):

        current = gains[i-1] + gains[i]
        gains[i] = current

        if current > highest:
            highest = current

    return highest


gain = [-4,-3,-2,-1,4,3,2]
print(largestAltitude(gain))


gains = [0]
gains.extend(gain)
print(gains)