#include <unistd.h>

void	ft_putstr(char *c)
{
	while (*c != '\0')
	{
		write(1, c, 1);
		c++;
	}
}
