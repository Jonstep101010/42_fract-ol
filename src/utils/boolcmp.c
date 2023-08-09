/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolcmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:45:17 by jschwabe          #+#    #+#             */
/*   Updated: 2023/08/09 19:48:47 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	boolcmp(char *argv, char *defined)
{
	if (ft_strncmp(str_tolower(argv), defined, ft_strlen(defined)) == 0)
		return (true);
	return (false);
}
