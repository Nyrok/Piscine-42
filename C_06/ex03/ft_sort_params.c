/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:52:23 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/16 15:04:46 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

void	ft_print_args(char **args)
{
	unsigned int	i;

	i = 1;
	while (args[i])
		ft_putstr(args[i++]);
}

int	main(int argc, char **argv)
{
	unsigned int	i;
	int				change;
	char			*temp;

	change = 1;
	if (argc < 2)
		return (1);
	while (change)
	{
		i = argc - 2;
		change = 0;
		while (i >= 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
				change = 1;
			}
			i--;
		}
	}
	ft_print_args(argv);
	return (0);
}
