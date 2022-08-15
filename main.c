/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                            			         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:04:55 by pshandy           #+#    #+#             */
/*   Updated: 2022/04/28 15:32:13 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_settings(t_fractol *ptr)
{
	ptr->x_min = -3.0;
	ptr->x_max = 2.0;
	ptr->y_min = -3.0;
	ptr->y_max = 2.0;
	ptr->zoom_x = 100;
	ptr->zoom_y = 100;
	ptr->iteration = 300;
	ptr->color = 0xFFFFFF / 20;
	ptr->shift = 0.1;
}

void	check(t_fractol *ptr, char **argv, int argc)
{
	if (ft_strcmp("Julia", argv[1]) == 0)
	{
		ptr->name = 1;
		if (argc != 4)
			help_exit();
		ft_julia_parameters(argv, ptr);
	}
	else if (ft_strcmp("Mandelbrot", argv[1]) == 0)
		ptr->name = 2;
	else if (ft_strcmp("Burningship", argv[1]) == 0)
		ptr->name = 3;
	else
		help_exit();
}

void	ft_init(t_fractol *ptr)
{
	ptr->mlx_ptr = mlx_init();
	if (!ptr->mlx_ptr)
		error();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr,
			ptr->width, ptr->height, "Fract-ol" );
	if (!ptr->win_ptr)
		error();
	ft_create_image(ptr);
	mlx_key_hook(ptr->win_ptr, keyhook, ptr);
	mlx_mouse_hook(ptr->win_ptr, mousehook, ptr);
	mlx_hook(ptr->win_ptr, 17, 2, click_cross, ptr);
	mlx_loop(ptr->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_fractol	*ptr;

	if (!(argc <= 4 && argc >= 2))
		help_exit();
	ptr = malloc(sizeof(t_fractol));
	if (ptr == NULL)
		error();
	ptr->width = 600;
	ptr->height = 600;
	ptr->img = malloc(sizeof(t_img));
	if (ptr->img == NULL)
		error();
	check(ptr, argv, argc);
	ft_settings(ptr);
	ft_init(ptr);
}
