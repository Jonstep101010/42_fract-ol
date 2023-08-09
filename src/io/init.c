/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:04:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/09 19:27:22 by jschwabe         ###   ########.fr       */
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
		fractol->pargs.color = rainbow;
}

/**
 * @brief set default values for fractal creation
 * 
 * @param fractol 
 */
static void	default_vals(t_program *fractol)
{
	fractol->pargs.set = MANDELBROT;
	fractol->pargs.color = default_color;
}

/**
 * @follow-up move set definition out of function?
 * @brief parse user input
 * errors on help page
 */
void	init_input(int argc, char **argv, t_program *fractol)
{
	int	i;

	i = 1;
	default_vals(fractol);
	if (argc == 1)
		return ;
	if (argc == 2 && boolcmp(argv[1], "help"))
		help_page();
	while (i < argc)
	{
		if (boolcmp(argv[i], "mandelbrot") || boolcmp(argv[i], "julia"))
		{
			if (fractol->pargs.set != NO_INIT)
				help_page();
			if (boolcmp(argv[i], "mandelbrot"))
				fractol->pargs.set = MANDELBROT;
			else if (boolcmp(argv[i], "julia"))
				fractol->pargs.set = JULIA;
		}
		else if (boolcmp(argv[i], "rainbow")
			|| boolcmp(argv[i], "default"))
			user_color(fractol, argv[i]);
		else
			help_page();
		i++;
	}
}
