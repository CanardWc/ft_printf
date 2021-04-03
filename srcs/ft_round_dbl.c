#include <libftprintf.h>
#include <stdio.h>

t_dbl	ft_new_decimal(t_dbl value, int size)
{
	free(value.decimal);
	//printf("coucou\n");
	value.decimal = (char *)ft_calloc(size, sizeof(char));
	if (!value.decimal)
		return (value);
	value.decimal = ft_memset(value.decimal, '0', size - 1);
	*(value.decimal) = '1';
	value.pow++;
	return (value);
}

t_dbl	ft_round_dbl(t_dbl value, int size)
{
	int	i;

	i = 0;
	while (value.decimal[i] == '9' && i < size && value.decimal[i])
		i++;
	//printf("dec = %s\n", value.decimal);
	//ft_putnbr_fd(size, 1);
	//write(1, "\n", 1);
	//ft_putnbr_fd(i, 1);
	//write(1, "\n", 1);
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
