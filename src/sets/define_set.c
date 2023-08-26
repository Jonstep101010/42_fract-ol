/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:46:07 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/26 11:46:17 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief call for Mandelbrot/Julia set
 * 
 */
void	define_set(char *set, t_program *fractol)
{
	if (fractol->args.set != NO_INIT)
		return ;
	else if (boolcmp(set, "mandelbrot"))
		fractol->set_function = mandelbrot;
	// else if (boolcmp(set, "julia"))
	// 	fractol->set_function = julia;
	else if (boolcmp(set, "burning_ship"))
		fractol->set_function = mandelbrot;
	else
		fractol->set_function = mandelbrot;
	fractol->args.set = init_set;
}
