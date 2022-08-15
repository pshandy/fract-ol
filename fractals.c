/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:04:55 by pshandy           #+#    #+#             */
/*   Updated: 2022/04/28 15:32:13 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color_pixels(t_fractol *ptr, int color)
{
	int		i;
	int		*new_ptr;

	if (ptr->x >= 0 && ptr->x < ptr->width
		&& ptr->y >= 0 && ptr->y < ptr->height)
	{
		i = ptr->y * ptr->img->size_line + ptr->x
			* ptr->img->bits_per_pixel / 8;
		new_ptr = (int *)&ptr->img->img_data[i];
		*new_ptr = color;
	}
	return (1);
}

void	ft_julia_parameters(char *argv[], t_fractol *ptr)
{
	if (!ft_strcmp("0", argv[2]) && !ft_strcmp("0", argv[3]))
	{
		ptr->c_r = 0;
		ptr->c_i = 0;
	}
	else
	{
		ptr->c_r = ft_atof(argv[2], 1, 0.0, 1.0);
		ptr->c_i = ft_atof(argv[3], 1, 0.0, 1.0);
	}
}

void	ft_mandelbrot(t_fractol *ptr)
{
	ptr->x = 0;
	while (ptr->x < ptr->width)
	{
		ptr->y = 0;
		while (ptr->y < ptr->height)
		{
			ptr->count = 0;
			ptr->c_r = ptr->x / ptr->zoom_x + (ptr->x_min);
			ptr->c_i = ptr->y / ptr->zoom_y + (ptr->y_min);
			ptr->r = 0;
			ptr->i = 0;
			while (ptr->r * ptr->r + ptr->i * ptr->i < 4
				&& ptr->count < ptr->iteration)
			{
				ptr->temp = ptr->r;
				ptr->r = ptr->r * ptr->r - ptr->i * ptr->i + ptr->c_r;
				ptr->i = 2 * ptr->i * ptr->temp + ptr->c_i;
				ptr->count++;
			}
			ft_color_pixels(ptr, ptr->count * ptr->color / ptr->iteration);
			ptr->y++;
		}
		ptr->x++;
	}
}

void	ft_julia(t_fractol *ptr)
{
	ptr->x = 0;
	while (ptr->x < ptr->width)
	{
		ptr->y = 0;
		while (ptr->y < ptr->height)
		{
			ptr->count = 0;
			ptr->r = ptr->x / ptr->zoom_x + ptr->x_min;
			ptr->i = ptr->y / ptr->zoom_y + ptr->y_min;
			while (ptr->r * ptr->r + ptr->i * ptr->i < 4
				&& ptr->count < ptr->iteration)
			{
				ptr->temp = ptr->r;
				ptr->r = ptr->r * ptr->r - ptr->i * ptr->i + ptr->c_r;
				ptr->i = 2 * ptr->i * ptr->temp + ptr->c_i;
				ptr->count++;
			}
			ft_color_pixels(ptr, ptr->count * ptr->color / ptr->iteration);
			ptr->y++;
		}
		ptr->x++;
	}
}

void	ft_burningship(t_fractol *ptr)
{
	ptr->x = 0;
	while (ptr->x < ptr->width)
	{
		ptr->y = 0;
		while (ptr->y < ptr->height)
		{
			ptr->count = 0;
			ptr->c_r = ptr->x / ptr->zoom_x + (ptr->x_min);
			ptr->c_i = ptr->y / ptr->zoom_y + (ptr->y_min);
			ptr->r = 0;
			ptr->i = 0;
			while (ptr->r * ptr->r + ptr->i * ptr->i < 4
				&& ptr->count < ptr->iteration)
			{
				ptr->temp = ptr->r * ptr->r - ptr->i * ptr->i + ptr->c_r;
				ptr->i = fabs(2 * ptr->i * ptr->r) + ptr->c_i;
				ptr->r = ptr->temp;
				ptr->count++;
			}
			ft_color_pixels(ptr, ptr->count * ptr->color / ptr->iteration);
			ptr->y++;
		}
		ptr->x++;
	}
}
