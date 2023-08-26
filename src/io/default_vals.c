/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_vals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:42:04 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 16:42:56 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief set default values for fractal creation
 * @follow-up values missing (structs.h)
 * @param fractol 
 */
void	default_vals(t_program *fractol)
{
	fractol->args.set = NO_INIT;
	fractol->set_function = mandelbrot;
	fractol->args.color = NO_COLOR;
	fractol->args.color_function = rainbow;
	fractol->args.max_iter = MAX_ITER;
	fractol->args.xmin = -2;
	fractol->args.xmax = 2;
	fractol->args.ymin = -2;
	fractol->args.ymax = 2;
	fractol->args.j_real_num = 0.6;
	fractol->args.j_img_num = -0.6;
}
