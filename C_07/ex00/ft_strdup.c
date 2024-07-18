/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:30:04 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/18 13:16:14 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strdup(char *src)
{
	char	*result;

	result = malloc(1 + ft_strlen(src) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strcpy(result, src);
	result[ft_strlen(src)] = '\0';
	return (result);
}
