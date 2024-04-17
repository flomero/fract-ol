/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colormodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:58:15 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 15:05:21 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

uint32_t	ft_monochrome(t_fractol *fractol, int i)
{
	double	color_factor;

	color_factor = (double)i / fractol->max_iter;
	return ((uint32_t)(0x000000ff * color_factor));
}

u_int32_t	ft_duotone(t_fractol *fractol, int i, uint32_t start_color,
		uint32_t end_color)
{
	uint32_t	color;
	t_color		start;
	t_color		end;

	start.r = start_color >> 16;
	start.g = start_color >> 8;
	start.b = start_color >> 0;
	end.r = end_color >> 16;
	end.g = end_color >> 8;
	end.b = end_color >> 0;
	color = 0xff << 24;
	color += (start.r + (end.r - start.r) * i / fractol->max_iter) << 16;
	color += (start.g + (end.g - start.g) * i / fractol->max_iter) << 8;
	color += (start.b + (end.b - start.b) * i / fractol->max_iter) << 0;
	return (color);
}

uint32_t	ft_default_color(t_fractol *fractol, int i)
{
	t_color		color;
	uint32_t	color_value;
	double		t;

	t = (double)i / (double)fractol->max_iter;
	color.r = (int)(9 * (1 - t) * t * t * t * 255);
	color.g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	color.b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color_value = (color.r << 24) + (color.g << 16) + (color.b << 8) + 0xff;
	return (color_value);
}
