/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:25:45 by flfische          #+#    #+#             */
/*   Updated: 2024/04/14 16:56:18 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc != 2)
		ft_print_errors(err_no_args, 1);
	fractol.fractal = ft_parse_input_fractal(argv[1]);
	if (*ft_get_input_error())
		ft_print_errors(0, 1);
	ft_printf("Fractal: %d\n", fractol.fractal);
	fractol.mlx = mlx_init(512, 512, "Fractol", 0);
	if (!fractol.mlx)
		ft_print_errors(err_mlx_init_failed, 1);
	mlx_loop_hook(fractol.mlx, &ft_key_press, &fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (0);
}
