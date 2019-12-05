/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:05:51 by alessandro        #+#    #+#             */
/*   Updated: 2019/12/05 11:18:36 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnjoin(char *s1, char *s2, ssize_t r_size);
size_t	ft_strlen(const char *src);
int		get_next_line(int fd, char **line)

#endif
