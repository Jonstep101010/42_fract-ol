/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:23:38 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/07 20:44:45 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	interpolate_color(t_color_five *rgb, double position)
{
	t_rgb	start;
	t_rgb	end;
	double	factor;
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (position < rgb->thresholds[i])
		{
			start = rgb->colors[i];
			end = rgb->colors[i + 1];
			factor = (position - rgb->prev_threshold[i])
				/ (rgb->thresholds[i] - rgb->prev_threshold[i]);
			return (rgb_to_hex(start.r + (end.r - start.r) * factor,
					start.g + (end.g - start.g) * factor,
					start.b + (end.b - start.b) * factor));
		}
	}
	return (rgb_to_hex(rgb->colors[4].r, rgb->colors[4].g, rgb->colors[4].b));
}
