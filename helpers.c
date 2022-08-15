/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:04:55 by pshandy           #+#    #+#             */
/*   Updated: 2022/04/28 15:32:13 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double	ft_atof(char *s, int sign, double nbr, double div)
{
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		nbr = nbr * 10.0 + (*s - '0');
		s++;
	}
	if (*s == '.')
		s++;
	if (!ft_isdigit(*s))
		error();
	while (ft_isdigit(*s))
	{
		nbr = nbr * 10.0 + (*s - '0');
		div *= 10.0;
		s++;
	}
	if (*s && !ft_isdigit(*s))
		error();
	return (nbr * sign / div);
}
