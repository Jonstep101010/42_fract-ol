/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:34:01 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/06 11:46:50 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reset_set(t_program *fractol)
{
	t_args	*args;

	args = &(fractol->args);
	args->zoom = DEFAULT_ZOOM;
	args->xmin = XY_MIN;
	args->xmax = XY_MAX;
	args->ymin = XY_MIN;
	args->ymax = XY_MAX;
	args->xmove = 0;
	args->ymove = 0;
	fractol->set_function(args);
}

void	set_keys(void *param)
{
	t_program	*fractol;
	t_args		*args;

	fractol = (t_program *) param;
	args = &(fractol->args);
	if (fractol->move_keys)
		fractol->move_keys(args, fractol->set_function);
	if (mlx_is_key_down(args->mlx, MLX_KEY_Z))
	{
		args->scroll_zoom = !args->scroll_zoom;
	}
	if (mlx_is_key_down(args->mlx, MLX_KEY_X))
	{
		if (fractol->move_keys)
			fractol->move_keys = NULL;
		else
			fractol->move_keys = move_keys;
	}
	if (mlx_is_key_down(args->mlx, MLX_KEY_R))
		reset_set(fractol);
}
