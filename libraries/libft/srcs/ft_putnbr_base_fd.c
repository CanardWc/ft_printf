#include <libft.h>

unsigned int	check(char *str)
{
	unsigned int	i;

	while (*str)
	{
		i = 1;
		if (*str == '-' || *str == '+')
			return (1);
		while (str[i])
			if (*str == str[i++])
				return (1);
		str++;
	}
	return (0);
}

void			ft_putnbr_base_fd(unsigned long long nbr, char *base, int fd)
{
	unsigned int	s;

	if ((s = ft_strlen(base)) < 2 || check(base))
		return ;
	if (nbr > (s - 1))
		ft_putnbr_base_fd(nbr / s, base, fd);
	write(fd, &base[nbr % s], 1);
}
