#include <libftprintf.h>
#include <stdio.h>

int	ft_format_treatment(const char *s, int i, va_list ap)
{
	//char	*form = "cspdiuxX%nfge";
	char	*flag = "-.*lh# +0";
	int	j;

	j = 0;
	//systeme d'indices pour les fonctions a gerer.
	while (ft_strchr(flag, s[i + (++j)]))
	{
		//if (s[i + j] == '-')
		//	right to left;
		//if (s[i + j] == '#')
		//if (s[i + j] == ' ')
		//	blank before positive;
		//if (s[i + j] == '+')
		//if (s[i + j] == '0')
		//if (s[i + j] == 'l')
		//if (s[i + j] == 'h')
		//if (s[i + j] == '.')
		//if (s[i + j] == '*')
	}
	printf("j = %d\n", j);
	
	if (s[i + j] == 'c')
		ft_putchar_fd((unsigned char)va_arg(ap, int), 1);
	if (s[i + j] == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	if (s[i + j] == 'p')
		ft_putmem_fd(va_arg(ap, unsigned long int), 1);
	if (s[i + j] == 'd' || *s == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	if (s[i + j] == 'u')
		ft_putstr_fd(ft_itoa(va_arg(ap, unsigned int)), 1);
	if (s[i + j] == 'o')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "01234567", 1);
	if (s[i + j] == 'x')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789abcdef", 1);
	if (s[i + j] == 'X')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", 1);
	if (s[i + j] == '%')
		ft_putchar_fd('%', 1);
	if (s[i + j] == 'n')
		*(va_arg(ap, int *)) = i;
	//if (s[i + j] == 'f')
	//	ft_putdbl_fd(va_arg(ap, double), 1);
	//if (s[i + j] == 'g')
	//	ft_putdbl_fd(va_arg(ap, double), 1);
	//if (s[i + j] == 'e')
	//	ft_putdbl_fd(va_arg(ap, double), 1);
	j++;
	return (j);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int	i;

	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			s += ft_format_treatment(s, i, ap);
		//if (ft_strncmp((s = ft_format_treatment(s, ap)), "error", ft_strlen(s)) == 0)
		//	return (1); // need to handle error format here
		else
		{
			ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * 4);
	ft_printf("hey %s \n la bess ? \n %.*d \n %c\n %  p\n", "boloss", 123446, 'u', s);
	return (0);
}

/*
 * fonctions necessaires:
 *
 * atoi
 * atoi_base
 * itoa_base
 */
