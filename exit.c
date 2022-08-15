/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:04:55 by pshandy           #+#    #+#             */
/*   Updated: 2022/04/28 15:32:13 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	ft_putstr("error!\n");
	exit(0);
}

void	help_exit(void)
{
	ft_putstr("Usage:\n");
	ft_putstr("./fractol Mandelbrot\n");
	ft_putstr("./fractol Julia [coordinate] [coordinate]\n");
	ft_putstr("./fractol Burningship\n");
	exit(0);
}
