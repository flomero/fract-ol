/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:25:45 by flfische          #+#    #+#             */
/*   Updated: 2024/04/19 13:45:22 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc < 2 && argc <= 5)
		ft_print_errors(err_no_args, 1);
	fractol.fractal = ft_parse_input_fractal(argv[1]);
	fractol.active_overlay = 0;
	if ((argc == 3 || (argc == 5 && fractol.fractal == julia))
		&& !ft_strcmp(argv[2], "-o"))
		fractol.active_overlay = 1;
	if (*ft_get_input_error())
		ft_print_errors(0, 1);
	ft_init_fractol(&fractol);
	if (fractol.fractal == julia)
		ft_get_julia_input(&fractol, argc, argv);
	mlx_loop_hook(fractol.mlx, &ft_keys_options, &fractol);
	mlx_loop_hook(fractol.mlx, &ft_keys_movement, &fractol);
	mlx_loop_hook(fractol.mlx, &ft_keys_colormode, &fractol);
	mlx_loop_hook(fractol.mlx, &ft_mouse_move, &fractol);
	mlx_scroll_hook(fractol.mlx, &ft_scroll, &fractol);
	mlx_key_hook(fractol.mlx, &ft_change_fractal, &fractol);
	ft_draw_image(&fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (0);
}
