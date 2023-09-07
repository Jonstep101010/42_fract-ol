/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:20:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/07 17:35:11 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	x_movement(t_args *args, void (*set_function)(t_args *args))
{
	if (mlx_is_key_down(args->mlx, MLX_KEY_A)
		|| mlx_is_key_down(args->mlx, MLX_KEY_LEFT))
	{
		args->xmin -= (0.1 / (2 * args->zoom));
		args->xmax -= (0.1 / (2 * args->zoom));
		set_function(args);
	}
	if (mlx_is_key_down(args->mlx, MLX_KEY_D)
		|| mlx_is_key_down(args->mlx, MLX_KEY_RIGHT))
	{
		args->xmin += (0.1 / (2 * args->zoom));
		args->xmax += (0.1 / (2 * args->zoom));
		set_function(args);
	}
}

static void	y_movement(t_args *args, void (*set_function)(t_args *args))
{
	if (mlx_is_key_down(args->mlx, MLX_KEY_W)
		|| mlx_is_key_down(args->mlx, MLX_KEY_UP))
	{
		args->ymin -= (0.1 / (2 * args->zoom));
		args->ymax -= (0.1 / (2 * args->zoom));
		set_function(args);
	}
	if (mlx_is_key_down(args->mlx, MLX_KEY_S)
		|| mlx_is_key_down(args->mlx, MLX_KEY_DOWN))
	{
		args->ymin += (0.1 / (2 * args->zoom));
		args->ymax += (0.1 / (2 * args->zoom));
		set_function(args);
	}
}

void	move_keys(t_args *args, void (*set_function))
{
	x_movement(args, set_function);
	y_movement(args, set_function);
}
