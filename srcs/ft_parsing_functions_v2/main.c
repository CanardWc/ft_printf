#include <stdio.h>
#include <unistd.h>
char		*flag_cleanse(char *s/*, va_list ap*/);

int main(int ac, char **av)
{
	(void)av;
	(void)ac;
	printf("%s\n",flag_cleanse("0- +10.10x"));
}
