/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:54:15 by flfische          #+#    #+#             */
/*   Updated: 2024/04/19 13:49:00 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

int	ft_is_double(char *str)
{
	ft_strskipif(&str, &ft_isspace);
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	ft_strskipif(&str, &ft_isdigit);
	if (!*str)
		return (1);
	if (*str == '.')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	ft_strskipif(&str, &ft_isdigit);
	if (*str)
		return (0);
	return (1);
}

void	ft_get_julia_input(t_fractol *fractol, int argc, char **argv)
{
	int	o;

	o = fractol->active_overlay;
	if (argc == 2 + o)
	{
		fractol->julia.re = JULIA_DEFAULT_RE;
		fractol->julia.im = JULIA_DEFAULT_IM;
		return ;
	}
	else if (argc != 4 + o)
		ft_print_errors(err_invalid_julia, 1);
	if (!ft_is_double(argv[2 + o]) || !ft_is_double(argv[3 + o]))
		ft_print_errors(err_invalid_julia, 1);
	fractol->julia.re = ft_atod(argv[2 + o]);
	fractol->julia.im = ft_atod(argv[3 + o]);
	if (fractol->julia.re < -2 || fractol->julia.re > 2)
		ft_print_errors(err_invalid_julia, 1);
	if (fractol->julia.im < -2 || fractol->julia.im > 2)
		ft_print_errors(err_invalid_julia, 1);
}

void	ft_rot_julia(t_fractol *fractol)
{
	t_complex	tmp;

	tmp.re = fractol->julia.re;
	tmp.im = fractol->julia.im;
	fractol->julia.re = tmp.re * cos(JULIA_ROT_ANGLE) - tmp.im
		* sin(JULIA_ROT_ANGLE);
	fractol->julia.im = tmp.re * sin(JULIA_ROT_ANGLE) + tmp.im
		* cos(JULIA_ROT_ANGLE);
}

uint32_t	ft_julia(t_fractol *fractol, int x, int y)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	tmp;

	i = 0;
	z.re = (x / fractol->zoom) + fractol->offset.x;
	z.im = (y / fractol->zoom) + fractol->offset.y;
	c.re = fractol->julia.re;
	c.im = fractol->julia.im;
	while (i < fractol->max_iter)
	{
		tmp.re = z.re * z.re - z.im * z.im;
		tmp.im = 2 * z.re * z.im;
		z.re = tmp.re + c.re;
		z.im = tmp.im + c.im;
		if (z.re * z.re + z.im * z.im > 4)
			break ;
		i++;
	}
	if (i == fractol->max_iter)
		return (0x000000FF);
	return (ft_get_color(fractol, i));
}
