/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scroll_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:02:18 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 10:20:04 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
#include <stdio.h>

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (ydelta > 0)
		fractol->zoom *= ZOOM_FACTOR;
	else if (ydelta < 0)
		fractol->zoom /= ZOOM_FACTOR;
	(void)xdelta;
	printf("Zoom: %f\n", fractol->zoom);
}
