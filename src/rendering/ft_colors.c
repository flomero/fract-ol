/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:59:53 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 16:18:08 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

uint32_t	ft_get_color(t_fractol *fractol, int i)
{
	if (fractol->colormode == monochrome)
		return (ft_monochrome(fractol, i));
	else if (fractol->colormode == duotone)
		return (ft_duotone(fractol, i, 0xff0ff0ff, 0x00ff00ff));
	return (ft_default_color(fractol, i));
}
