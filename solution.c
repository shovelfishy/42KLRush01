#include <unistd.h>
#include <stdio.h>

int	check_all(int pos, int grid[16], int conditions[16]);
int	is_duplicate(int pos, int height, int grid[]);

int	solve(int pos, int grid[16], int conditions[16])
{
	int height;
	int row;
	int col;

	height = 0;
	row = pos / 4;
	col = pos % 4;

	while (height++ < 4)
	{
		grid[pos] = height;
		if (!is_duplicate(pos, height, grid) && check_all(pos, grid, conditions))
		{
			if (pos == 15 || solve(pos + 1, grid, conditions) == 1)
			{
				return (1);
			}
		}
		grid[pos] = 0;
	}
	return (0);
}

int	check_top_columns(int row, int col, int grid[16], int conditions[16])
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = col;
	while (i < 16)
	{
		if(grid[i] > max)
		{
			max = grid[i];
			count++;
		}
		i += 4;
	}
	if ((row < 3 && count <= conditions[col])
		|| (row == 3 && count == conditions[col]))
		return(1); 
	return (0);
}

int	check_bottom_columns(int row, int col, int grid[16], int conditions[16])
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 12 + col;
	while (i >= 0)
	{
		if(grid[i] > max)
		{
			max = grid[i];
			count++;
		}
		i -= 4;
	}
	if ((row < 3) || (row == 3 && count == conditions[4 + col]))
		return(1);
	return (0);
}
int	check_right_rows(int row, int col, int grid[16], int conditions[16])
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = row * 4 + 4;
	while (--i >= row * 4)
	{
		if(grid[i] > max)
		{
			max = grid[i];
			count++;
		}
	}

	if ((col < 3)
		|| (col == 3 && count == conditions[12 + row]))
		return(1); 
	return (0);
}
int	check_left_rows(int row, int col, int grid[16], int conditions[16])
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = row * 4;

	while (i < row * 4 + 4)
	{
		if(grid[i] > max)
		{
			max = grid[i];
			count++;
		}
		i++;
	}

	if ((col < 3 && count <= conditions[8 + row])
		|| (col == 3 && count == conditions[8 + row]))
			return(1);
	return (0);
}

int	check_all(int pos, int grid[16], int conditions[16])
{
	int row;
	int col;

	row = pos / 4;
	col = pos % 4;

	if (check_left_rows(row, col, grid, conditions) == 1
		&& check_right_rows(row, col, grid, conditions) == 1
		&& check_top_columns(row, col, grid, conditions) == 1
		&& check_bottom_columns(row, col, grid, conditions) == 1)
			return (1);
	return (0);
}

int	is_duplicate(int pos, int height, int grid[])
{
	int	row;
	int	col;
	int i;

	i = 0;
	row = pos / 4;
	col = pos % 4;
	while (i < 4)
	{
		if ((i * 4 + col != pos && grid[i * 4 + col] == height)
			|| (row * 4 + i != pos && grid[row * 4 + i] == height))
				return (1);
		i++;
	}
	return (0);
}

void	display_grid(int grid[16])
{
	int		i;
	char	num;

	i = 0;
	while (i < 16)
	{
		num = grid[i] + '0';
		write(1, &num, 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}