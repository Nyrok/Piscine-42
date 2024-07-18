/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:25:12 by hkonte            #+#    #+#             */
/*   Updated: 2024/06/27 09:26:22 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_reverse_alphabet(void);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{
	char			*alphabet;
	unsigned int	i;

	alphabet = "zyxwvutsrqponmlkjihgfedcba";
	i = 0;
	while (alphabet[i] != '\0')
	{
		ft_putchar(alphabet[i++]);
	}
}
