int		ft_format_size_g(double nb, char *flags)
{
	int		ret;
	int		prec;
	int		sign;
	int		qqch;
	int		t_nb;

	ret = 0;
	prec = 1;
	sign = nb < 0 ? -1 : 1;
	nb *= sign;
	qqch = ft_get_pow
		while (nb > 9)
		{
			if ((int)nb % 10 != 0)
				break;
			nb /= 10;
		}
	while ((nb /= 10) > 9)
		prec++;
	if (strchr(flags, '+') || strchr(flags, ' ') || sign == -1)
		prec++;
	if (strchr(flags, '#'))
		prec = atoi(strchr(flags, '.') + 1) > 0 ? atoi(strchr(flags, '.') + 1) + 1 : 7;
	while (*flags && *flags != '.')
		ret = ret < atoi(flags++) ? atoi(flags - 1) : ret;
	ret = prec + 5 > ret ? prec + 6 : ret + 1;
	return (ret);
}

int main()
{
	int i;
	double j = -4200101.42;
	i = ft_format_size_g(j, "g");
	printf("%d\n", i);
	i = printf("%g", j);
	printf("\n%d\n", i);
}



// sans flag si prec >= +6 -> passe en e sinon f
// sans flag si prec <= -5 -> passe en e sinon f
// si prec < exposant -> passe en e | p.ex
//
//
{
	int		exp;
	int		sign;

	sign = nb < 0 ? -1 : 1;
	nb *= sign;
	exp = ft_get_pow(nb);
	if (!strchr(flags, '.'))
	{
		if (exp >= 6 || exp <= -5)
			ret = ft_size_g_e(flags, nbr, exp);
		else
			ret = ft_size_g_f(flags, nbr, exp);
	}
	else
	{
		if (atoi(strchr(flags, '.') + 1) <= exp)
			ret = ft_size_g_e(flags, nbr, exp);
		else
			ret = ft_size_g_f(flags, nbr, exp);
	}
	if (strchr(t_flags, ' ') || strchr(t_flags, '+') || sign == -1)
		prec++;
	return (ret);
}

int		ft_size_g_e(char *flags, double nb, int exp)
{
	
}

int		ft_size_g_f(char *flags, double nb, int exp)
{
	int		ret;
	int		prec;
	char	*t_flags;

	ret = 0;
	prec = nb > 9 ? 1 : 0;
	while ((nb /= 10.0) > 9)
		prec++;
	if (atoi(strchr(flags, '.') + 1))
		prec = prec < atoi(strchr(flags, '.') +1) ? atoi(strchr(flags, '.') +1) + 1 : prec + 1;
	t_flags = flags;
	while (*flags && *flags != '.')
		ret = ret < atoi(flags++) ? atoi(flags - 1) : ret;
	if (strchr(t_flags. '#'))
	{
		if (exp >= 0)
			if (prec < 7)
				prec = 7;
		if (exp < 0)
			prec = (exp * -1) + 7;
	}
	if (strchr(t_flags, ' ') || strchr(t_flags, '+') || sign == -1)
		prec++;
	ret = prec < ret ? ret + 1 : prec + 1;
	return (ret);
}
