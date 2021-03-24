#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_qqch(char *s, int exp)
{
	int		size;
	char	*tmp;
	int		save;
	int		add;
	int		size_s;
	int		exp_s;

	exp_s = exp;
	size_s = strlen(s);
	save = 0;
	add = 0;
	memmove(s + 340 - size_s, s, size_s);
	bzero(s, strlen(s));
	while (exp_s--)
	{
		size = size_s;
		tmp = s + 340;
		while (size-- >= 0 || save)
		{
			tmp--;
			if (save)
			{
				add = 1;
				save = 0;
			}
			if (*tmp && *tmp > '4')
				save = 1;
			if (*tmp)
				*tmp = save ? ((*tmp - 48) * 2) + 38 + add : ((*tmp - 48) * 2) + 48 + add;
			else
				*tmp = 48 + add;
			add = 0;
		}
	}
	while (!*s)
		s++;
	dprintf(1, "%s\n", tmp);
	exp = strlen(s) - size_s;
	printf("exp==%d\n", exp);
	return (tmp);
}

int main()
{
	char *s;
	char *str = "647";

	s = calloc(340, (sizeof(char)));
	memcpy(s, str, strlen(str));
	printf("%s\n", ft_qqch(s, 4));
}
