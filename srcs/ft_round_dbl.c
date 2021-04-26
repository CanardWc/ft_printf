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

t_dbl	ft_round_dbl(t_dbl value, int size)
{
	int	i;

	i = 0;
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
