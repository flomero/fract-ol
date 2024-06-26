/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:25:32 by flfische          #+#    #+#             */
/*   Updated: 2024/04/23 11:42:05 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "ft_defines.h"
# include "ft_typedefs.h"
# include <math.h>

// input parsing
t_fractals	ft_parse_input_fractal(char *input);
void		ft_init_mlx(t_fractol *fractol);
void		ft_init_fractol(t_fractol *fractol);
void		ft_get_julia_input(t_fractol *fractol, int argc, char **argv);

// rendering
void		ft_draw_image(t_fractol *fractol);
uint32_t	ft_mandelbrot(t_fractol *fractol, int x, int y);
uint32_t	ft_julia(t_fractol *fractol, int x, int y);
void		ft_rot_julia(t_fractol *fractol);
uint32_t	ft_burningship(t_fractol *fractol, int x, int y);

// color
uint32_t	ft_get_color(t_fractol *fractol, int i);
// color modes
uint32_t	ft_monochrome(t_fractol *fractol, int i);
uint32_t	ft_duotone(t_fractol *fractol, int i, uint32_t color1,
				uint32_t color2);
uint32_t	ft_default_color(t_fractol *fractol, int i);

// user input handling
void		ft_mouse_move(void *param);
void		ft_scroll(double xdelta, double ydelta, void *param);
void		ft_keys_options(void *param);
void		ft_keys_colormode(void *param);
void		ft_keys_movement(void *param);
void		ft_change_fractal(mlx_key_data_t keydata, void *param);

// overlay
void		ft_init_overlay(t_fractol *fractol);
void		ft_overlay_refresh(t_fractol *fractol);
void		ft_draw_overlay(t_fractol *fractol);
void		ft_overlay_bg(t_fractol *fractol);
void		ft_overlay_text(t_fractol *fractol);
// dynamic overlay texts
void		ft_ov_zoom(t_fractol *fractol, int x, int y);
void		ft_ov_iterations(t_fractol *fractol, int x, int y);
int			ft_linenbr(int i);
void		ft_ov_title(t_fractol *fractol, int x, int y);
char		*ft_dtoa(double n, int precision);

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
// math utils
double		ft_dabs(double x);

#endif
