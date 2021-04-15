#!/usr/bin/python3
""" Rain module """


def rain(walls):
    """ Calculate the rain buildup between walls """
    if len(walls) == 0 or len(walls) == 1 or len(walls) == 2:
        return 0
    i = 1
    x = 3
    total = 0
    while x < len(walls) + 1:
        if x != 0 and i != 0:
            total += x - i
        i += 2
        x += 2
    return total
