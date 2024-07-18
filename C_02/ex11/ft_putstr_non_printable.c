/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:47:39 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/01 17:46:08 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			*hex;
	char			a;
	char			b;
	unsigned char	c;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_str_is_printable(str[i]))
		{
			c = str[i];
			a = hex[c / 16];
			b = hex[c % 16];
			write(1, "\\", 1);
			write(1, &a, 1);
			write(1, &b, 1);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}	
}
