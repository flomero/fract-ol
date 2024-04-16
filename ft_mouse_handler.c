/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:26:38 by flfische          #+#    #+#             */
/*   Updated: 2024/04/16 16:36:25 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_mouse_move(void *param)
{
	t_fractol	*fractol;
	int			x;
	int			y;

	fractol = (t_fractol *)param;
	mlx_get_mouse_pos(fractol->mlx, &x, &y);
	fractol->mouse.x = x;
	fractol->mouse.y = y;
}
