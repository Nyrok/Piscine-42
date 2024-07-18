/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:07:59 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/11 14:50:47 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	if (n == 0)
		return (0);
	while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0')
	{
		if (++index >= n)
		{
			index--;
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		}
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
