#!/usr/bin/python3
import sys


def checkSafe(queens, x, y):
    for z in queens:
        if (z[0] == x or z[1] == y):
            return False
        i = x
        c = y
        while i >= 0 and c >= 0:
            if z[0] == i and z[1] == c:
                return False
            i = i - 1
            c = c - 1
        i = x
        c = y
        while x >= 0 and i < sys.argv[1]:
            if z[0] == i and z[1] == c:
                return False
            i = i + 1
            c = c - 1
    return True


def solveNQueens(queens, y):
    if len(queens) == sys.argv[1]:
        print(queens)
        return True
    res = False
    for x in range(sys.argv[1]):
        if checkSafe(queens, x, y):
            queens.append([x, y])
            res = False
            if (solveNQueens(queens, y + 1)):
                res = True
            queens.pop()
    return res


def starter():
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)
    try:
        sys.argv[1] = int(sys.argv[1])
    except ValueError as e:
        print('N must be a number')
        exit(1)
    if sys.argv[1] < 4:
        print('N must be at least 4')
        exit(1)
    queens = []
    solveNQueens(queens, 0)


starter()
