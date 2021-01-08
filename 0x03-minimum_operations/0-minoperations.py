#!/usr/bin/python3

"""
Finding the minimum operations
"""


def minOperations(n):
    res = 0
    i = 0
    while i < n:
    	if n % 2 == 0:
    		n = n // 2
    		res += 2
    	else:
    		break
    for x in range(3, n+1, 2):
        while n % x == 0:
            res += x
            n = n // x
    return res
