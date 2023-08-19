/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:59 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/11 12:21:10 by jschwabe         ###   ########.fr       */
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

int32_t     main(int argc, char **argv);
void	init_input(int argc, char **argv, t_program *fractol);

/* sets */

void	mandelbrot(t_program *fractol);
void	julia(t_program *fractol);
void	define_set(char *set, t_program *fractol);

/* utils */

bool	boolcmp(char *argv, char *defined);
char	*str_tolower(char *s);

// int	main(void);

#endif