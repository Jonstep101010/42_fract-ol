/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:04:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 23:24:15 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief set default values for fractal creation
 * @follow-up values missing (structs.h)
 * @param fractol 
 */
static void	set_default_values(t_program *fractol)
{
	fractol->args.set = NO_INIT;
	fractol->set_function = mandelbrot;
	fractol->args.color = NO_COLOR;
	fractol->args.color_function = rainbow;
	fractol->args.max_iterations = MAX_ITER;
	fractol->args.xmin = -2;
	fractol->args.xmax = 2;
	fractol->args.ymin = -2;
	fractol->args.ymax = 2;
	fractol->args.j_real_num = 0.6;
	fractol->args.j_img_num = -0.6;
}

/**
 * @brief matches function pointer to set
 */
static void	user_set(char *set, t_program *fractol)
{
	if (fractol->args.set != NO_INIT)
		help_page();
	else if (boolcmp(set, "mandelbrot"))
		fractol->set_function = mandelbrot;
	else if (boolcmp(set, "julia"))
		fractol->set_function = julia;
	else if (boolcmp(set, "burning_ship"))
		fractol->set_function = burning_ship;
	else
		return ;
	fractol->args.set = init_set;
}

/**
 * @brief matches function pointer to color scheme
 * @details errors on multiple color inputs
 * @param color scheme name
 */
static void	user_color(t_args *args, char *color)
{
	if (args->color != NO_COLOR)
		help_page();
	else if (boolcmp(color, "rainbow"))
		args->color_function = rainbow;
	else if (boolcmp(color, "tuvalu"))
		args->color_function = rainbow;
	else
		return ;
	args->color = init_color;
}

//@todo add input for julia set
static void	get_user_input(int argc, char **argv, t_program *fractol)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (boolcmp(argv[i], "iter:") && fractol->args.max_iterations
			== MAX_ITER && ft_atoi(argv[i] + 5) > 0)
			fractol->args.max_iterations = ft_atoi(argv[i] + 5);
		else if (boolcmp(argv[i], "mandelbrot") || boolcmp(argv[i], "julia")
			|| boolcmp(argv[i], "burning_ship"))
			user_set(argv[i], fractol);
		else if (boolcmp(argv[i], "rainbow"))
			user_color(&(fractol->args), argv[i]);
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
void	initialize_input(int argc, char **argv, t_program *fractol)
{
	set_default_values(fractol);
	if (argc == 1)
		return ;
	if (argc == 2 && boolcmp(argv[1], "help"))
		help_page();
	get_user_input(argc, argv, fractol);
}
