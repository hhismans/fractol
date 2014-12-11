/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 06:35:47 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/01 20:46:51 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void set_rgb(int *tab, int r, int g, int b)
{
	tab[0] = r;
	tab[1] = g;
	tab[2] = b;
}

int			rainbow_gen(int x)
{
	int color;
	int tab[3];

	color = 0;
	if (x < 0 || x > 1530)
		return (0xFF0000);
	if (0 <= x && x < 255)
		set_rgb(tab, 255, x, 0);
	if (255 <= x && x < 510)
		set_rgb(tab, 510 - x, 255, 0);
	if (510 <= x && x < 765)
		set_rgb(tab, 0, 255, x - 510);
	if (765 <= x && x < 1020)
		set_rgb(tab, 0, 1020 - x, 255);
	if (x >= 1020 && x <= 1530)
		set_rgb(tab, x - 1020, 0, 255);
	if (x >= 1275 && x <= 1530)
		set_rgb(tab, 255, 0, 1530 - x);
	color = tab[0] * 0x010000 + tab[1] * 0x000100 + tab[2] * 0x000001;
	return (color);
}
