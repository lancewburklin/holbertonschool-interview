#!/usr/bin/python3


def makeChange(coins, total):
    if (total <= 0):
        return 0
    count = [-1 for i in range(0, total + 1)]
    for i in coins:
        if i > len(count) - 1:
            continue
        count[i] = 1
        for j in range(i + 1, total + 1):
            if count[j - i] == -1:
                continue
            elif count[j] == -1:
                count[j] = count[j - 1] + 1
            else:
                count[j] = min(count[j], count[j - i] + 1)
    return count[total]
