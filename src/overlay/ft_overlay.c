/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overlay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:22:48 by flfische          #+#    #+#             */
/*   Updated: 2024/04/18 13:43:37 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

void	ft_init_overlay(t_fractol *fractol)
{
	fractol->size.x = WIDTH - OVERLAY_WIDTH;
	fractol->size.y = HEIGHT;
	fractol->overlay.size.x = OVERLAY_WIDTH;
	fractol->overlay.size.y = HEIGHT;
	fractol->overlay.pos.x = WIDTH - OVERLAY_WIDTH;
	fractol->overlay.pos.y = 0;
	fractol->overlay.background = 0x343D46FF;
	fractol->overlay.text = 0xFEFEFEFF;
}

void	ft_overlay_bg(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < fractol->overlay.size.y)
	{
		x = 0;
		while (x < fractol->overlay.size.x)
		{
			mlx_put_pixel(fractol->overlay.image, x, y,
				fractol->overlay.background);
			x++;
		}
		y++;
	}
}

void	ft_draw_overlay(t_fractol *fractol)
{
	fractol->overlay.image = mlx_new_image(fractol->mlx,
			fractol->overlay.size.x, fractol->overlay.size.y);
	if (!fractol->overlay.image)
		ft_print_errors(err_mlx_new_image_failed, 1);
	if (mlx_image_to_window(fractol->mlx, fractol->overlay.image,
			fractol->overlay.pos.x, fractol->overlay.pos.y) == -1)
		ft_print_errors(err_mlx_image_to_window_failed, 1);
}
