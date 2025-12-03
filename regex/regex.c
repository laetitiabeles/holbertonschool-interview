#include "regex.h"

static int match_here(const char *s, const char *p)
{
	if (*p == '\0')
		return (*s == '\0');

	if (*(p + 1) == '*')
	{
		if (match_here(s, p + 2))
			return 1;

		while (*s != '\0' && (*p == '.' || *s == *p))
		{
			s++;
			if (match_here(s, p + 2))
				return 1;
		}
		return 0;
	}

	if (*s != '\0' && (*p == '.' || *p == *s))
		return match_here(s + 1, p + 1);

	return 0;
}

int regex_match(char const *str, char const *pattern)
{
	if (!str)
		str = "";
	if (!pattern)
		pattern = "";

	return match_here(str, pattern) ? 1 : 0;
}
