/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overlay_dynamic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:11:09 by flfische          #+#    #+#             */
/*   Updated: 2024/04/18 15:30:32 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

void	ft_ov_zoom(t_fractol *fractol, int x, int y)
{
	char				*zoom;
	static mlx_image_t	*image;
	static double		zoom_old;

	if (fractol->zoom == zoom_old)
		return ;
	zoom_old = fractol->zoom;
	if (image)
		mlx_delete_image(fractol->mlx, image);
	zoom = ft_itoa(fractol->zoom / 300);
	if (!zoom)
		ft_print_errors(err_malloc_failed, 1);
	image = mlx_put_string(fractol->mlx, zoom, x, y);
	free(zoom);
}

void	ft_ov_iterations(t_fractol *fractol, int x, int y)
{
	char				*iterations;
	static mlx_image_t	*image;
	static int			iterations_old;

	if (fractol->max_iter == iterations_old)
		return ;
	iterations_old = fractol->max_iter;
	if (image)
		mlx_delete_image(fractol->mlx, image);
	iterations = ft_itoa(fractol->max_iter);
	if (!iterations)
		ft_print_errors(err_malloc_failed, 1);
	image = mlx_put_string(fractol->mlx, iterations, x, y);
	free(iterations);
}
