/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_set->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:59:55 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/25 15:26:19 by jschwabe         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**@note needs to contain parameters for calls (in t_program)
 * @brief call for Mandelbrot/Julia set
 * 
 */
void	define_set(char *set, t_program *fractol)
{
	if (boolcmp(set, "mandelbrot"))
		fractol->pargs.set = MANDELBROT;
	else if (boolcmp(set, "julia"))
		fractol->pargs.set = JULIA;
	else if (boolcmp(set, "burning_ship"))
		fractol->pargs.set = BURNING_SHIP;
	else if (fractol->pargs.set == NO_INIT)
		fractol->pargs.set = MANDELBROT;
	// if (boolcmp(set, "mandelbrot"))
	// 	fractol->set_function = mandelbrot;
	// else if (boolcmp(set, "julia"))
	// 	fractol->set_function = julia;
	// else if (boolcmp(set, "burning_ship"))
	// 	fractol->set_function = mandelbrot;
	// else if (fractol->pargs.set == NO_INIT)
	// 	fractol->set_function = mandelbrot;

}
