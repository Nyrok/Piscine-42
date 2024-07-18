/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:58:11 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/10 10:11:49 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	else if (nb < 2)
		return (1);
	else
	{
		result = 1;
		while (nb >= 2)
		{
			result *= nb--;
		}
		return (result);
	}
}
