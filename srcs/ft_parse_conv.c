
#include "../includes/ft_printf.h"

void	ft_parse_conv(t_env *arg)
{
	char	*tmp;
	char	*non_val;
	int		i;

	i = 0;
	tmp = CONVERSION;
	non_val = NON_VALID;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == arg->str[arg->cur])
			arg->conv = tmp[i];
		i++;
	}
	i = 0;
	while (non_val[i] != '\0')
	{
		if (non_val[i] == arg->str[arg->cur])
			arg->conv = non_val[i];
		i++;
	}
	arg->cur++;
}
