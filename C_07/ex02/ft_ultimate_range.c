/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:30:08 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/10 13:03:37 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;
	int	r;

	if (min >= max)
	{
		*range = (void *)0;
		return (0);
	}
	r = max - min;
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
		return (-1);
	i = 0;
	while (min < max && min < 2147483647)
	{
		tab[i] = min++;
		i++;
	}
	*range = tab;
	return (r);
}
