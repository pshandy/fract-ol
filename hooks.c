/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:04:55 by pshandy           #+#    #+#             */
/*   Updated: 2022/04/28 15:32:13 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keyhook(int keycode, t_fractol *ptr)
{
	if (keycode == ESC || keycode == 65307)
		ft_destroy(ptr);
	if (keycode == KEY_C || keycode == 99)
		ptr->color = ptr->color + 0xFF;
	if (keycode == ARROW_UP || keycode == 65362)
		ptr->y_min = ptr->y_min - ptr->shift;
	if (keycode == ARROW_DOWN || keycode == 65364)
		ptr->y_min = ptr->y_min + ptr->shift;
	if (keycode == ARROW_LEFT || keycode == 65361)
		ptr->x_min = ptr->x_min - ptr->shift;
	if (keycode == ARROW_RIGHT || keycode == 65363)
		ptr->x_min = ptr->x_min + ptr->shift;
	if (keycode == KEY_PLUS || keycode == 65451)
		ptr->iteration = ptr->iteration + 50;
	if (keycode == KEY_MINUS || keycode == 65453)
		ptr->iteration = ptr->iteration - 50;
	ft_create_image(ptr);
	return (0);
}

int	mousehook(int button, int x, int y, t_fractol *ptr)
{
	double	dummy_x;
	double	dummy_y;

	if (button == ZOOM_IN || button == ZOOM_OUT)
	{
		dummy_x = x / ptr->zoom_x + (ptr->x_min);
		dummy_y = y / ptr->zoom_y + (ptr->y_min);
		if (button == ZOOM_IN)
		{
			ptr->zoom_x *= 0.5;
			ptr->zoom_y *= 0.5;
			ptr->shift /= 0.5;
		}
		if (button == ZOOM_OUT)
		{
			ptr->zoom_x /= 0.8;
			ptr->zoom_y /= 0.8;
			ptr->shift *= 0.8;
		}
		ptr->x_min = dummy_x - (x / ptr->zoom_x);
		ptr->y_min = dummy_y - (y / ptr->zoom_y);
	}
	ft_create_image(ptr);
	return (0);
}

int	click_cross(int button, t_fractol *ptr)
{
	(void)ptr;
	exit(0);
}
