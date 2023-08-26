/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:57:55 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 22:33:51 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	calculate_mandelbrot_color(t_args *args, double cx, double cy)
{
	t_mandelbrot	m;

	m.iterations = -1;
	m.zx = 0.0;
	m.zy = 0.0;
	cx = (args->xmin + (cx * (args->xmax - args->xmin) / WIDTH));
	cy = (args->ymin + (cy * (args->ymax - args->ymin) / HEIGHT));
	while (++m.iterations < args->max_iterations)
	{
		m.new_zx = m.zx * m.zx - m.zy * m.zy + cx;
		m.new_zy = 2.0 * m.zx * m.zy + cy;
		m.zx = m.new_zx;
		m.zy = m.new_zy;
		if (sqrt(m.zx * m.zx + m.zy * m.zy) > 2.0)
			break ;
	}
	return (args->color_function(m.iterations, args->max_iterations));
}

void	mandelbrot(t_args *args)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		mlx_put_pixel(args->img, x, y, calculate_mandelbrot_color(args, x, y));
		x++;
		if (x == WIDTH)
		{
			x = 0;
			y++;
		}
	}
}

/*
cx -> between -2 and 2
cy -> between -2 and 2
sqrt(0 * 0 + 0 * 0) > 2.0 -> either reaches 2 or max_iter reached
	-> color determined by iterations
*/
