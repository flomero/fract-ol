/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:25:32 by flfische          #+#    #+#             */
/*   Updated: 2024/04/16 14:34:31 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define WIDTH 512
# define HEIGHT 512
# define MAX_ITER 1000

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

typedef struct s_fractol
{
	t_fractals	fractal;
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			max_iter;
	uint32_t	(*draw_fractal)(struct s_fractol *fractol, int x, int y);
}				t_fractol;

typedef enum e_errors
{
	no_error,
	err_no_args,
	err_invalid_fractal,
	err_mlx_init_failed,
}				t_errors;

// input parsing
t_fractals		ft_parse_input_fractal(char *input);
void			ft_init_mlx(t_fractol *fractol);

// rendering
void			ft_draw_image(t_fractol *fractol);
uint32_t		ft_mandelbrot(t_fractol *fractol, int x, int y);

// user input handling
void			ft_key_press(void *param);

// error handling
t_errors		*ft_get_input_error(void);
void			ft_set_input_error(t_errors error);
void			ft_print_errors(t_errors error, int exit_bool);
void			ft_print_help(void);

// complex operations
t_complex		ft_c_addition(t_complex a, t_complex b);
t_complex		ft_c_subtraction(t_complex minund, t_complex subtrahend);
t_complex		ft_c_multiplication(t_complex a, t_complex b);
t_complex		ft_c_division(t_complex dividend, t_complex divisor);
t_complex		ft_c_power(t_complex base, int exponent);

#endif
