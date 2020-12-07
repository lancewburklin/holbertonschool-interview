#!/usr/bin/python3


def canUnlockAll(boxes):
    num = len(boxes)
    if num <= 1:
        return True
    tester = []
    for i in range(num):
        tester.append(False)
    tester[0] = True
    flag = 0
    while flag == 0:
        flag = 1
        for i in range(num):
            for x in boxes[i]:
                if tester[i] == True:
                    if tester[x] == False:
                    	tester[x] = True
                    	flag = 0
    if False in tester:
        return False
    return True
