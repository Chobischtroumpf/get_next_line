/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:59:46 by adorigo           #+#    #+#             */
/*   Updated: 2019/12/05 11:10:44 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin(char *s1, char *s2, ssize_t r_size)
{
	int		len;
	char	*res;
	ssize_t	i;

	len = ft_strlen(s1) + r_size;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && *s2 != '\0')
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}
