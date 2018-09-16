/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:44:54 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/13 21:07:25 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char *s;
	char *d;

	s = (char*)malloc(len + 1 * sizeof(char));
	d = s;
	if (s == NULL)
		return (NULL);
	while (len--)
		*s++ = '\0';
	*s = '\0';
	return (d);
}
