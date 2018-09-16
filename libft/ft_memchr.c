/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 21:07:37 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/13 23:34:45 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *us;

	us = (unsigned char *)s;
	while (n--)
		if (*us == (unsigned char)c)
			return ((void*)us);
		else
			us++;
	return (NULL);
}
