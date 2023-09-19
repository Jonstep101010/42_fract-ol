/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:16:07 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/19 12:31:43 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief matches function pointer to set
 */
static void	user_set(char *set, t_program *fractol)
{
	if (fractol->set_function != mandelbrot || fractol->args.set != NO_INIT)
		help_page();
	else if (boolcmp(set, "mandelbrot"))
		fractol->set_function = mandelbrot;
	else if (boolcmp(set, "julia"))
		fractol->set_function = julia;
	else if (boolcmp(set, "burning_ship"))
		fractol->set_function = burning_ship;
	fractol->args.set = init_set;
}

/**
 * @brief matches function pointer to color scheme
 * @details errors on multiple color inputs
 * @param color scheme name
 */
static void	user_color(t_args *args, char *color)
{
	if (args->color_function != ultra)
		help_page();
	else if (boolcmp(color, "rainbow"))
		args->color_function = rainbow;
	else if (boolcmp(color, "ultra"))
		args->color_function = ultra;
	else if (boolcmp(color, "shift"))
		args->color_function = shift;
}

static void	validate_julia_input(t_program *fractol, char *input)
{
	if (boolcmp(input, "j_real_num:") && input + 11)
		fractol->args.j_real_num = atof(input + 11);
	else if (boolcmp(input, "j_imag_num:") && input + 11)
		fractol->args.j_imag_num = atof(input + 11);
	else
		help_page();
	if (fractol->args.j_imag_num <= 0 || fractol->args.j_real_num <= 0)
		help_page();
}

void	get_user_input(int argc, char **argv, t_program *fractol)
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
		else if ((boolcmp(argv[i], "j_real_num:")
				|| boolcmp(argv[i], "j_imag_num:"))
			&& fractol->set_function == julia)
			validate_julia_input(fractol, argv[i]);
		else if (boolcmp(argv[i], "rainbow")
			|| boolcmp(argv[i], "ultra")
			|| boolcmp(argv[i], "shift"))
			user_color(&(fractol->args), argv[i]);
		else
			help_page();
		i++;
	}
}
