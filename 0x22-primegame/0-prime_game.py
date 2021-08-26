#!/usr/bin/python3


allNumbers = {
    0: False,
    1: False,
    2: True,
}


def checkPrime(x):
    if (x in allNumbers):
        return allNumbers[x]
    for i in range(2, x):
        if (x % i) == 0:
            allNumbers[x] = False
            return False
    allNumbers[x] = True
    return True


def isWinner(x, nums):
    if (x < 1):
        return None
    if nums == []:
        return None
    Maria = 0
    Ben = 0
    for i in nums:
        primeNumbers = []
        for j in range(i + 1):
            if checkPrime(j) is True:
                primeNumbers.append(j)
        if (len(primeNumbers) % 2 == 0):
            Ben = Ben + 1
        else:
            Maria = Maria + 1
    if (Maria > Ben):
        return 'Maria'
    if (Ben > Maria):
        return 'Ben'
    return 'None'
