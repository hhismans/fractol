/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:48:33 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/11 17:26:36 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <mlx.h>
#include "fractol.h"
void	mlx_pixel_put_img(void *img_ptr, int x, int y, int color)
{
	char	*data;
	int		bbp;
	int		sizeline;
	int		endian;
	int		i;

	data = mlx_get_data_addr(img_ptr, &bbp, &sizeline, &endian);
	bbp /= 8;
	i = x * bbp + y * sizeline;
	if (WX * bbp + WY * sizeline < i)
		return ;
	if (x >= 0 && y >= 0)
	{
		data[i] = color;
		data[i + 1] = color >> 8;
		data[i + 2] = color >> 16;
	}
}
