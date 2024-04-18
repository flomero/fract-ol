/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:22:33 by flfische          #+#    #+#             */
/*   Updated: 2024/04/18 14:16:39 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"
#include "ft_errors.h"

void	ft_print_errors(t_errors error, int exit_bool)
{
	if (error)
		ft_set_input_error(error);
	if (*ft_get_input_error() == err_no_args)
		ft_putstr_fd(ERRMSG_INV_ARGS, 2);
	else if (*ft_get_input_error() == err_invalid_fractal)
		ft_putstr_fd(ERRMSG_INV_FRACTAL, 2);
	else if (*ft_get_input_error() == err_invalid_julia)
		ft_putstr_fd(ERRMSG_INV_JULIA, 2);
	else if (*ft_get_input_error() == err_mlx_init_failed)
		ft_putstr_fd(ERRMSG_MLX_INIT, 2);
	else if (*ft_get_input_error() == err_mlx_new_image_failed)
		ft_putstr_fd(ERRMSG_MLX_NEW_IMG, 2);
	else if (*ft_get_input_error() == err_mlx_image_to_window_failed)
		ft_putstr_fd(ERRMSG_MLX_IMAGE_TO_WINDOW, 2);
	ft_print_help();
	if (exit_bool)
		exit(1);
}

void	ft_print_help(void)
{
	ft_printf("------------------\n");
	ft_printf("Usage: ./fractol [options] [fractal]\n");
	ft_printf("Options:\n");
	ft_printf("\t-o\t\t\tActivate overlay\n");
	ft_printf("Available Fractals:\n");
	ft_printf("\tmandelbrot\n");
	ft_printf("\tjulia [re] [im] (re & im between -2 and 2)\n");
}
