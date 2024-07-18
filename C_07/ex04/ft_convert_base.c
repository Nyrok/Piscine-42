/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:33:55 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/16 16:10:00 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_check_base(char *base);
int	ft_atoi_base(char *str, char *base);

char	*ft_itoa_base(int nb, char *base, unsigned int n, char *result)
{
	if (nb > (int)(n - 1))
	{
		ft_itoa_base(nb / n, base, n, result);
		ft_itoa_base(nb % n, base, n, result);
	}
	else if (nb <= (int)(-n))
	{
		result[0] = '-';
		ft_itoa_base(-nb / n, base, n, result);
		ft_itoa_base(-nb % n, base, n, result);
	}
	else if (nb < 0)
	{
		result[0] = '-';
		result[1] = base[-nb];
	}
	else
	{
		result[ft_strlen(result)] = base[nb];
	}
	result[ft_strlen(result)] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		val;
	char	*result;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return ((void *)0);
	val = ft_atoi_base(nbr, base_from);
	result = malloc(32 * sizeof(char));
	if (!result)
		return ((void *)0);
	return (ft_itoa_base(val, base_to, ft_strlen(base_to), result));
}
