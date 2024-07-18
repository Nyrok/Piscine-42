/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwuille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:23:23 by jwuille           #+#    #+#             */
/*   Updated: 2024/07/07 19:53:04 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	print_error(void);
char	**init_map(void);
void	print_map(char **map);
void	fill_rows(char *row, char *str);
void	fill_columns(char *col, char *str);
int	resolve(char **map, int row, int col);
char	*columns;
char	*rows;

void	skyscrapper(char *str)
{
	char	**map;
	
	map = init_map();
	columns = malloc(8 * 4); // nombre de int * taille d'un int
	rows = malloc(8 * 4);
	fill_columns(columns, str);
	fill_rows(rows, str);
	if(!resolve(map, 0, 0))
	{
		print_error();
		return ;
	}	
	print_map(map);
}
