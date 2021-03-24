#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_qqch(char *s, int exp)
{
	int		size;
	char	*tmp;
	int		save;
	int		add;

	size = strlen(s);
	memmove(s + 340 - size, s, size); //ira dans autre fonction
	bzero(s, size); // ira dans autre fonction
	while (exp--)
	{
		tmp = s + 340;
		while (*--tmp || save == 38)
		{
			add = save == 38;
			save = 48;
			if (*tmp && *tmp > '4')
				save = 38;
			if (*tmp)
				*tmp = ((*tmp - 48) * 2) + save + add;
			else
				*tmp = 48 + add;
		}
	}
	while (!*s)
		s++;
	exp = strlen(s) - size;
	return (tmp + 1);
}

int main()
{
	char *s;
	char *str = "647";

	s = calloc(340, (sizeof(char)));
	memcpy(s, str, strlen(str));
	printf("%s\n", ft_qqch(s, 9));
}
