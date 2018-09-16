/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 21:00:30 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/14 22:10:09 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*alloc_word(const char *start, const char *end)
{
	size_t	len;
	char	*w;

	len = end - start + 1;
	w = (char*)malloc(len * sizeof (char));
	if (w == NULL)
		return (NULL);
	ft_strncpy(w, start, len - 1);
	w[len] = '\0';
	return (w);
}

char	**ft_strsplit(const char *s, char c)
{
	const char	*t;
	size_t		wc;
	char		**words;
	const char	*start;

	t = s;
	wc = 1;
	while (*s)
		if (*s++ == c && *s && *s != c)
			wc++;
	s = t;
	words = (char**)malloc((wc + 1) * sizeof(char));
	if (words == NULL)
		return (NULL);
	start = s;
	while(*s)
	{
		if (*s == c)
		{
			if (start != s)
				if((*words++ = alloc_word(start, s)) == NULL)
					return (NULL);
			while (*s && *s == c)
				s++;
			start = s;
		}
		else
			s++;
	}
	if (start != s)
		if((*words++ = alloc_word(start, s)) == NULL)
			return (NULL);
	*words = NULL;
	return (words - wc);
}
