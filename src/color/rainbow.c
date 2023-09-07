/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:08:08 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/07 19:42:57 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	rainbow(int iterations, int max_iterations, long double zoom)
{
	(void)zoom;
	max_iterations = (double)max_iterations;
	if (iterations == max_iterations)
		return (rgb_to_hex(255, 0, 24));
	else if (iterations <= (double)max_iterations * 0.02)
		return (rgb_to_hex(134, 0, 125));
	else if (iterations <= (double)max_iterations * 0.05)
		return (rgb_to_hex(0, 0, 249));
	else if (iterations <= (double)max_iterations * 0.15)
		return (rgb_to_hex(0, 128, 24));
	else if (iterations <= (double)max_iterations * 0.4)
		return (rgb_to_hex(255, 255, 65));
	else if (iterations <= (double)max_iterations * 0.8)
		return (rgb_to_hex(255, 165, 44));
	else
		return (rgb_to_hex(255, 0, 24));
}
