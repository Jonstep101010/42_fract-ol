/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:57:55 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 12:20:10 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
temp_z_real = 0 * 0 - 0 * 0 + (-2 + (x * (2 - (-2)) / WIDTH)) between -2 and 2
temp_z_imag = 2.0 * 0 * 0 + (-2 + (y * (2 - (-2)) / HEIGHT));-> between -2 and 2
sqrt(0 * 0 + 0 * 0) > 2.0 -> either reaches 2 or max_iter reached
	-> color determined by iter
*/

/**
 * @brief Get the color object
 * 
 * @param args struct of arguments
 * @param x position
 * @param y position
 * @return uint32_t color in hex
 */
uint32_t	get_iter_color(t_args *args, int x, int y)
{
	int		iter;
	double	z_real;
	double	z_imag;
	double	temp_z_real;
	double	temp_z_imag;

	iter = -1;
	z_real = 0.0;
	z_imag = 0.0;
	while (++iter < args->max_iter)
	{
		temp_z_real = z_real * z_real - z_imag * z_imag + 
			(args->xmin + (x * (args->xmax - args->xmin) / WIDTH));
		temp_z_imag = 2.0 * z_real * z_imag + 
			(args->ymin + (y * (args->ymax - args->ymin) / HEIGHT));
		z_real = temp_z_real;
		z_imag = temp_z_imag;
		if (sqrt(z_real * z_real + z_imag * z_imag) > 2.0)
			break ;
	}
	return (args->color_function(iter, args->max_iter));
}

		// iter++;
/**
 * @brief 
 * @follow-up zooming in and out
 * color function through iter && passing real, imag, max_iter
 */
void	mandelbrot(t_args *args)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		mlx_put_pixel(args->img, x, y, 
			get_iter_color(args, x, y));
		x++;
		if (x == WIDTH)
		{
			x = 0;
			y++;
		}
	}
}
