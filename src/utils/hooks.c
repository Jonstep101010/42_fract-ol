/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:52:22 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/30 21:59:36 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	hooks(t_args *args)
{
	mlx_close_hook(args->mlx, (void *)close_window, NULL);
	mlx_key_hook(args->mlx, (void *)key_esc, NULL);
}
