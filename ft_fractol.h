/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:25:32 by flfische          #+#    #+#             */
/*   Updated: 2024/04/12 18:03:25 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "libft/libft.h"
//# include "MLX42/MLX42.h"

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

t_complex	ft_c_addition(t_complex a, t_complex b);
t_complex	ft_c_subtraction(t_complex minund, t_complex subtrahend);
t_complex	ft_c_multiplication(t_complex a, t_complex b);
t_complex	ft_c_division(t_complex dividend, t_complex divisor);
t_complex	ft_c_power(t_complex base, int exponent);

#endif
