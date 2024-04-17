/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:26:38 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 16:11:56 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_mouse_move(void *param)
{
	t_fractol	*fractol;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;

	fractol = (t_fractol *)param;
	prev_x = fractol->mouse.x;
	prev_y = fractol->mouse.y;
	mlx_get_mouse_pos(fractol->mlx, &x, &y);
	fractol->mouse.x = x;
	fractol->mouse.y = y;
	if (mlx_is_mouse_down(fractol->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		fractol->offset.x += (prev_x - x) / fractol->zoom;
		fractol->offset.y += (prev_y - y) / fractol->zoom;
		ft_draw_image(fractol);
	}
}
