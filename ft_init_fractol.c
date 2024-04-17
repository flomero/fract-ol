/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fractol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:09:25 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 09:13:08 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_init_fractol(t_fractol *fractol)
{
	fractol->max_iter = MAX_ITER;
	fractol->zoom = 1;
	if (fractol->fractal == mandelbrot)
		fractol->draw_fractal = &ft_mandelbrot;
	ft_init_mlx(fractol);
}
