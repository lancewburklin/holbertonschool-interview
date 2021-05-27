#!/usr/bin/python3


def rotate_2d_matrix(matrix):
    size = len(matrix[0])
    for i in range(size // 2):
        for x in range(i, size - i - 1):
            temp = matrix[i][x]
            matrix[i][x] = matrix[size - 1 - x][i]
            matrix[size - 1 - x][i] = matrix[size - 1 - i][size - 1 - x]
            matrix[size - 1 - i][size - 1 - x] = matrix[x][size - 1 - i]
            matrix[x][size - 1 - i] = temp
