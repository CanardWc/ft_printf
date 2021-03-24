#include <stdio.h>

size_t	ft_strlen(char *s)
{
	char *tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	return (tmp - s);
}

char	*ft_jsp(char *s)
{
	int	oui;
	int	i;
	char *tmp;
	int	jsp;

	s++;
	jsp = 0;
	tmp = s;
	i = 4;
	oui = 0;
	tmp += ft_strlen(s);
	while (i-- >= 0 || oui)
	{
		tmp--;
		if (oui)
		{
			jsp = 1;
			oui = 0;
		}
		if (*tmp && *tmp > '4')
			oui = 1;
		if (*tmp)
			*tmp = oui ? ((*tmp - 48) * 2) + 38 + jsp: ((*tmp - 48) * 2) + 48 + jsp;
		else
			*tmp = 48 + jsp;
		jsp = 0;
	}
	return (s - 1);
}

int main()
{
	char frac[6];


	frac[0] = 0;
	frac[1] = '9';
	frac[2] = '9';
	frac[3] = '9';
	frac[4] = '9';
	frac[5] = 0;
	printf("%s\n", ft_jsp(frac));
	return (0);
}
