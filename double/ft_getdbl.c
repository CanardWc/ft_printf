t_dbl	ft_get_double(double d)
{
	t_dbl_pars	parsed_dbl;
	t_dbl_data	dbl;
	int		i;

	i = 0;
	memcpy(&parsed_dbl, &d, sizeof(double));
	dbl.sign = parsed_dbl.sign == 0 ? -1 : 1;
	dbl.decimal = ft_getdbl_fraction(parsed_dbl);
	dbl = ft_getdbl_exponent(dbl);
	return (dbl);
}

	t_dbl_data	ret;
	t_dbl_data	tmp;

	if (!(ret.decimal = (char *)calloc(340, sizeof(char))))
		return (0);
	i = 0;
	ret.decimal[0] = '1';
	printf("len = %d\n", strlen(lol));
	while (lol[i])
	{
		if (lol[i] == '1')
		{
			if (!(tmp.decimal = (char *)calloc(50, sizeof(char))))
			return (0);
			tmp = ft_binary_pow(tmp, i + 1);
			ret = ft_add_tmp(ret, tmp);
			free(tmp.decimal);
		}
		i++;
	}
	printf("ret = %s\n", ret.decimal);
	return (0);
}
