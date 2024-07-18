/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:52:23 by hkonte            #+#    #+#             */
/*   Updated: 2024/07/04 16:57:06 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	main(int argc, char **argv)
{
	unsigned int	i;

	i = 1;
	if (argc < 1)
		return (1);
	while (argv[i])
	{
		ft_putstr(argv[i++]);
		write(1, "\n", 1);
	}
	return (0);
}
