/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:06:19 by flfische          #+#    #+#             */
/*   Updated: 2024/04/18 11:17:16 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

t_errors	*ft_get_input_error(void)
{
	static t_errors	error;

	return (&error);
}

void	ft_set_input_error(t_errors error)
{
	*ft_get_input_error() = error;
}

t_fractals	ft_parse_input_fractal(char *input)
{
	if (ft_strcmp(input, "mandelbrot") == 0)
		return (mandelbrot);
	if (ft_strcmp(input, "julia") == 0)
		return (julia);
	if (ft_strcmp(input, "burningship") == 0)
		return (burningship);
	ft_set_input_error(err_invalid_fractal);
	return (mandelbrot);
}
