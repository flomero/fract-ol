/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typedefs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:32:00 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 16:01:04 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPEDEFS_H
# define FT_TYPEDEFS_H

# include "ft_fractol.h"

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef enum e_fractals
{
	mandelbrot,
	julia,
}					t_fractals;

typedef struct s_mouse
{
	int				x;
	int				y;
	t_complex		pos;
}					t_mouse;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_dpoint
{
	double			x;
	double			y;
}					t_dpoint;

typedef enum e_colormodes
{
	normal,
	monochrome,
	duotone,
	gradient,
}					t_colormodes;

typedef struct s_color
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
}					t_color;

typedef struct s_fractol
{
	t_fractals		fractal;
	mlx_t			*mlx;
	mlx_image_t		*image;
	int				max_iter;
	uint32_t		(*draw_fractal)(struct s_fractol *, int x, int y);
	t_mouse			mouse;
	double			zoom;
	t_dpoint		offset;
	t_dpoint		center;
	t_colormodes	colormode;
}					t_fractol;

typedef enum e_errors
{
	no_error,
	err_no_args,
	err_invalid_fractal,
	err_mlx_init_failed,
}					t_errors;

#endif
