/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:55:21 by adorigo           #+#    #+#             */
/*   Updated: 2019/12/05 11:47:37 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strndup(const char *s1, size_t size);


char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *scpy;

	if (ft_strlen(s) < start)
	{
		if (!(scpy = malloc(sizeof(char))))
			return (NULL);
		*scpy = '\0';
		return (scpy);
	}
	else if (s)
	{
		return (ft_strndup(&s[start], len));
	}
	else
		return (NULL);
}

static char	*ft_strndup(const char *s1, size_t size)
{
	char	*new_str;
	char	*new_cpy;

	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new_cpy = new_str;
	while (*s1 && size)
	{
		*new_cpy++ = *s1++;
		size--;
	}
	*new_cpy = '\0';
	return (new_str);
}
