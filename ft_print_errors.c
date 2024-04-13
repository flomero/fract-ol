/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:22:33 by flfische          #+#    #+#             */
/*   Updated: 2024/04/13 13:16:11 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_print_errors(void)
{
	if (*ft_get_input_error() == 1)
		ft_putstr_fd("Error\nInvalid fractal\n", 2);
	ft_print_help();
}

void	ft_print_help(void)
{
	ft_printf("------------------\n");
	ft_printf("Usage: ./fractol [fractal]\n");
	ft_printf("Available Fractals:\n");
	ft_printf("\tmandelbrot\n");
	ft_printf("\tjulia\n");
}
