"""
Jesse Plummer CISC 179 3/1/2020
program computes median, mode, and mean
of a set of numbers (these must be in
functions).  Main function will test them.
"""

def median(num):
    if len(num) == 0:
        return 0
    num.sort()
    midpoint = len(num) // 2
    if len(num) % 2 == 0 :
        return (num[midpoint] + num[midpoint-1])/2
    else:
        return num[midpoint]

def mode(num) :
    if len(num) == 0:
        return 0
    num.sort()
    mode = 0
    for i in num:
        if num.count(i) > 1:
            mode = i

    return mode

def mean(num) :
    if len(num) == 0:
        return 0
    sum = 0
    for i in num:
        sum += i
    return sum/len(num)

def main():

    userList = [3, 1, 7, 1, 4, 10]
    #userList2 = [10, 13, 78, 69, 45, 23, 32, 23]
    #userList3 = [1, 1, 2, 3, 5, 8, 13, 21]

    meanValue = mean(userList)

    medianValue = median(userList)

    modeValue = mode(userList)

    print("List: " , userList)
    print("Mode: ", modeValue)
    print("Median: ", medianValue)
    print("Mean: ", meanValue)

main()


