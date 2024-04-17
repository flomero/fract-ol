/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:48:24 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 16:18:08 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

uint32_t	ft_mandelbrot(t_fractol *fractol, int x, int y)
{
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	int			i;

	z.re = 0;
	z.im = 0;
	i = 0;
	c.re = (x / fractol->zoom) + fractol->offset.x;
	c.im = (y / fractol->zoom) + fractol->offset.y;
	while (z.re * z.re + z.im * z.im < 4 && i < fractol->max_iter)
	{
		tmp = ft_c_addition(ft_c_multiplication(z, z), c);
		z = tmp;
		i++;
	}
	if (i == fractol->max_iter)
		return (0x000000ff);
	return (ft_get_color(fractol, i));
}
