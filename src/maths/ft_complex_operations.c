/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:47:15 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 16:18:08 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

t_complex	ft_c_addition(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

t_complex	ft_c_subtraction(t_complex minund, t_complex subtrahend)
{
	t_complex	result;

	result.re = minund.re - subtrahend.re;
	result.im = minund.im - subtrahend.im;
	return (result);
}

t_complex	ft_c_multiplication(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re * b.re - a.im * b.im;
	result.im = a.re * b.im + a.im * b.re;
	return (result);
}

t_complex	ft_c_division(t_complex dividend, t_complex divisor)
{
	t_complex	result;
	double		denominator;

	denominator = divisor.re * divisor.re + divisor.im * divisor.im;
	result.re = (dividend.re * divisor.re + dividend.im * divisor.im)
		/ denominator;
	result.im = (dividend.im * divisor.re - dividend.re * divisor.im)
		/ denominator;
	return (result);
}

t_complex	ft_c_power(t_complex base, int exponent)
{
	t_complex	result;

	result = base;
	while (--exponent)
		result = ft_c_multiplication(result, base);
	return (result);
}
