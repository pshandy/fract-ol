/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:04:55 by pshandy           #+#    #+#             */
/*   Updated: 2022/04/28 15:32:13 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx_linux/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define LEFT_CLICK 1
# define ZOOM_OUT 4
# define ZOOM_IN 5
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_UP 126
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define KEY_C 8
# define KEY_PLUS 24
# define KEY_MINUS 27

typedef struct s_img
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*img_data;
	void	*img_ptr;
}			t_img;

typedef struct s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
	int			width;
	int			height;
	int			iteration;
	int			color;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		count;
	double		r;
	double		i;
	double		c_r;
	double		c_i;
	double		zoom_x;
	double		zoom_y;
	double		temp;
	int			img_x;
	int			img_y;
	float		shift;
	int			name;
	t_img		*img;
}				t_fractol;

int		ft_color_pixels(t_fractol *ptr, int color);
int		keyhook(int keycode, t_fractol *ptr);
int		mousehook(int button, int x, int y, t_fractol *ptr);
int		click_cross(int button, t_fractol *ptr);
int		ft_isdigit(int c);
int		ft_strcmp(char *s1, char *s2);
void	error(void);
void	help_exit(void);
void	ft_julia_parameters(char *argv[], t_fractol *ptr);
void	ft_mandelbrot(t_fractol *ptr);
void	ft_julia(t_fractol *ptr);
void	ft_burningship(t_fractol *ptr);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_choose_fractol(t_fractol *ptr);
void	ft_create_image(t_fractol *ptr);
void	ft_destroy(t_fractol *ptr);
void	ft_settings(t_fractol *ptr);
void	check(t_fractol *ptr, char **argv, int argc);
void	ft_init(t_fractol *ptr);
double	ft_atof(char *s, int sign, double nbr, double div);

#endif
