/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:25:08 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/11 14:51:17 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	valid;
	int	i;
	int	k;
	int	n;

	n = ft_strlen(to_find);
	if (n == 0)
		return (str);
	i = -1;
	while (str[++i] != '\0' && ft_strlen(str) >= n)
	{
		k = -1;
		valid = 1;
		while (to_find[++k] != '\0' && str[i + k] != '\0')
		{
			if (str[i + k] != to_find[k])
			{
				valid = 0;
				break ;
			}
		}
		if (valid > 0 && k == n)
			return (&str[i]);
	}
	return (0);
}
