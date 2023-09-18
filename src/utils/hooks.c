/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:52:22 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/18 11:38:30 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	close_window(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

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

static void	key_press(mlx_key_data_t keydata, void *param)
{
	t_program	*fractol;

	fractol = (t_program *) param;
	if (keydata.key == MLX_KEY_M || keydata.key == MLX_KEY_X)
	{
		if (keydata.key == MLX_KEY_M)
			fractol->move_keys = NULL;
		else if (keydata.key == MLX_KEY_X)
			fractol->move_keys = move_keys;
	}
	if (keydata.key == MLX_KEY_ESCAPE)
		close_window(param);
	if (keydata.key ==  MLX_KEY_HOME || keydata.key == MLX_KEY_R)
		reset_set(fractol);
}

static void	move_keys_set(void *param)
{
	t_program	*fractol;

	fractol = ((t_program *)param);
	if (fractol->move_keys)
		fractol->move_keys(&(fractol->args), fractol->set_function);
}

void	hooks(t_program *fractol)
{
	mlx_close_hook(fractol->args.mlx, close_window, NULL);
	mlx_key_hook(fractol->args.mlx, key_press, fractol);
	mlx_loop_hook(fractol->args.mlx, move_keys_set, fractol);
	mlx_scroll_hook(fractol->args.mlx, zoom_on_scroll, fractol);
}
