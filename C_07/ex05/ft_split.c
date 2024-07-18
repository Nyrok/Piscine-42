/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:26:15 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/17 16:13:55 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count(char *str, char *charset)
{
	int	i;
	int	new_word;
	int	count;

	i = 0;
	new_word = 1;
	count = 0;
	while (str[i])
	{
		if (ft_in_charset(str[i], charset) && !new_word)
		{
			new_word = 1;
		}
		else if (!ft_in_charset(str[i], charset) && new_word)
		{
			new_word = 0;
			count++;
		}
		i++;
	}
	return (count);
}

char	**ft_alloc(int count)
{
	char	**result;
	int		i;

	result = malloc(1 + count * sizeof(char *));
	if (!result)
	{
		result = malloc(1);
		result[0] = (void *)0;
		return (result);
	}
	i = 0;
	while (i < count)
	{
		result[i] = malloc(32 * sizeof(char));
		if (!result[i])
		{
			result = malloc(1);
			result[0] = (void *)0;
			return (result);
		}
		i++;
	}
	return (result);
}

void	ft_split_exec(char *str, char *charset, char **result, int count)
{
	int	i;
	int	j;
	int	new_word;

	i = 0;
	j = 0;
	new_word = 1;
	while (str[i])
	{
		if (ft_in_charset(str[i], charset) && !new_word)
		{
			new_word = 1;
			result[count][j] = '\0';
			j = 0;
			count++;
		}
		else if (!ft_in_charset(str[i], charset))
		{
			new_word = 0;
			result[count][j] = str[i];
			j++;
		}
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		count;

	result = ft_alloc(ft_count(str, charset));
	if (!result[0])
		return (result);
	count = 0;
	ft_split_exec(str, charset, result, count);
	return (result);
}
