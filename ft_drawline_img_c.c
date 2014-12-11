/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 13:29:38 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/05 03:47:53 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "fdf.h"
#include <unistd.h>
#include <math.h>

void		case_horiz(void *img_ptr, t_point p1, t_point p2, int c)
{
	int dx;
	int dy;
	int e;

	dy = (p2.y - p1.y) * 2;
	e = p2.x - p1.x;
	dx = 2 * e;
	while (p1.x <= p2.x)
	{
		mlx_pixel_put_img(img_ptr, p1.x, p1.y, c);
		e = e - dy;
		if (e <= 0)
		{
			p1.y++;
			e = e + dx;
		}
		p1.x++;
	}
}

void		case_horizneg(void *img_ptr, t_point p1, t_point p2, int c)
{
	int dx;
	int dy;
	int e;

	dy = (p1.y - p2.y) * 2;
	e = p2.x - p1.x;
	dx = 2 * e;
	while (p1.x <= p2.x)
	{
		mlx_pixel_put_img(img_ptr, p1.x, p1.y, c);
		e = e - dy;
		if (e <= 0)
		{
			p1.y--;
			e = e + dx;
		}
		p1.x++;
	}
}

void		case_verti(void *img_ptr, t_point p1, t_point p2, int c)
{
	int dx;
	int dy;
	int e;

	dx = (p2.x - p1.x) * 2;
	e = p2.y - p1.y;
	dy = 2 * e;
	while (p1.y <= p2.y)
	{
		mlx_pixel_put_img(img_ptr, p1.x, p1.y, c);
		e = e - dx;
		if (e <= 0)
		{
			p1.x++;
			e = e + dy;
		}
		p1.y++;
	}
}

void		case_vertineg(void *img_ptr, t_point p1, t_point p2, int c)
{
	int dx;
	int dy;
	int e;

	e = p2.y - p1.y;
	dx = (p1.x - p2.x) * 2;
	dy = 2 * e;
	while (p1.y >= p2.y)
	{
		mlx_pixel_put_img(img_ptr, p1.x, p1.y, c);
		e = e + dx;
		if (e <= 0)
		{
			p1.x++;
			e = e - dy;
		}
		p1.y--;
	}
}

void		ft_drawline_img_c(void *img_ptr, t_point p1, t_point p2, int c)
{
	int dx;
	int dy;

	if ((dx = p2.x - p1.x) != 0)
	{
		if (dx > 0)
		{
			if ((dy = p2.y - p1.y) != 0)
				ft_drawline_img_c_1(img_ptr, p1, p2, c);
			else
				ft_drawline_img_c_2(img_ptr, p1, p2, c);
		}
		else
		{
			ft_drawline_img_c(img_ptr, p2, p1, c);
		}
	}
	else
	{
		ft_drawline_img_c_3(img_ptr, p1, p2, c);
	}
}
