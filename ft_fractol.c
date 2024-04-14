/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:25:45 by flfische          #+#    #+#             */
/*   Updated: 2024/04/14 12:47:28 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_key_hook(void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;
	mlx_t		*mlx;

	if (argc != 2)
		ft_print_errors(err_no_args, 1);
	fractol.fractal = ft_parse_input_fractal(argv[1]);
	if (*ft_get_input_error())
		ft_print_errors(0, 1);
	ft_printf("Fractal: %d\n", fractol.fractal);
	mlx = mlx_init(512, 512, "Fractol", 0);
	if (!mlx)
		ft_print_errors(err_mlx_init_failed, 1);
	mlx_loop_hook(mlx, ft_key_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
