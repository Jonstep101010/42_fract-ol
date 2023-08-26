/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:04:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 12:33:58 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief 
 * errors on multiple color inputs
 * @param fractol 
 * @param color 
 */
static void	user_color(t_program *fractol, char *color)
{
	if (fractol->args.color != NO_COLOR)
		help_page();
	// if (boolcmp(color, "rainbow"))
	// 	fractol->args.color = RAINBOW;
	// if (fractol->args.color == default_color)
	// 	fractol->color_function = rainbow;
	if (boolcmp(color, "rainbow"))
		fractol->args.color_function = rainbow;
	// else if (boolcmp(color, "default"))
	// 	fractol->args.color = RAINBOW;
	else if (boolcmp(color, "default"))
		fractol->args.color_function = rainbow;
}

/**
 * @brief set default values for fractal creation
 * @follow-up values missing (structs.h)
 * @param fractol 
 */
static void	default_vals(t_program *fractol)
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

//@todo add input for julia set
static void	user_vals(int argc, char **argv, t_program *fractol)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (boolcmp(argv[i], "iter:") && fractol->args.max_iter == MAX_ITER
			&& ft_atoi(argv[i] + 5) > 0)
			fractol->args.max_iter = ft_atoi(argv[i] + 5);
		else if (boolcmp(argv[i], "mandelbrot") || boolcmp(argv[i], "julia"))
			define_set(argv[i], fractol);
		else if (boolcmp(argv[i], "rainbow"))
			user_color(fractol, argv[i]);
		else
			help_page();
		i++;
	}
}

/**
 * @follow-up move set definition out of function?
 * @brief parse user input
 * errors on help page
 */
void	init_input(int argc, char **argv, t_program *fractol)
{
	default_vals(fractol);
	if (argc == 1)
		return ;
	if (argc == 2 && boolcmp(argv[1], "help"))
		help_page();
	user_vals(argc, argv, fractol);
}
