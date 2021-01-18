#include <stdio.h>
#include <unistd.h>
char		*flag_cleanse(char *s/*, va_list ap*/);

int main(int ac, char **av)
{
	int i = 42;
	(void)av;
	(void)ac;
	printf("%s\n",flag_cleanse("- +010.10x"));
}
