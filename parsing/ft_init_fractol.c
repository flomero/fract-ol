/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:09:25 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 10:39:02 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_fractol.h"

void	ft_init_fractol(t_fractol *fractol)
{
	fractol->max_iter = MAX_ITER;
	fractol->zoom = INIT_ZOOM;
	if (fractol->fractal == mandelbrot)
		fractol->draw_fractal = &ft_mandelbrot;
	ft_init_mlx(fractol);
}
