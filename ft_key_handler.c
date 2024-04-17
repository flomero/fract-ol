/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:48:37 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 09:34:46 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_fractol.h"

void	ft_key_press(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
	{
		mlx_terminate(fractol->mlx);
		exit(0);
	}
}
