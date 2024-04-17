/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:48:37 by flfische          #+#    #+#             */
/*   Updated: 2024/04/17 13:45:36 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_key_press(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
	{
		mlx_terminate(fractol->mlx);
		exit(0);
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(fractol->mlx, MLX_KEY_W))
		fractol->offset.y -= MOVE_SIZE / fractol->zoom;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(fractol->mlx, MLX_KEY_S))
		fractol->offset.y += MOVE_SIZE / fractol->zoom;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(fractol->mlx, MLX_KEY_A))
		fractol->offset.x -= MOVE_SIZE / fractol->zoom;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(fractol->mlx, MLX_KEY_D))
		fractol->offset.x += MOVE_SIZE / fractol->zoom;
	else
		return ;
	ft_draw_image(fractol);
}
