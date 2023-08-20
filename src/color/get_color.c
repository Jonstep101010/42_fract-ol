/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:12:03 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/20 21:40:40 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_color(t_args *args, int iter)
{
	if (args->color == RAINBOW || args->color == default_color)
		return (rainbow(iter, args->max_iter));
	else
		return (0x000000FF);
}
	// else if (args->color == TUVALU)
	// 	return (tuvalu(iter, max_iter));
	// else if (args->color == INDIA)
	// 	return (india(iter, max_iter));
	// else if (args->color == INTERGRAD)
	// 	return (intergrad(iter, max_iter));
