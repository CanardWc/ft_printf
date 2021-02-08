#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	printf("g = %.*g\n", atoi(av[1]), atof(av[2]));
	return (0);
}
