#include "holberton.h"

/**
 * wildcmp - compares two strings where s2 can contain the wildcard '*'
 * @s1: first string
 * @s2: second string (may contain '*')
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
    /* If we reached end of s2, strings match only if s1 also ended */
    if (*s2 == '\0')
        return (*s1 == '\0');

    /* If current char of s2 is '*', try two recursive options:
     * 1) treat '*' as matching empty: advance s2
     * 2) if s1 not at end, consume one char from s1 and keep s2
     * This eliminates any loops by using recursion only.
     */
    if (*s2 == '*')
    {
        if (wildcmp(s1, s2 + 1))
            return 1;
        if (*s1 && wildcmp(s1 + 1, s2))
            return 1;
        return 0;
    }

    /* Normal character: must match and advance both */
    if (*s1 && *s1 == *s2)
        return wildcmp(s1 + 1, s2 + 1);

    return 0;
}
