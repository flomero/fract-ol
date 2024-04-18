/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_change.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:39:03 by flfische          #+#    #+#             */
/*   Updated: 2024/04/18 16:11:44 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

void	ft_change_fractal(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;
	t_fractals	before;

	fractol = (t_fractol *)param;
	before = fractol->fractal;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_1)
		fractol->fractal = mandelbrot;
	else if (keydata.key == MLX_KEY_2)
		fractol->fractal = julia;
	else if (keydata.key == MLX_KEY_3)
		fractol->fractal = burningship;
	if (before == fractol->fractal)
		return ;
	mlx_delete_image(fractol->mlx, fractol->image);
	if (fractol->active_overlay)
		mlx_delete_image(fractol->mlx, fractol->overlay.image);
	fractol->image = mlx_new_image(fractol->mlx, fractol->size.x,
			fractol->size.y);
	if (!fractol->image)
		ft_print_errors(err_mlx_new_image_failed, 1);
	ft_init_fractol(fractol);
	ft_draw_image(fractol);
	ft_overlay_refresh(fractol);
}
