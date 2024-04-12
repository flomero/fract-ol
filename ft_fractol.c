/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:25:45 by flfische          #+#    #+#             */
/*   Updated: 2024/04/12 18:27:23 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}
	fractol.fractal = ft_parse_input_fractal(argv[1]);
	if (*ft_get_input_error() == 1)
	{
		ft_print_errors();
		return (1);
	}
	ft_printf("Fractal: %d\n", fractol.fractal);
	ft_printf("%d", argc);
	return (0);
}
