/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scroll_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:02:18 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 13:27:56 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (ydelta < 0)
	{
		fractol->offset.x = (fractol->mouse.x / fractol->zoom
				+ fractol->offset.x) - (fractol->mouse.x / (fractol->zoom
					* ZOOM_FACTOR));
		fractol->offset.y = (fractol->mouse.y / fractol->zoom
				+ fractol->offset.y) - (fractol->mouse.y / (fractol->zoom
					* ZOOM_FACTOR));
		fractol->zoom *= ZOOM_FACTOR;
	}
	else if (ydelta > 0)
	{
		fractol->offset.x = (fractol->mouse.x / fractol->zoom
				+ fractol->offset.x) - (fractol->mouse.x / (fractol->zoom
					/ ZOOM_FACTOR));
		fractol->offset.y = (fractol->mouse.y / fractol->zoom
				+ fractol->offset.y) - (fractol->mouse.y / (fractol->zoom
					/ ZOOM_FACTOR));
		fractol->zoom /= ZOOM_FACTOR;
	}
	(void)xdelta;
	ft_draw_image(fractol);
}
