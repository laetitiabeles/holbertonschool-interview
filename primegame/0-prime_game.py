#!/usr/bin/python3
"""Prime game: determine winner across rounds.

Prototype: def isWinner(x, nums)

Maria always goes first. For each round with numbers 1..n, players
take turns choosing a prime and removing it and its multiples. The
player who cannot move loses. If Maria wins more rounds than Ben,
return "Maria"; if Ben wins more, return "Ben"; if tied return None.
"""

def isWinner(x, nums):
    """Return the name of the overall winner or None for a tie.

    x: number of rounds (int)
    nums: list of n values for each round
    """
    if x <= 0 or not nums:
        return None

    rounds = nums[:x]
    max_n = max(rounds)
    if max_n < 2:
        maria_wins = 0
        ben_wins = len(rounds)
    else:
        sieve = [True] * (max_n + 1)
        sieve[0:2] = [False, False]
        p = 2
        while p * p <= max_n:
            if sieve[p]:
                for i in range(p * p, max_n + 1, p):
                    sieve[i] = False
            p += 1

        maria_wins = 0
        for n in rounds:
            if n < 2:
                primes_count = 0
            else:
                primes_count = 0
                for i in range(2, n + 1):
                    if sieve[i]:
                        primes_count += 1
            if primes_count % 2 == 1:
                maria_wins += 1

        ben_wins = len(rounds) - maria_wins

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None


if __name__ == '__main__':
    # quick manual test when run directly
    print("Winner:", isWinner(5, [2, 5, 1, 4, 3]))
