#!/usr/bin/python3
"""
Pascal Triangle module
"""


def pascal_triangle(n):
    """
    Pascal Triangle Function
    """
    triangle = []
    if (n <= 0):
        return []
    for row in range(1, n + 1):
        num = 1
        newRow = []
        for i in range(1, row + 1):
            newRow.append(num)
            num = int(num * (n - i) / i)
        triangle.append(newRow)
    return (triangle)
