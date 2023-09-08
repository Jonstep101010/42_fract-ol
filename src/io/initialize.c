/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:04:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/08 12:56:54 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief sets default values for fractal creation
 */
static void	set_default_values(t_program *fractol)
{
	fractol->set_function = mandelbrot;
	fractol->args.color_function = ultra_fractal;
	fractol->args.max_iterations = MAX_ITER;
	fractol->args.scroll_zoom = true;
	fractol->args.zoom = DEFAULT_ZOOM;
	fractol->move_keys = move_keys;
	fractol->args.j_real_num = J_REAL_DEFAULT;
	fractol->args.j_imag_num = J_IMAG_DEFAULT;
	fractol->args.xmin = XY_MIN;
	fractol->args.xmax = XY_MAX;
	fractol->args.ymin = XY_MIN;
	fractol->args.ymax = XY_MAX;
	fractol->args.xmove = 0;
	fractol->args.ymove = 0;
}

/**
 * @brief initialize the fractal based on user input & default values
 */
void	initialize_input(int argc, char **argv, t_program *fractol)
{
	set_default_values(fractol);
	if (argc == 1)
		return ;
	if (argc == 2 && boolcmp(argv[1], "help"))
		help_page();
	get_user_input(argc, argv, fractol);
}
