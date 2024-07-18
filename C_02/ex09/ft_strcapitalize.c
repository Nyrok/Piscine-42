/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:47:39 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/02 13:50:34 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_str_is_alpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	ft_str_is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_str_is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (!ft_str_is_alpha(str[i]) && !ft_str_is_numeric(str[i]))
			new_word = 1;
		else
		{
			if (new_word && ft_str_is_lowercase(str[i]))
				str[i] = str[i] - 32;
			else if (!new_word && ft_str_is_uppercase(str[i]))
				str[i] = str[i] + 32;
			new_word = 0;
		}
		i++;
	}
	return (str);
}
