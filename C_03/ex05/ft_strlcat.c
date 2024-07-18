/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:18:40 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/10 10:01:22 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	n;

	n = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && n + i + 1 < size)
	{
		dest[n + i] = src[i];
		i++;
	}
	dest[n + i] = '\0';
	if (n <= size)
		return (n + ft_strlen(src));
	return (size + ft_strlen(src));
}
