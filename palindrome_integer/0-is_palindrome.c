#include "palindrome.h"

int is_palindrome(unsigned long n)
{
    unsigned long div = 1;

    if (n < 10)
        return (1);

    /* compute the largest divisor to extract leading digit */
    while (n / div >= 10)
        div *= 10;

    while (n != 0)
    {
        unsigned long leading = n / div;
        unsigned long trailing = n % 10;

        if (leading != trailing)
            return (0);

        /* remove leading and trailing digits */
        n = (n % div) / 10;
        div /= 100;
    }

    return (1);
}
