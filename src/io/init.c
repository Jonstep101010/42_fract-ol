/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:04:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/20 21:42:16 by jschwabe         ###   ########.fr       */
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
	if (fractol->pargs.color != default_color)
		help_page();
	if (boolcmp(color, "rainbow"))
		fractol->pargs.color = RAINBOW;
	else if (boolcmp(color, "default"))
		fractol->pargs.color = RAINBOW;
}

/**
 * @brief set default values for fractal creation
 * @follow-up values missing (structs.h)
 * @param fractol 
 */
static void	default_vals(t_program *fractol)
{
	fractol->pargs.set = MANDELBROT;
	fractol->pargs.color = default_color;
	fractol->pargs.max_iter = 30;
	fractol->pargs.xmin = -2;
	fractol->pargs.xmax = 2;
	fractol->pargs.ymin = -2;
	fractol->pargs.ymax = 2;
	fractol->pargs.j_real_num = 0;
	fractol->pargs.j_img_num = 0;
}
	// fractol->pargs.max_val = 2.0;

static void	user_vals(int argc, char **argv, t_program *fractol)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (boolcmp(argv[i], "iter:") && fractol->pargs.max_iter == 18)
			fractol->pargs.max_iter = ft_atoi(argv[i] + 5);
		if (boolcmp(argv[i], "mandelbrot") || boolcmp(argv[i], "julia"))
			define_set(argv[i], fractol);
		else if (boolcmp(argv[i], "rainbow")
			|| boolcmp(argv[i], "default"))
			user_color(fractol, argv[i]);
		else
			help_page();
		i++;
	}
	if (fractol->pargs.max_iter <= 0)
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
	if (fractol->pargs.color == default_color)
		fractol->pargs.color = RAINBOW;
}
