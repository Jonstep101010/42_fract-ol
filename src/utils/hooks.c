/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:52:22 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/07 19:49:20 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	close_window(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

static int	key_esc(int keycode, void *param)
{
	if (keycode == MLX_KEY_ESCAPE)
		close_window(param);
	return (0);
}

void	hooks(t_program *fractol)
{
	mlx_close_hook(fractol->args.mlx, (void *)close_window, NULL);
	mlx_key_hook(fractol->args.mlx, (void *)key_esc, NULL);
	mlx_loop_hook(fractol->args.mlx, (void *)set_keys, fractol);
	mlx_scroll_hook(fractol->args.mlx, (void *)zoom_on_scroll, fractol);
}
