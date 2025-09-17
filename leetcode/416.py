
def spiralOrder(matrix):
    n = len(matrix) # rows
    m = len(matrix[0]) # columns
    left = 0
    right = m - 1
    top = 0
    bottom = n - 1
    ans = []

    while top <= bottom and left <= right:
    # top
        for i in range(left,right+1):
            print(matrix[top][i])
            ans.append(matrix[top][i])
        top+=1
        # right
        for i in range(top,bottom+1):
            print(matrix[i][right])
            ans.append(matrix[i][right])
        right-=1
        # bottom
        if top <= bottom:
            for i in range(right,left-1, -1):
                print(matrix[bottom][i])
                ans.append(matrix[bottom][i])
            bottom -=1 
        # left
        if left <= right:
            for i in range(bottom, top-1, -1):
                print(matrix[i][left])
                ans.append(matrix[i][left])
            left+=1

    return ans


matrix = [[1,2,3],[4,5,6],[7,8,9]]

print(spiralOrder(matrix))
