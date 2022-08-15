/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_lifecycle.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:04:55 by pshandy           #+#    #+#             */
/*   Updated: 2022/04/28 15:32:13 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_choose_fractol(t_fractol *ptr)
{
	if (ptr->name == 1)
		ft_julia(ptr);
	else if (ptr->name == 2)
		ft_mandelbrot(ptr);
	else if (ptr->name == 3)
		ft_burningship(ptr);
}

void	ft_create_image(t_fractol *ptr)
{
	ptr->img->img_ptr = mlx_new_image(ptr->mlx_ptr,
			ptr->width, ptr->height);
	if (!ptr->img->img_ptr)
		error();
	ptr->img->img_data = mlx_get_data_addr(ptr->img->img_ptr,
			&ptr->img->bits_per_pixel, &ptr->img->size_line, &ptr->img->endian);
	if (!ptr->img->img_data)
		error();
	ft_choose_fractol(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
		ptr->img->img_ptr, 0, 0);
}

void	ft_destroy(t_fractol *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->img_ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	free(ptr->img);
	free(ptr->mlx_ptr);
	free(ptr);
	exit(0);
}
