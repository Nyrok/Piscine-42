/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:47:06 by hkonte            #+#    #+#             */
/*   Updated: 2024/06/30 15:33:47 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

int	line(int x, int *c, char outside, char inside)
{
	if (*c == x)
	{
		ft_putchar(outside);
		ft_putchar('\n');
		*c = 1;
		return (1);
	}
	else if (*c == 1)
	{
		ft_putchar(outside);
		(*c)++;
		return (0);
	}
	else
	{	
		ft_putchar(inside);
		(*c)++;
		return (0);
	}
}

void	rush(int x, int y)
{
	int	c;
	int	l;

	if (x <= 0 || y <= 0)
		return ;
	c = 1;
	l = 1;
	while (l <= y)
	{
		if (l == 1 || l == y)
		{
			l += line(x, &c, 'o', '-');
		}
		else
		{
			l += line(x, &c, '|', ' ');
		}
	}
}
