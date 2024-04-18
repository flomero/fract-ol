/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:09:25 by flfische          #+#    #+#             */
/*   Updated: 2024/04/18 09:14:32 by flfische         ###   ########.fr       */
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

void	ft_init_fractol(t_fractol *fractol)
{
	fractol->max_iter = MAX_ITER;
	fractol->zoom = INIT_ZOOM;
	fractol->color_shift = 0.0;
	if (fractol->fractal == mandelbrot)
		ft_init_mandebrot(fractol);
	else if (fractol->fractal == julia)
		ft_init_julia(fractol);
	ft_init_mlx(fractol);
}
