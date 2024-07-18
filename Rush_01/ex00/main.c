/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwuille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:24:11 by jwuille           #+#    #+#             */
/*   Updated: 2024/07/07 15:29:22 by hkonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_error(void);
int	check_format(char *str);
void	skyscrapper(char *str);

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (print_error());
	if (!check_format(argv[1]))
		return (print_error());
	skyscrapper(argv[1]);
	return (0);
}
