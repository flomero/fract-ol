/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:25:32 by flfische          #+#    #+#             */
/*   Updated: 2024/04/13 13:17:21 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "libft/libft.h"
//# include "MLX42/MLX42.h"

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

typedef struct ft_fractol
{
	t_fractals	fractal;
}				t_fractol;

// input parsing
t_fractals		ft_parse_input_fractal(char *input);

// error handling
int				*ft_get_input_error(void);
void			ft_set_input_error(int error);
void			ft_print_errors(void);
void			ft_print_help(void);

// complex operations
t_complex		ft_c_addition(t_complex a, t_complex b);
t_complex		ft_c_subtraction(t_complex minund, t_complex subtrahend);
t_complex		ft_c_multiplication(t_complex a, t_complex b);
t_complex		ft_c_division(t_complex dividend, t_complex divisor);
t_complex		ft_c_power(t_complex base, int exponent);

#endif
