
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwuille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:15:20 by jwuille           #+#    #+#             */
/*   Updated: 2024/07/07 13:52:55 by jwuille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

extern char	*columns;
extern char	*rows;

void	print_map(char **map)
{
	int	col;
	int	lin;

	col = 0;
	lin = 0;
	while (lin < 4)
	{
		while (col < 4)
		{
			write(1, &map[lin][col], 1);
			if (col != 3)
				write(1, " ", 1);
			col++;
		}	
		write(1, "\n", 1);
		lin++;
		col = 0;
	}
}

char	**init_map(void)
{
	char	**map;
	int	i;
	int	j;

	i = 0;
	map = malloc(4 * 8);
	while (i < 4)
		map[i++] = malloc(4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return map;
}

void	fill_rows(char *row, char *str)
{
	int	i;
	int	j;

	i = 16;
	j = 0;
	while (j < 8)
	{
		row[j] = str[i];	
		i += 2;
		j++;
	}
}

void	fill_columns(char *col, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 8)
	{
		col[j] = str[i];	
		i += 2;
		j++;
	}
}

int	is_safe(char **map, int row, int col, int val)
{
	// val de 1 a 4
	//la fonction verifie que val 
	int i;

	i = 0;
	while (i < 4)
	{
		if (map[row][i] == val || map[i][col] == val)
			return (0);
		i++;
	}
	return (1);
}

int count_visible(char *values, int direction) {
    char max = 0;
    int count = 0;
    int i;

    if (direction) {
        for (i = 0; i < 2; i++) {
            char temp = values[i];
            values[i] = values[3 - i];
            values[3 - i] = temp;
        }
    }

    for (i = 0; i < 4; i++) {
        if (values[i] > max) {
            max = values[i];
            count++;
        }
    }
    return count;
}

int	check_column(char **map, int index)
{
	char	up;
	char	down;
	char	*values;
	int	i;

	up = columns[index];
	down = columns[index + 4];
	values = malloc(4);
	i = 0;
	while (i < 4)
	{
		values[i] = map[i][index] - '0';
		i++;
	}
	int upCount = count_visible(values, 1);
	if (upCount != (up - '0'))
	{
		free(values);
		return (0);
	}
	int downCount = count_visible(values, 1);
	if (downCount != (down - '0'))
	{
		free(values);
		return (0);
	}
	return (1);
}

int	check_row(char **map, int index)
{
	char	left;
	char	right;
	char	*values;
	int	i;

	left = rows[index];
	right = rows[index + 4];
	values = malloc(4);
	i = 0;
	while (i < 4)
	{
		values[i] = map[index][i] - '0';
		i++;
	}
	int leftCount = count_visible(values, 1);
	if (leftCount != (left - '0'))
	{
		free(values);
		return (0);
	}
	int rightCount = count_visible(values, 1);
	if (rightCount != (right - '0'))
	{
		free(values);
		return (0);
	}
	return (1);
}

int	check_all(char **map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_row(map, i) || !check_column(map, i))
			return (0);
		i++;
	}
	return (1);
}

int	resolve(char **map, int row, int col)
{
	int i;

	i = 4;
	if (row > 3)
		return (check_all(map));
	if (col > 3)
		return resolve(map, row + 1, 0);

	while (i >= 1)
	{
		if (is_safe(map, row, col, i + '0'))
		{
			map[row][col] = i + '0';
			if(resolve(map, row, col + 1))
				return (1);
			map[row][col] = '0';	
		}
		i--;
	}
	return (0);
}


