/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:50:56 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/11 19:33:59 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BLUE 0x0000FF
#define RED 0xFF0000
#define WX 1000
#define WY 700
#define XMIN -2
#define XMAX 1
#define YMIN -1
#define YMAX 1
#define it_max 1000

#define LEFT_CLIC 1
#define RIGHT_CLIC 3
#define MOL_CLIC 2
#define MOL_UP 4
#define MOL_DOWN 5

void	mlx_pixel_put_img(void *img_ptr, int x, int y, int color);
static void set_rgb(int *tab, int r, int g, int b);
typedef struct s_env
{
	void	*mlx;
	void	*img;
	void	*win;

	double		xmintmp;
	double		ymintmp;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double stepx;
	double stepy;
	int		nbr_clic;
}				t_env;
