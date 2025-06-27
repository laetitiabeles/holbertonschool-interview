#!/usr/bin/python3
"""
module rain
"""


def rain(walls):
    """Calculate how much water will be retained after it rains"""
    if not walls:
        return 0

    n = len(walls)
    left = [0] * n
    right = [0] * n

    left[0] = walls[0]
    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])

    right[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])

    water = 0
    for i in range(n):
        water += min(left[i], right[i]) - walls[i]

    return water
