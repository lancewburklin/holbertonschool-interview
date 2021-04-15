#!/usr/bin/python3
""" Rain module """


def rain(walls):
    """ Calculate the rain buildup between walls """
    if len(walls) == 0 or len(walls) == 1 or len(walls) == 2:
        return 0
    i = 1
    x = 3
    max = i
    max_2 = i
    total = 0
    while x < len(walls) + 1:
        if walls[x] >= walls[max]:
            max_2 = max
            max = x
        elif walls[x] > walls[max_2]:
            max_2 = x
        if x != 0 and i != 0:
            total += x - i
        i += 2
        x += 2
    mheight = walls[max_2]
    i = max_2 + 1
    total_2 = ((max - 1) - (max_2))
    total_2 = total_2 * walls[max_2]
    while i < max:
        total_2 -= walls[i]
        i += 1
    if total_2 > total:
        return total_2
    return total
