/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:59 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/03 21:05:05 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "structs.h"
# include "libft.h"
# include <math.h>
# include "MLX42.h"

# ifndef WIDTH
#  define WIDTH 1024
# endif
# ifndef HEIGHT
#  define HEIGHT 1024
# endif

/* input/output */

void	init_input(int argc, char **argv, t_program *fractol);

/* sets */

void	mandelbrot(t_program *fractol);
void	julia(t_program *fractol);
void	define_set(t_program *fractol);

/* utils */

char	*str_tolower(char *s);

// int	main(void);

#endif