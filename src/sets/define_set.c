/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:59:55 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/11 12:20:45 by jschwabe         ###   ########.fr       */
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
		fractol->pargs.set = MANDELBROT;
}
