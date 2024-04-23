/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overlay_dynamic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:11:09 by flfische          #+#    #+#             */
/*   Updated: 2024/04/23 11:22:35 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

void	ft_ov_title(t_fractol *fractol, int x, int y)
{
	static mlx_image_t	*image;
	static t_fractals	fractal_old;

	if (fractal_old == fractol->fractal)
		return ;
	fractal_old = fractol->fractal;
	if (image)
		mlx_delete_image(fractol->mlx, image);
	if (fractol->fractal == julia)
		image = mlx_put_string(fractol->mlx, TITLE_JULIA, x, y);
	else if (fractol->fractal == mandelbrot)
		image = mlx_put_string(fractol->mlx, TITLE_MANDELBROT, x, y);
	else if (fractol->fractal == burningship)
		image = mlx_put_string(fractol->mlx, TITLE_BURNINGSHIP, x, y);
}

void	ft_ov_zoom(t_fractol *fractol, int x, int y)
{
	char				*zoom;
	static mlx_image_t	*image;
	static double		zoom_old;
	static t_fractals	fractal_old;

	if (fractol->zoom == zoom_old && zoom_old != 0
		&& fractal_old == fractol->fractal)
		return ;
	zoom_old = fractol->zoom;
	fractal_old = fractol->fractal;
	if (image)
		mlx_delete_image(fractol->mlx, image);
	zoom = ft_itoa(fractol->zoom / INIT_ZOOM);
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
	static t_fractals	fractal_old;

	if (fractol->max_iter == iterations_old && iterations_old != 0
		&& fractal_old == fractol->fractal)
		return ;
	iterations_old = fractol->max_iter;
	fractal_old = fractol->fractal;
	if (image)
		mlx_delete_image(fractol->mlx, image);
	iterations = ft_itoa(fractol->max_iter);
	if (!iterations)
		ft_print_errors(err_malloc_failed, 1);
	image = mlx_put_string(fractol->mlx, iterations, x, y);
	free(iterations);
}
