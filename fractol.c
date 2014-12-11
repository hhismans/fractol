/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:35:09 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/11 19:33:03 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fractol.h"
#include <stdio.h>
#include <mlx.h>


void	mandelbrot(double *xi, double *yi, double x, double y)
{
	double tmp;
	tmp = *xi;
	*xi = (*xi * *xi - *yi * *yi) + x;
	*yi = 2 * tmp * *yi + y;
}

int		is_converg(void (*eq)(double *, double *, double, double), double x, double y)
{
	int i;
	double xi;
	double yi;
	double tmp;

	xi = 0;
	yi = 0;
	i = 0;
	while ((xi * xi + yi * yi) < 4 && i < 1000)
	{
		eq(&xi, &yi, x, y);
		i++;
	}
	return (i);
}

void	set_env(t_env *e, char *title, int w, int h)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, w, h, title);
	e->img = mlx_new_image(e->mlx, w, h);
	e->xmax = XMAX;
	e->xmin = XMIN;
	e->ymax = YMAX;
	e->ymin = YMIN;
	e->nbr_clic = 0;
	e->stepx = (double)(e->xmax - e->xmin) / WX;
	e->stepy = (double)(e->ymax - e->ymin) / WY;
}

int		mouse_hook(int boutton, int x, int y, t_env *e)
{
	printf("bouton = %d, x = %d, y = %d\n", boutton, x, y);
	if (boutton == LEFT_CLIC)
	{
		if (e->nbr_clic == 0)
		{
			ft_putstr("in nrbclic = 0");
			e->nbr_clic++;
			e->xmintmp = e->xmin;
			e->ymintmp = e->ymin;
			e->xmin = e->xmin + x * e->stepx;
			e->ymin = e->ymin + y * e->stepy;
		}
		else if (e->nbr_clic == 1)
		{
			ft_putstr("in nrbclic = 1");
			e->nbr_clic = 0;
			e->xmax = e->xmintmp + x * e->stepx;
			e->ymax = e->ymintmp + y * e->stepy;
			e->stepx = (double)(e->xmax - e->xmin) / WX;
			e->stepy = (double)(e->ymax - e->ymin) / WY;
			double x_f;
			double y_f;
			int nb_it;
			mlx_destroy_image(e->mlx, e->img);
			e->img = mlx_new_image(e->mlx, WX, WY);
			x_f = e->xmin;
			x = 0;
			while (x <= WX)
			{
				y = 0;
				y_f = e->ymin;
				while (y <= WY)
				{
					nb_it = is_converg((mandelbrot), x_f, y_f);
			//			printf("val x_f = %lf, val de y_f = %lf, val de nb_it = %d\n", x_f, y_f, nb_it);
			//			printf("val stepx= %lf, val de stepy = %lf, val de y %d= \n",e->stepx, e->stepy, y);
					if (nb_it < 1000)
						mlx_pixel_put_img(e->img, x, y, rainbow_gen(nb_it * 40));
					else
						mlx_pixel_put_img(e->img, x, y, 0x000000);
					y++;
					y_f += e->stepy;
				}
				x_f += e->stepx;
				x++;
			}
			mlx_put_image_to_window(e->mlx, e->win, e->img, 0,0);
		}
	}
	return (0);
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
	t_env e;

	set_env(&e, "titre", WX, WY);
	x = 0;
	x_f = e.xmin;
	while (x <= WX)
	{
		y = 0;
		y_f = e.ymin;
		while (y <= WY)
		{
			nb_it = is_converg((mandelbrot), x_f, y_f);
			//	printf("val x_f = %lf, val de y_f = %lf, val de nb_it = %d\n", x_f, y_f, nb_it);
			if (nb_it < 1000)
				mlx_pixel_put_img(e.img, x, y, rainbow_gen(nb_it * 40));
			y++;
			y_f += e.stepy;
		}
		x_f += e.stepx;
		x++;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0,0);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
