/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:57:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 22:32:26 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	calculate_julia_color(t_args *args, double x, double y)
{
	t_julia	j;

	j.iterations = -1;
	j.zx = args->xmin 
		+ (x * ((args->xmax - args->xmin)
				/ WIDTH));
	j.zy = args->ymin 
		+ (y * ((args->ymax - args->ymin)
				/ HEIGHT));
	while (++j.iterations < args->max_iterations)
	{
		j.new = j.zx * j.zx - j.zy * j.zy + args->j_real_num;
		j.zy = 2 * j.zx * j.zy + args->j_img_num;
		j.zx = j.new;
		if (sqrt(j.zx * j.zx + j.zy * j.zy) > 4.0)
			break ;
	}
	return (args->color_function(j.iterations, args->max_iterations));
}

void	julia(t_args *args)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		mlx_put_pixel(args->img, x, y, calculate_julia_color(args, x, y));
		x++;
		if (x == WIDTH)
		{
			x = 0;
			y++;
		}
	}
	return ;
}

/*
basically similar to mandelbrot set, with some differences

- using j.zx as x, z_img as y, limiting the sqrt result to 4

- using the input variables of j_real & j_imag (0.6 and -0.6 default)

- most important visualization step is color scheme

*/
