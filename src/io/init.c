/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:04:14 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 16:58:21 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief matches function pointer to set
 */
static void	user_set(char *set, t_program *fractol)
{
	if (fractol->args.set != NO_INIT)
		help_page();
	else if (boolcmp(set, "mandelbrot"))
		fractol->set_function = mandelbrot;
	// else if (boolcmp(set, "julia"))
	// 	fractol->set_function = julia;
	else if (boolcmp(set, "burning_ship"))
		fractol->set_function = mandelbrot;
	else
		return ;
	fractol->args.set = init_set;
}

/**
 * @brief 
 * errors on multiple color inputs
 * @param fractol 
 * @param color 
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
void	init_input(int argc, char **argv, t_program *fractol)
{
	default_vals(fractol);
	if (argc == 1)
		return ;
	if (argc == 2 && boolcmp(argv[1], "help"))
		help_page();
	user_vals(argc, argv, fractol);
}
