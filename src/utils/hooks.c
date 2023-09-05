/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:52:22 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/05 20:40:27 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_on_scroll(t_args *params, int x, int y)
{
	long double	xrange;
	long double	yrange;

	xrange = (params->xmax - params->xmin) / WIDTH;
	yrange = (params->ymax - params->ymin) / HEIGHT;
	params->xmove += (xrange * (x - (WIDTH / 2)));
	params->ymove += (yrange * (y - (HEIGHT / 2)));
	params->xmin += params->xmove;
	params->xmax += params->xmove;
	params->ymin += params->ymove;
	params->ymax += params->ymove;
}

static void	detect_scroll(double xdelta, double ydelta, void *param)
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
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT && args->scroll_zoom)
		zoom_on_scroll(args, x, y);
	if (args->zoom < 1)
		args->zoom = 1;
	((t_program *)param)->set_function(args);
}

static int	close_window(void *param)
{
	t_args	*args;

	args = (t_args *)param;
	exit(EXIT_SUCCESS);
}

static int	key_esc(int keycode, void *param)
{
	t_args	*args;

	args = (t_args *)param;
	if (keycode == MLX_KEY_ESCAPE)
		close_window(param);
	return (0);
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
	{
		args->zoom = 1;
		args->xmin = -2;
		args->xmax = 2;
		args->ymin = -2;
		args->ymax = 2;
		args->xmove = 0;
		args->ymove = 0;
		fractol->set_function(args);
	}
}

void	hooks(t_program *fractol)
{
	// t_args	*args;

	// args = &(fractol->args);
	mlx_close_hook(fractol->args.mlx, (void *)close_window, NULL);
	mlx_key_hook(fractol->args.mlx, (void *)key_esc, NULL);
	mlx_loop_hook(fractol->args.mlx, set_keys, fractol);
	mlx_scroll_hook(fractol->args.mlx, detect_scroll, fractol);
}
