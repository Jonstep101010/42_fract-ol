/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:04:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 11:37:16 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**@note help page for printing out file?
 * @brief print out help page for user (undefined/incorrect)
 * 
 */
static void	help_page(void)
{
	ft_printf("This will be our manual\n");
	exit(EXIT_FAILURE);
}

/**
 * @brief 
 * errors on multiple color inputs
 * @param fractol 
 * @param color 
 */
static void	user_color(t_program *fractol, char *color)
{
	if (fractol->args.set != NO_COLOR)
		help_page();
	// if (boolcmp(color, "rainbow"))
	// 	fractol->args.color = RAINBOW;
	// if (fractol->args.color == default_color)
	// 	fractol->color_function = rainbow;
	if (boolcmp(color, "rainbow"))
		fractol->color_function = rainbow;
	// else if (boolcmp(color, "default"))
	// 	fractol->args.color = RAINBOW;
	else if (boolcmp(color, "default"))
		fractol->color_function = rainbow;
}

/**
 * @brief set default values for fractal creation
 * @follow-up values missing (structs.h)
 * @param fractol 
 */
static void	default_vals(t_program *fractol)
{
	fractol->args.set = NO_INIT;
	fractol->color_function = rainbow;
	fractol->set_function = mandelbrot;
	fractol->args.color = NO_COLOR;
	fractol->args.max_iter = 30;
	fractol->args.xmin = -2;
	fractol->args.xmax = 2;
	fractol->args.ymin = -2;
	fractol->args.ymax = 2;
	fractol->args.j_real_num = 0.6;
	fractol->args.j_img_num = -0.6;
}
// fractol->args.max_val = 2.0;

static void	user_vals(int argc, char **argv, t_program *fractol)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (boolcmp(argv[i], "iter:") && fractol->args.max_iter == 18)
			fractol->args.max_iter = ft_atoi(argv[i] + 5);
		if (boolcmp(argv[i], "mandelbrot") || boolcmp(argv[i], "julia"))
			define_set(argv[i], &(fractol->args));
		else if (boolcmp(argv[i], "rainbow")
			|| boolcmp(argv[i], "default"))
			user_color(fractol, argv[i]);
		else
			help_page();
		i++;
	}
	if (fractol->args.max_iter <= 0)
		help_page();
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
