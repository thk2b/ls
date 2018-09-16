/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 23:34:17 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/13 23:34:22 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *s;
	char *d;

	s = (char*)malloc(size * sizeof(char));
	d = s;
	if (s == NULL)
		return (NULL);
	while (size--)
		*s++ = 0;
	return ((void*)(d));
}
