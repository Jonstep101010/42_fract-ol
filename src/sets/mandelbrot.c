/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:57:55 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/18 18:10:06 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_iter(double real, double imag, int max_iter, double max_val)
{
	double	z_real;
	double	z_imag;
	double	temp_z_real;
	double	temp_z_imag;
	int		iter;

	z_real = 0.0;
	z_imag = 0.0;
	iter = 0;
	while (iter < max_iter)
	{
		temp_z_real = z_real * z_real - z_imag * z_imag + real;
		temp_z_imag = 2 * z_real * z_imag + imag;
		z_real = temp_z_real;
		z_imag = temp_z_imag;
		if (sqrt(z_real * z_real + z_imag * z_imag) > max_val)
			break ;
		iter++;
	}
	return (iter);
}
// {
// 	double	z_real;
// 	double	z_imag;
// 	double	temp_z_real;
// 	double	temp_z_imag;
// 	int		iter;

// 	z_real = 0.0;
// 	z_imag = 0.0;
// 	iter = 0;
// 	while (iter < pargs->max_iter)
// 	{
// 		temp_z_real = sqrt(z_real) - sqrt(z_imag) + real;
// 		temp_z_imag = pargs->max_val * z_real * z_imag + imag;
// 		z_real = temp_z_real;
// 		z_imag = temp_z_imag;
// 		if (sqrt(sqrt(z_real) + sqrt(z_imag)) > pargs->max_val)
// 			break ; 
// 		iter++;
// 	}
// 	return (iter);
// }

uint32_t	put_rainbow(int iterations, int max_iterations)
{
	if (iterations == max_iterations)
		return (0xE40303FF);
	else if (iterations <= (double)max_iterations * 0.02)
		return (0x732982FF);
	else if (iterations <= (double)max_iterations * 0.05)
		return (0x24408EFF);
	else if (iterations <= (double)max_iterations * 0.15)
		return (0x008026FF);
	else if (iterations <= (double)max_iterations * 0.4)
		return (0xFFED00FF);
	else if (iterations <= (double)max_iterations * 0.8)
		return (0xFF8C00FF);
	else
		return (0xE40303FF);
}

static uint32_t	getpartial(int iterations, int maxIterations,
					uint32_t endcolour)//@note shifting using endcolor/bitwise
{
	double		itergrad;
	uint8_t		blue;
	uint8_t		green;
	uint8_t		red;
	uint32_t	start_colour;

	itergrad = (double)iterations / maxIterations;
	start_colour = 0x000000;
	blue = (uint8_t)((1 - itergrad) * ((start_colour >> 16) & 0xFF)
			+ itergrad * ((endcolour >> 16) & 0xFF));
	green = (uint8_t)((1 - itergrad) * ((start_colour >> 8) & 0xFF)
			+ itergrad * ((endcolour >> 8) & 0xFF));
	red = (uint8_t)((1 - itergrad) * (start_colour & 0xFF)
			+ itergrad * (endcolour & 0xFF));
	return ((blue << 24) | (green << 16) | (red << 8) | 0xFF);
}


uint32_t	intergrad(int iterations, int max_iterations)
{
	if (iterations == max_iterations)
		return (0x000000FF);
	else if (iterations <= max_iterations / 4)
		return ((getpartial(iterations, max_iterations / 4, 0xFF0000)));
	else if (iterations <= max_iterations / 2)
		return (getpartial(iterations, max_iterations / 2, 0xFFF700));
	else if (iterations <= max_iterations * (3 / 4))
		return (getpartial(iterations, max_iterations * (3.0 / 4.0), 0x07FF00));
	else
		return (getpartial(iterations, max_iterations, 0x0012FF));
}

// uint32_t	get_color(t_program *fractol, int iter, int max_iter)
// {
// 	// if (fractol->pargs.color == rainbow)
// 	return (put_rainbow(iter, max_iter));
// 	// else if (params.colour == SHIFT)
// 	// 	return (shifting_range(iterations, max_iterations, params));
// 	// else if (params.colour == TUVALU)
// 	// 	return (tuvalu(iterations, max_iterations));
// 	// else if (params.colour == INDIA)
// 	// 	return (india(iterations, max_iterations));
// 	// else
// 	// 	return (intergrad(iterations, max_iterations));
// }

/**
 * @brief 
 * @follow-up zooming in and out
 */
void	mandelbrot(t_program *fractol)
{
	int		x;
	int		y;
	int		pxl_iter;
	// double	real;
	// double	imag;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		pxl_iter = get_iter(fractol->pargs.xmin
				+ (x * (fractol->pargs.xmax - fractol->pargs.xmin) / WIDTH),
				fractol->pargs.ymin + (y * (fractol->pargs.ymax - fractol->pargs.ymin) / HEIGHT),
				fractol->pargs.max_iter, fractol->pargs.max_val);
		mlx_put_pixel(fractol->img , x, y, put_rainbow(pxl_iter, fractol->pargs.max_iter));
		x++;
		if (x == WIDTH)
		{
			x = 0;
			y++;
		}
	}
	return ;
}

