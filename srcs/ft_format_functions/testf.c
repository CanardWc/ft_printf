int		ft_format_size_f(long double nb, char *flags)
{
	int			ret;
	int			prec;
	int			sign;

	ret = 0;
	prec = strchr(flags, '.') ? atoi(strchr(flags, '.') + 1) + 2 : 8;
	sign = nb < 0 ? -1 : 1;
	nb *= sign;
	prec += nb > 9 ? 1 : 0;
	while ((nb /= 10.0) > 9)
		prec++;
	if (strchr(flags, '+') || strchr(flags, ' ') || sign == -1)
		prec++;
	while (*flags)
		ret = ret < atoi(flags++) ? atoi(flags - 1) : ret;
	ret = prec < ret ? ret + 1 : prec + 1;
	//	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
	//		return (ret);
	return (ret);
}

int main()
{
	int		i;

	i = ft_format_size_f(-45454.4242, ".2f");
	printf("%d\n", i);
	i = printf("%.2f", -45454.4242);
	printf("\n");
	printf("%d\n", i);
}
