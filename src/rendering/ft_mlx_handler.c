/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:54:15 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 16:18:08 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

void	ft_init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", 0);
	if (!fractol->mlx)
		ft_print_errors(err_mlx_init_failed, 1);
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->image)
		ft_print_errors(err_mlx_init_failed, 1);
	mlx_image_to_window(fractol->mlx, fractol->image, 0, 0);
}

void	ft_draw_image(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(fractol->image, x, y, fractol->draw_fractal(fractol,
					x, y));
			x++;
		}
		y++;
	}
}
