/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:22:33 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 09:34:54 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_fractol.h"

void	ft_print_errors(t_errors error, int exit_bool)
{
	if (error)
		ft_set_input_error(error);
	if (*ft_get_input_error() == err_no_args)
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	else if (*ft_get_input_error() == err_invalid_fractal)
		ft_putstr_fd("Error\nInvalid fractal\n", 2);
	else if (*ft_get_input_error() == err_mlx_init_failed)
		ft_putstr_fd("Error\nFailed to initialize MLX\n", 2);
	ft_print_help();
	if (exit_bool)
		exit(1);
}

void	ft_print_help(void)
{
	ft_printf("------------------\n");
	ft_printf("Usage: ./fractol [fractal]\n");
	ft_printf("Available Fractals:\n");
	ft_printf("\tmandelbrot\n");
	ft_printf("\tjulia\n");
}
