/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 20:51:52 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/14 22:24:43 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(const char *s)
{
	const char *start;
	size_t len;
	char *t;

	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	start = s;
	s += ft_strlen(s);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s--;
	len = s - start - 1;
	t = ((char*)malloc((len) * sizeof(char)));
	if (t == NULL)
		return (NULL);
	t[len] = '\0';
	return (ft_strncpy(t, start, len - 1));	
}
int main()
{
	printf("%s\n", ft_strtrim("  abc  1234567891011 \t"));
}
