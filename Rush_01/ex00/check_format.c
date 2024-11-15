/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwuille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:33:19 by jwuille           #+#    #+#             */
/*   Updated: 2024/07/07 15:21:10 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_format(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (i % 2 != 0 && str[i] != ' ')
			return (0);
		if (i % 2 == 0 && (str[i] < '1' || str[i] > '4'))
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}
