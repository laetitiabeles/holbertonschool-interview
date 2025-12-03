#!/usr/bin/python3
"""
Module that provides makeChange(coins, total)

The function returns the fewest number of coins needed to reach
`total` using an unlimited number of each coin in `coins`.
If total is 0 or less -> return 0. If not possible -> return -1.
"""
from typing import List


def makeChange(coins: List[int], total: int) -> int:
    """Return the minimum number of coins needed to make `total`.

    Uses a bottom-up dynamic programming approach. Time complexity is
    O(len(coins) * total) and space O(total).
    """
    if total <= 0:
        return 0

    # dp[a] = fewest coins to make amount a; initialize with a large value
    INF = total + 1
    dp = [INF] * (total + 1)
    dp[0] = 0

    for coin in coins:
        if coin <= 0:
            # Skip invalid coin denominations (shouldn't happen per spec)
            continue
        for amount in range(coin, total + 1):
            if dp[amount - coin] + 1 < dp[amount]:
                dp[amount] = dp[amount - coin] + 1

    return dp[total] if dp[total] != INF else -1


if __name__ == "__main__":
    # quick smoke test matching the prompt examples
    print(makeChange([1, 2, 25], 37))
    print(makeChange([1256, 54, 48, 16, 102], 1453))
