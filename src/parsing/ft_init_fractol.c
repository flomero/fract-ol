/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:09:25 by flfische          #+#    #+#             */
/*   Updated: 2024/04/18 14:08:01 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

void	ft_init_mandebrot(t_fractol *fractol)
{
	fractol->draw_fractal = &ft_mandelbrot;
	fractol->offset.x = -3;
	fractol->offset.y = -1.5;
	fractol->colormode = normal;
}

void	ft_init_julia(t_fractol *fractol)
{
	fractol->draw_fractal = &ft_julia;
	fractol->offset.x = -2.5;
	fractol->offset.y = -1.5;
}

void	ft_init_burningship(t_fractol *fractol)
{
	fractol->draw_fractal = &ft_burningship;
	fractol->offset.x = -3;
	fractol->offset.y = -2;
	fractol->color_shift = 0.3;
}

void	ft_init_fractol(t_fractol *fractol)
{
	fractol->max_iter = MAX_ITER;
	fractol->zoom = INIT_ZOOM;
	fractol->color_shift = 0.0;
	fractol->size.x = WIDTH;
	fractol->size.y = HEIGHT;
	if (fractol->active_overlay)
		ft_init_overlay(fractol);
	if (fractol->fractal == mandelbrot)
		ft_init_mandebrot(fractol);
	else if (fractol->fractal == julia)
		ft_init_julia(fractol);
	else if (fractol->fractal == burningship)
		ft_init_burningship(fractol);
	ft_init_mlx(fractol);
	if (fractol->active_overlay)
		ft_draw_overlay(fractol);
}
