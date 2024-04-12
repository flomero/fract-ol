/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:06:19 by flfische          #+#    #+#             */
/*   Updated: 2024/04/12 18:21:30 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	*ft_get_input_error(void)
{
	static int	error;

	return (&error);
}

void	ft_set_input_error(int error)
{
	*ft_get_input_error() = error;
}

t_fractals	ft_parse_input_fractal(char *input)
{
	if (ft_strcmp(input, "mandelbrot") == 0)
		return (mandelbrot);
	if (ft_strcmp(input, "julia") == 0)
		return (julia);
	ft_set_input_error(1);
	return (mandelbrot);
}
