/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:57:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 11:39:18 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief 
 * 
 * @param fractol 
 */
// void	julia(t_program *fractol)
// {
// 	(void)fractol;
// 	return ;
// }


// static int	getiteration(double x, double y, t_args *args);

// void	julia(t_program *fractol)
// {
// 	int		x;
// 	int		y;
// 	int		pxlval;

// 	x = 0;
// 	y = 0;
// 	while (y < HEIGHT)
// 	{
// 		pxlval = getiteration(fractol->pargs.xmin
// 				+ (x * ((fractol->pargs.xmax - fractol->pargs.xmin) / WIDTH)),
// 				fractol->pargs.ymin + (y * ((fractol->pargs.ymax - fractol->pargs.ymin) / HEIGHT)),
// 				 &(fractol->pargs));
// 		mlx_put_pixel(fractol->img, x, y, get_color(&(fractol->pargs), pxlval));
// 		x++;
// 		if (x == WIDTH)
// 		{
// 			x = 0;
// 			y++;
// 		}
// 	}
// 	return ;
// }

/*
basically similar to mandelbrot set, with some differences

- using z_real as x, z_img as y, limiting the sqrt result to 4

- using the input variables of j_real & j_imag (0.6 and -0.6 default)

- most important visualization step is color scheme

*/

// static int	getiteration(double x, double y, t_args *args)
// {
// 	double	zreal;
// 	double	zimg;
// 	double	temp;
// 	int		iter;

// 	iter = 0;
// 	zreal = x;
// 	zimg = y;
// 	while (iter < args->max_iter)
// 	{
// 		temp = zreal * zreal - zimg * zimg + args->j_real_num;
// 		zimg = 2 * zreal * zimg + args->j_img_num;
// 		zreal = temp;
// 		if (sqrt(zreal * zreal + zimg * zimg) > 4)
// 			break ;
// 		iter++;
// 	}
// 	return (iter);
// }
