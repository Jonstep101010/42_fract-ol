/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:37:20 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/18 11:36:34 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void	move_on_scroll(t_args *args, int x, int y)
{
	args->xmove += (((args->xmax - args->xmin) / WIDTH) * (x - (WIDTH / 2)));
	args->ymove += (((args->ymax - args->ymin) / HEIGHT) * (y - (HEIGHT / 2)));
	args->xmin += args->xmove;
	args->xmax += args->xmove;
	args->ymin += args->ymove;
	args->ymax += args->ymove;
}

void	zoom_on_scroll(double xdelta, double ydelta, void *param)
{
	int32_t		x;
	int32_t		y;
	t_args		*args;

	args = &((t_program *)param)->args;
	if (ydelta > 0)
	{
		args->zoom += 0.05;
		args->zoom_in++;
	}
	else if (ydelta < 0)
	{
		args->zoom -= 0.05;
		args->zoom_out++;
	}
	args->xmin = -2.0 / (pow(1.05, args->zoom_in) * pow(0.95, args->zoom_out));
	args->xmax = 2.0 / (pow(1.05, args->zoom_in) * pow(0.95, args->zoom_out));
	args->ymin = -2.0 / (pow(1.05, args->zoom_in) * pow(0.95, args->zoom_out));
	args->ymax = 2.0 / (pow(1.05, args->zoom_in) * pow(0.95, args->zoom_out));
	mlx_get_mouse_pos(args->mlx, &x, &y);
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
		move_on_scroll(args, x, y);
	if (args->zoom < 1)
		args->zoom = 1;
	((t_program *)param)->set_function(args), (void)xdelta;
}
