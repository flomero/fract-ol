/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overlay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:22:48 by flfische          #+#    #+#             */
/*   Updated: 2024/04/19 13:43:35 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

void	ft_init_overlay(t_fractol *fractol)
{
	fractol->size.x = WIDTH - OVERLAY_WIDTH;
	fractol->size.y = HEIGHT;
	fractol->overlay.size.x = OVERLAY_WIDTH;
	fractol->overlay.size.y = HEIGHT;
	fractol->overlay.pos.x = WIDTH - OVERLAY_WIDTH;
	fractol->overlay.pos.y = 0;
	fractol->overlay.background = 0x343D46FF;
	fractol->overlay.text = 0xFEFEFEFF;
}

void	ft_overlay_bg(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < fractol->overlay.size.y)
	{
		x = 0;
		while (x < fractol->overlay.size.x)
		{
			mlx_put_pixel(fractol->overlay.image, x, y,
				fractol->overlay.background);
			x++;
		}
		y++;
	}
}

void	ft_draw_overlay(t_fractol *fractol)
{
	fractol->overlay.image = mlx_new_image(fractol->mlx,
			fractol->overlay.size.x, fractol->overlay.size.y);
	if (!fractol->overlay.image)
		ft_print_errors(err_mlx_new_image_failed, 1);
	if (mlx_image_to_window(fractol->mlx, fractol->overlay.image,
			fractol->overlay.pos.x, fractol->overlay.pos.y) == -1)
		ft_print_errors(err_mlx_image_to_window_failed, 1);
	ft_overlay_bg(fractol);
	ft_overlay_text(fractol);
}

void	ft_overlay_refresh(t_fractol *fractol)
{
	ft_ov_zoom(fractol, fractol->size.x + 200, ft_linenbr(L_ZOOM));
	ft_ov_iterations(fractol, fractol->size.x + 200, ft_linenbr(L_ITERATIONS));
	ft_ov_title(fractol, fractol->size.x + 200, ft_linenbr(L_TITLE));
}

void	ft_overlay_text(t_fractol *fractol)
{
	int	x;

	x = 10 + fractol->size.x;
	mlx_put_string(fractol->mlx, "fract-ol", x, ft_linenbr(0));
	mlx_put_string(fractol->mlx, "Controls", x, ft_linenbr(2));
	mlx_put_string(fractol->mlx, "Move: WASD / Arrows / Left Mouse + Drag", x,
		ft_linenbr(3));
	mlx_put_string(fractol->mlx, "Zoom: Scroll", x, ft_linenbr(4));
	mlx_put_string(fractol->mlx, "Change Fractal: 1 2 3", x, ft_linenbr(5));
	mlx_put_string(fractol->mlx, "Change Color Mode: Numpad 0-3", x,
		ft_linenbr(6));
	mlx_put_string(fractol->mlx, "Rotate Color Slow: Numpad 4", x,
		ft_linenbr(7));
	mlx_put_string(fractol->mlx, "Rotate Color Fast: Numpad 5", x,
		ft_linenbr(8));
	mlx_put_string(fractol->mlx, "Reset Zoom: R", x, ft_linenbr(9));
	mlx_put_string(fractol->mlx, "Exit: ESC", x, ft_linenbr(10));
	mlx_put_string(fractol->mlx, "Fractal", x, ft_linenbr(L_TITLE));
	mlx_put_string(fractol->mlx, "Zoom:", x, ft_linenbr(L_ZOOM));
	mlx_put_string(fractol->mlx, "Iterations:", x, ft_linenbr(L_ITERATIONS));
	mlx_put_string(fractol->mlx, "by flfische", x, ft_linenbr(51));
	ft_overlay_refresh(fractol);
}
