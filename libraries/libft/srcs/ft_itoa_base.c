#include <libft.h>

char	*itoa_base(int nbr, char *base)
{
	char		*dest;
	unsigned int	size;
	unsigned int	nb;

	nb = (nbr < 0 ? nbr * -1 : nbr);
	size = (nbr < 0 ? 3 : 2);
	nbr = (nbr < 0 ? nbr * -1 : nbr);
	while (nbr > ft_strlen(base) - 1)
	{
		nbr /= ft_strlen(base);
		size++;
	}
	if (!(dest = (char *)malloc(sizeof(char) * size)))
		return (0);
	dest[--size] = '\0';
	while (nb > ft_strlen(base) - 1)
	{
		dest[--size] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	dest[--size] = base[nb % ft_strlen(base)];
	if (--size == 0)
		dest[0] = '-';
	return (dest);
}
