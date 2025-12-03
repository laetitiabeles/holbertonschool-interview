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

    /* When s2 starts with '*', it can match any sequence (including empty) */
    if (*s2 == '*')
    {
        /* Skip consecutive '*' to avoid redundant work */
        while (*(s2 + 1) == '*')
            s2++;

        /* If '*' is the last char in s2, it matches the rest of s1 */
        if (*(s2 + 1) == '\0')
            return 1;

        /* Try to match the remainder of s2 with s1 at current or later positions */
        while (*s1)
        {
            if (wildcmp(s1, s2 + 1))
                return 1;
            s1++;
        }

        /* Also try matching empty sequence for '*' (s1 may be at '\0') */
        return wildcmp(s1, s2 + 1);
    }

    /* Normal character: must match and advance both */
    if (*s1 && *s1 == *s2)
        return wildcmp(s1 + 1, s2 + 1);

    return 0;
}
