#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int	str_len(char *str)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

int	*split_str(char	*str)
{
	int	i;
	int	*array;
	int	strlen;
	
	array = (int*) malloc(16 * sizeof(int));
	strlen = str_len(str);
	i = 0;
	array[0] = -1;
	while (*str != 0 && strlen == 31)
	{
		if ((*str >= '1' && *str <= '4') && (*(str + 1) == ' ' || *(str + 1) == '\0'))
		{
			array[i++] = *str - '0';
			if (*(str++ + 1) != '\0')
			{
				str++;
			}
		}
		else 
		{
			array[0] = -1;
			break;
		}
	}
	return (array);
}

int	main(int argc, char *argv[])
{
	int *params;
	int solution;
	int grid[16];
	int i;

	i = 0;
	while (i < 16)
		grid[i++] = 0;

	if (argc == 2) {
		params = split_str(argv[1]);
		if (params[0] != -1) {
			solution = solve(0, grid, params);
			if (solution == 1)
				display_grid(grid);
			else
				write(1, "Error\n",6);
			return (0);
		}
	}
	ft_putstr("Expected input: ./rush-01 \"col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right\"\n");
	return (0);
}
