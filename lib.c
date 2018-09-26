/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 18:01:30 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/25 18:05:51 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "file.h"

int		ft_strcmp(const char *s, const char *t)
{
	while (*s && *s == *t)
	{
		s++;
		t++;
	}
	return ((unsigned char)*s - (unsigned char)*t);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*d;
	char	*c;

	len = ft_strlen(s);
	if ((d = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	c = d;
	while (*s)
		*d++ = *s++;
	*d = '\0';
	return (c);
}

char	*ft_strcjoin(const char *s, char sep, const char *t)
{
	size_t	slen;
	size_t	tlen;
	size_t	len;
	char	*d;
	char	*c;

	slen = ft_strlen(s);
	tlen = ft_strlen(t);
	len = slen + tlen;
	if ((d = (char*)malloc((len + 2) * sizeof(char))) == NULL)
		return (NULL);
	c = d;
	while (*s)
		*d++ = *s++;
	*d++ = sep;
	while (*t)
		*d++ = *t++;
	*d = '\0';
	return (c);
}
