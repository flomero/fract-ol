/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:54:15 by flfische          #+#    #+#             */
/*   Updated: 2024/04/18 15:17:39 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

void	ft_init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", 0);
	if (!fractol->mlx)
		ft_print_errors(err_mlx_init_failed, 1);
	fractol->image = mlx_new_image(fractol->mlx, fractol->size.x,
			fractol->size.y);
	if (!fractol->image)
		ft_print_errors(err_mlx_new_image_failed, 1);
	if (mlx_image_to_window(fractol->mlx, fractol->image, 0, 0) == -1)
		ft_print_errors(err_mlx_image_to_window_failed, 1);
}

void	ft_draw_image(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < fractol->size.y)
	{
		x = 0;
		while (x < fractol->size.x)
		{
			mlx_put_pixel(fractol->image, x, y, fractol->draw_fractal(fractol,
					x, y));
			x++;
		}
		y++;
	}
	ft_overlay_refresh(fractol);
}
