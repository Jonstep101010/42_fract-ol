/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 23:17:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 23:25:44 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	get_iter_color_burning_ship(double x, double y, t_args *args)
{
	double	zreal;
	double	zimg;
	double	temp;
	int		iter;
	double	c_real;
	double	c_img;

	c_real = zreal;
	c_img = zimg;

	iter = -1;
	zreal = args->xmin + (x * ((args->xmax - args->xmin) / WIDTH));
	zimg = args->ymin + (y * ((args->ymax - args->ymin) / HEIGHT));

	while (++iter < args->max_iterations)
	{
		zreal = fabs(zreal);
		zimg = fabs(zimg);
		temp = zreal * zreal - zimg * zimg + c_real;
		zimg = 2 * zreal * zimg + c_img;
		zreal = temp;
		if (sqrt(zreal * zreal + zimg * zimg) > 4.0)
			break ;
	}
	return (args->color_function(iter, args->max_iterations));
}

void	burning_ship(t_args *args)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		mlx_put_pixel(args->img, x, y, get_iter_color_burning_ship(x, y, args));
		x++;
		if (x == WIDTH)
		{
			x = 0;
			y++;
		}
	}
	return ;
}
