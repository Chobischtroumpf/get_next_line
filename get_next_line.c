/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:54:16 by adorigo           #+#    #+#             */
/*   Updated: 2019/10/23 10:43:49 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	ssize_t		r_size;
	ssize_t	p_nl;
	char		buff[BUFFER_SIZE + 1];
	static char	*tmp;

	if (fd < 0 || !line)
		return (-1);
	while ((r_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r_size] = '\0';
		
	}
}
