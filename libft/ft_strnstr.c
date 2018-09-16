/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:25:05 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/14 18:25:04 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *t, size_t len)
{
	size_t	tlen;

	if (*t == '\0')
		return ((char*)s);
	if (*s == '\0')
		return (*t == '\0' ? (char*)s : (NULL));
	tlen = ft_strlen(t);
	if (tlen == len)
		return (ft_strncmp(s, t, len) == 0 ? (char*)s : NULL);
	while (*s && (tlen - len--) > 0)
		if (ft_strncmp(s, t, tlen) == 0)
			return ((char*)s);
		else
			s++;
	return (NULL);
}
