/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:07:45 by flfische          #+#    #+#             */
/*   Updated: 2024/04/18 11:23:43 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

uint32_t	ft_burningship(t_fractol *fractol, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z.re = 0;
	z.im = 0;
	c.re = (x / fractol->zoom) + fractol->offset.x;
	c.im = (y / fractol->zoom) + fractol->offset.y;
	i = 0;
	while (z.re * z.re + z.im * z.im < 4 && i < fractol->max_iter)
	{
		z = ft_c_addition(ft_c_multiplication(z, z), c);
		z.re = ft_dabs(z.re);
		z.im = ft_dabs(z.im);
		i++;
	}
	if (i == fractol->max_iter)
		return (0x000000ff);
	return (ft_get_color(fractol, i));
}
