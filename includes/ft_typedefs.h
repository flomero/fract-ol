/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typedefs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:32:00 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 10:11:20 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPEDEFS_H
# define FT_TYPEDEFS_H

# include "ft_fractol.h"

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef enum e_fractals
{
	mandelbrot,
	julia,
}				t_fractals;

typedef struct mouse
{
	int			x;
	int			y;
	t_complex	pos;
}				t_mouse;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_fractol
{
	t_fractals	fractal;
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			max_iter;
	uint32_t	(*draw_fractal)(struct s_fractol *fractol, int x, int y);
	t_mouse		mouse;
	double		zoom;
	t_complex	offset;
}				t_fractol;

typedef enum e_errors
{
	no_error,
	err_no_args,
	err_invalid_fractal,
	err_mlx_init_failed,
}				t_errors;

#endif
