/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:57:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/07 20:52:22 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	j_calculate_color(t_args *args, double x, double y);

void	julia(t_args *args)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		mlx_put_pixel(args->img, x, y, j_calculate_color(args, x, y));
		x++;
		if (x == WIDTH)
		{
			x = 0;
			y++;
		}
	}
}

static uint32_t	j_calculate_color(t_args *args, double x, double y)
{
	t_julia	j;

	j.max_iterations = args->max_iterations * (args->zoom * args->zoom);
	j.iterations = -1;
	j.zx = args->xmin + (x * ((args->xmax - args->xmin) / WIDTH));
	j.zy = args->ymin + (y * ((args->ymax - args->ymin) / HEIGHT));
	while (++j.iterations < args->max_iterations)
	{
		j.tmp = j.zx * j.zx - j.zy * j.zy + args->j_real_num;
		j.zy = 2 * j.zx * j.zy + args->j_imag_num;
		j.zx = j.tmp;
		if (sqrt(j.zx * j.zx + j.zy * j.zy) > 4.0)
			break ;
	}
	return (args->color_function(j.iterations, args->max_iterations,
			args->zoom));
}
/*
basically similar to mandelbrot set, with some differences

- using j.zx as x, z_img as y, limiting the sqrt result to 4

- using the input variables of j_real & j_imag (0.6 and -0.6 default)

- most important visualization step is color scheme

*/
