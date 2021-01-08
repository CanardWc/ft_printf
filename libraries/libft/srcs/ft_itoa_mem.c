#include <libft.h>

char	*ft_itoa_mem(unsigned long int nbr)
{
	char			*base = "0123456789abcdef";
	char			*dest;
	unsigned int		size;
	unsigned long int	nb;

	nb = nbr;
	size = 2;
	while (nbr > 15)
	{
		nbr = nbr >> 4;
		size++;
	}
	if (!(dest = (char *)malloc(sizeof(char) * size)))
		return (0);
	dest[--size] = '\0';
	while (nb > 15)
	{
		dest[--size] = base[nb % ft_strlen(base)];
		nb = nb >> 4;
	}
	dest[--size] = base[nb % ft_strlen(base)];
	return (dest);
}
