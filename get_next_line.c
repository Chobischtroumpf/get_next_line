/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:54:16 by adorigo           #+#    #+#             */
/*   Updated: 2019/10/24 14:25:44 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
void	*ft_calloc(int count, int size);
char	*ft_strjoin(char *s1,char *s2);
char	*ft_strstr(const char *haystack,const char *needle);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memtreat(char *ptr, const void *src, size_t n, char flag);

int				clean_mem(char **buf)
{
	free(*buf);
	*buf = NULL;
	return (ERROR);
}

static int		read_fd(char **buf, int fd, int *pos)
{
	int     ret;
	char    *ptr;
	char    buffer[BUFF_SIZE + 1];

	while (1)
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) == ERROR)
			return (ERROR);
		buffer[ret] = 0;
		if (ret > 0 && (ptr = ft_strjoin(buf[fd], buffer)) != NULL)
		{
			free(buf[fd]);
			buf[fd] = ptr;
		}
		if ((ptr = ft_strstr(buf[fd], "\n")) != NULL)
		{
			*pos = ptr - buf[fd];
			return (SUCCESS);
		} else
			*pos = ft_memtreat(buf[fd], NULL, 0, 0);
		if (ret == 0)
			return (ENDFILE);
	}
}

static char		*make_newline(char *lst_ptr, int ret, int pos)
{
	char	*new_line;
	
	if (ret == ENDFILE)
	{
		if (!(new_line = (char *)ft_calloc(pos + 1, sizeof(char))))
			return (NULL);
		ft_memtreat(new_line, lst_ptr, pos, 1);
		ft_memmove(lst_ptr, lst_ptr + pos, 1);
	}
	else
	{
		if (!(new_line = (char *)ft_calloc(pos + 1, sizeof(char))))
			return (NULL);
		ft_memtreat(new_line, lst_ptr, pos, 1);
		ft_memmove(lst_ptr, lst_ptr + pos + 1, ft_memtreat(lst_ptr + pos, NULL, 0, 0));	
	}
	return (new_line);
}

int				get_next_line(int fd, char **line)
{
	static char		*buffer[FDS_MAX];
	int             pos;
	int             ret;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (ERROR);
	if (buffer[fd] == NULL)
		buffer[fd] = (char *)(ft_calloc(1, sizeof(char)));
	if ((ret = read_fd(buffer, fd, &pos)) < 0)
		return (clean_mem(&(buffer[fd])));
		if (!(*line = make_newline(buffer[fd], ret, pos)))
		return (clean_mem(&(buffer[fd])));
	if (*(*line) != 0 || ret != ENDFILE)
		return (SUCCESS);
	else 
	{
		if (!(*line = (char *)ft_calloc(pos + 1, sizeof(char))))
			return (clean_mem(&(buffer[fd])));
		*(*line) = 0;
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (ENDFILE);
	}
}
