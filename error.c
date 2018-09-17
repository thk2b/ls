/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:58:27 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/16 23:04:26 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include "libft/libft.h"
#include <string.h>

int		error(const char *filename)
{
	if (filename == NULL)
		ft_putendl(strerror(errno));
	else
	{
		ft_putstr(filename);
		ft_putstr(": ");
		ft_putendl(strerror(errno));
	}
	return (1);
}
