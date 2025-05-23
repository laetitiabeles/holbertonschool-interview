#!/usr/bin/python3
"""Module to calculate the fewest number of operations
needed to result in exactly n H characters in the file"""


def minOperations(n):
    if n < 2:
        return 0
    is_prime = True
    for i in range(2, n):
        if (n % i == 0):
            is_prime = False
            break
        is_prime = True
    if (is_prime):
        return n
    else:
        count_operations = 0
        char = 1
        cache = char
    while char < n:
        if (n % (cache * 2) == 0 and n/cache >= 2):
            cache = char
            char += cache
            count_operations += 2
        elif (n % char == 0 and (char + cache) <= n):
            cache = char
            char += cache
            count_operations += 2
        else:
            char += cache
            count_operations += 1
    return count_operations
