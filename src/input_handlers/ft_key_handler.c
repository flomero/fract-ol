/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:48:37 by flfische          #+#    #+#             */
/*   Updated: 2024/04/18 09:36:22 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

void	ft_escape(t_fractol *fractol)
{
	mlx_terminate(fractol->mlx);
	exit(0);
}

void	fr_reset_zoom(t_fractol *fractol)
{
	fractol->zoom = INIT_ZOOM;
	fractol->offset.x = -3;
	fractol->offset.y = -1.5;
}

void	ft_keys_options(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		ft_escape(fractol);
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_DIVIDE))
		fr_reset_zoom(fractol);
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_ADD))
		fractol->max_iter += 10;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_SUBTRACT))
		fractol->max_iter -= 10;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_SPACE)
		&& fractol->fractal == julia)
		ft_rot_julia(fractol);
	else
		return ;
	ft_draw_image(fractol);
}

void	ft_keys_movement(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
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

void	ft_keys_colormode(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_0))
		fractol->colormode = normal;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_1))
		fractol->colormode = monochrome;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_2))
		fractol->colormode = duotone;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_3))
		fractol->colormode = gradient;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_4))
		fractol->color_shift += COLOR_SHIFT;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_5))
		fractol->color_shift += COLOR_SHIFT * 10;
	else
		return ;
	ft_draw_image(fractol);
}
