/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:25:32 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 09:34:01 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "ft_defines.h"
# include "ft_typedefs.h"

// input parsing
t_fractals	ft_parse_input_fractal(char *input);
void		ft_init_mlx(t_fractol *fractol);
void		ft_init_fractol(t_fractol *fractol);

// rendering
void		ft_draw_image(t_fractol *fractol);
uint32_t	ft_mandelbrot(t_fractol *fractol, int x, int y);

// user input handling
void		ft_key_press(void *param);
void		ft_mouse_move(void *param);

// error handling
t_errors	*ft_get_input_error(void);
void		ft_set_input_error(t_errors error);
void		ft_print_errors(t_errors error, int exit_bool);
void		ft_print_help(void);

// complex operations
t_complex	ft_c_addition(t_complex a, t_complex b);
t_complex	ft_c_subtraction(t_complex minund, t_complex subtrahend);
t_complex	ft_c_multiplication(t_complex a, t_complex b);
t_complex	ft_c_division(t_complex dividend, t_complex divisor);
t_complex	ft_c_power(t_complex base, int exponent);

#endif
