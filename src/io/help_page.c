/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:34:00 by jschwabe          #+#    #+#             */
/*   Updated: 2023/09/19 10:31:44 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fcntl.h"
#include "ft_printf.h"

/**
 * @brief print out help page for user (undefined/incorrect)
 *
 */
void	help_page(void)
{
	int		fd;
	char	*line;

	fd = open("./src/io/help.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}
