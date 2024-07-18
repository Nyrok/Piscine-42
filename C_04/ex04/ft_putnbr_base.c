/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:33:55 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/04 14:04:14 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr(int nb, char *base, unsigned int n)
{
	if (nb > (int)(n - 1))
	{
		ft_putnbr(nb / n, base, n);
		ft_putnbr(nb % n, base, n);
	}
	else if (nb <= (int)(-n))
	{
		ft_putchar('-');
		ft_putnbr(-nb / n, base, n);
		ft_putnbr(-nb % n, base, n);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putchar(base[-nb]);
	}
	else
	{
		ft_putchar(base[nb]);
	}
}

void	ft_putnbr_base(int nb, char *base)
{
	if (!ft_check_base(base))
		return ;
	ft_putnbr(nb, base, ft_strlen(base));
}
