#!/usr/bin/python3
"""
File for finding the perimeter
"""


def island_perimeter(grid):
    """The perimeter function """
    total = 0
    for i in range(len(grid)):
        for x in range(len(grid[i])):
            if (grid[i][x] == 1):
                total = total + 4
                if (i - 1 != -1):
                    if (grid[i - 1][x] == 1):
                        total = total - 2
                if (x - 1 != -1):
                    if (grid[i][x - 1] == 1):
                        total = total - 2
    return total
