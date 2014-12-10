/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:35:09 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/09 15:36:34 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fractol.h"

void	mandelbrot(double *xi, double *yi, double x, double y)
{
	int tmp;
	tmp = *xi;
	*xi = (*xi * *xi + *yi * *yi) + x;
	*yi = 2 * tmp * *yi + y;
}
int		is_converg((eq*)(double, double), double x, double y)
{
	int i;
	double xi;
	double yi;
	double tmp;

	xi = 0;
	yi = 0;
	while (xi * xi + yi * yi < 4 && i < max)
	{
		tmp = xi;
		xi = (xi * xi + yi * yi) + x;
		yi = 2 * tmp * yi + y;
		i++;
	}
	return (i);
}

int		main(void)
{
	int x;
	int y;
	int nb_it;
	double x_f;
	double y_f;
	double stepx;
	double stepy;

	stepx = (xmax - xmin) / WX;
	stepy = (ymax - ymin) / WY;
	x = 0;
	x_f = xmin
	while (x < WX)
	{
		y = 0;
		y_f = ymin;
		while (y < WY)
		{
			nb_it = is_converg((mandelbrot), x_f, y_f);
			y++;
		}
		x++;
	}
}
