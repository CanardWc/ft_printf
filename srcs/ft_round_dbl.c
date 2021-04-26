#include <libftprintf.h>
#include <stdio.h>

t_dbl	ft_new_decimal(t_dbl value, int size)
{
	free(value.decimal);
	value.decimal = NULL;
	//printf("coucou\n");
	if (size == 0)
	{
		value.decimal = (char *)ft_calloc(2, sizeof(char));
		*(value.decimal) = '1';
	}
	else
	{
		value.decimal = (char *)ft_calloc(size, sizeof(char));
		if (!value.decimal)
			return (value);
		value.decimal = ft_memset(value.decimal, '0', size - 1);
		*(value.decimal) = '1';
	}
	//	dprintf(1, "value.decimal==%s\n", value.decimal);
	value.pow++;
	return (value);
}

int		ft_check_bankers(char *s)
{
	while (*++s)
		if (*s != '0' && *s)
			return (0);
	return (1);
}

void	ft_bankers_rounding(char *s, int i)
{
	s[i - 1] = s[i - 1] + 1;
	s[i] = '0';
}

t_dbl	ft_round_dbl(t_dbl value, int size)
{
	int	i;

	i = 0;
	if (value.decimal[size] == '5')
	{
		if (ft_check_bankers(value.decimal + size))
		{
			if (ft_strchr("13579", value.decimal[size - 1]))
				ft_bankers_rounding(value.decimal, size);
			return (value);
		}
	}
	while (value.decimal[i] == '9' && i < size && value.decimal[i])
		i++;
	if (!value.decimal[i])
		return (value);
	if (i == size && value.decimal[i] > '4')
		return (ft_new_decimal(value, size));
	if (value.decimal[size] > '4')
	{
		while (value.decimal[--size] == '9' && size)
			value.decimal[size] = '0';
		value.decimal[size]++;
	}
	return (value);
}
