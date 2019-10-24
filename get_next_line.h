/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:51:48 by adorigo           #+#    #+#             */
/*   Updated: 2019/10/24 14:15:40 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# define FDS_MAX 125
# define ERROR -1
# define ENDFILE 0
# define SUCCESS 1
# define BUFF_SIZE 32

int		get_next_line(int fd, char **line);
void	*ft_calloc(int count, int size);
char	*ft_strjoin(char *s1,char *s2);
char	*ft_strstr(const char *haystack,const char *needle);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memtreat(char *ptr, const void *src, size_t n, char flag);

#endif
