/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:25:05 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/14 18:53:29 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *t)
{
	size_t	tlen;

	tlen = ft_strlen(t);
	if (*s == '\0')
		return (*s == *t ? (char*)s : NULL);
	if (*t == '\0')
		return ((char*)s);
	while (*s)
	{
		if (ft_strncmp(s, t, tlen) == 0)
			return ((char*)s);
		else
			s++;
	}
	return (NULL);
}
