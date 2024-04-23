/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scroll_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:02:18 by flfische          #+#    #+#             */
/*   Updated: 2024/04/23 11:36:19 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

void	ft_scroll_iter(t_fractol *fractol)
{
	fractol->max_iter = fractol->zoom / INIT_ZOOM * MAX_ITER / 5;
	if (fractol->max_iter > ITER_LIMIT)
		fractol->max_iter = ITER_LIMIT;
	else if (fractol->max_iter < MAX_ITER)
		fractol->max_iter = MAX_ITER;
}

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	t_mouse		mouse;

	fractol = (t_fractol *)param;
	mouse = fractol->mouse;
	if (ydelta < 0)
	{
		fractol->offset.x = (mouse.x / fractol->zoom + fractol->offset.x)
			- (mouse.x / (fractol->zoom * ZOOM_FACTOR));
		fractol->offset.y = (mouse.y / fractol->zoom + fractol->offset.y)
			- (mouse.y / (fractol->zoom * ZOOM_FACTOR));
		fractol->zoom *= ZOOM_FACTOR;
	}
	else if (ydelta > 0)
	{
		fractol->offset.x = (mouse.x / fractol->zoom + fractol->offset.x)
			- (mouse.x / (fractol->zoom / ZOOM_FACTOR));
		fractol->offset.y = (mouse.y / fractol->zoom + fractol->offset.y)
			- (mouse.y / (fractol->zoom / ZOOM_FACTOR));
		fractol->zoom /= ZOOM_FACTOR;
	}
	ft_scroll_iter(fractol);
	(void)xdelta;
	ft_draw_image(fractol);
}
