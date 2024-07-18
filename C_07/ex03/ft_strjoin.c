/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:59:48 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/18 20:12:21 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	return (dest);
}

int	ft_strslen(char **strs)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (strs[i])
	{
		n += ft_strlen(strs[i]);
		i++;
	}
	return (n);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		length;
	int		i;

	length = ft_strslen(strs) + 1;
	result = malloc((length + ((size - 1) * ft_strlen(sep))) * sizeof(char));
	if (!result || size <= 0)
	{
		result = malloc(sizeof(char));
		result[0] = '\0';
		return (result);
	}
	i = 0;
	while (i < size)
	{
		if (strs[i])
		{
			ft_strcat(result, strs[i]);
			if (i < size - 1)
				ft_strcat(result, sep);
		}
		i++;
	}
	result[ft_strlen(result)] = '\0';
	return (result);
}
