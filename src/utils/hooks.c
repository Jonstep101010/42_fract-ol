/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:52:22 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/08 12:10:16 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	close_window(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

static void	key_esc(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		close_window(param);
}

void	hooks(t_program *fractol)
{
	mlx_close_hook(fractol->args.mlx, close_window, NULL);
	mlx_key_hook(fractol->args.mlx, key_esc, NULL);
	mlx_loop_hook(fractol->args.mlx, set_keys, fractol);
	mlx_scroll_hook(fractol->args.mlx, zoom_on_scroll, fractol);
}
