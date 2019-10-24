/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:19:13 by adorigo           #+#    #+#             */
/*   Updated: 2019/10/24 14:26:39 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_memtreat(char *ptr, const void *src, size_t n, char flag)
{
	void	*p;
	int		len;

	p  = ptr;
	len = 0;
	if (flag)
	{
		while (n--)
			*((char *)p++) = *((char *)src++);
		*((char *)p) = 0;
		
	}
	else
	{
		while (*ptr++)
			len++;
	}
	return (len);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*p;

	p = dst;
	if (p > src)
	{
		while (len--)
			*((unsigned char *)p + (len)) = *((unsigned char *)src + (len)); 
	}
	else
	{
		while (len--)
			*((unsigned char *)p++) = *((unsigned char *)src++); 
	}
	return (dst);
}

void	*ft_calloc(int count, int size)
{
	void			*ptr;
	void			*ptr_b;
	unsigned int	len;

	len = count * size;
	if (!(ptr = malloc(len)))
		return (NULL);
	ptr_b = ptr;
	while (len--)
		*((char *)ptr_b++) = 0;
	return (ptr);
}

char	*ft_strstr(const char *haystack,const char *needle)
{
	const char *p1;
	const char *p2;

	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		p1 = haystack;
		p2 = needle;
		while (*p1 == *p2)
		{
			p1++;
			p2++;
			if (*p2 == 0)
				return ((char *)haystack);
		}
		if (*p2 == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1,char *s2)
{
	char 	*ptr;
	char	*ptr_cp;

	if (!s1 || !s2 || \
	!(ptr = (char *)malloc(ft_memtreat(s1, NULL, 0, 0) + \
	ft_memtreat(s2, NULL, 0, 0) + 1)))
		return (NULL);
	ptr_cp = ptr;
	while (*s1)
		*ptr_cp++ = *s1++;
	while (*s2)
		*ptr_cp++ = *s2++;
	*ptr_cp = 0;
	return (ptr);
}
