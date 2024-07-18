/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:58:21 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/03 18:03:46 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (c == '\r' || c == '\v' || c == '\f');
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	int	p;
	int	val;

	result = 0;
	i = 0;
	p = 1;
	while (str[i] != '\0' && ft_is_space(str[i]))
		i++;
	while (str[i] != '\0' && ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			p *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		val = (int)(str[i] - '0');
		if (val < 0 || val > 9)
			return (p * result);
		result = result * 10 + val;
		i++;
	}
	return (p * result);
}
