/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:07:09 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/09 23:25:56 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <ft_printf.h>
#include <errno.h>
#include <string.h>

int		error(char *filename)
{
	if (filename)
		ft_printf("%s: %s: %s\n", "ft_ls", filename, strerror(errno));
	else
		ft_printf("%s: %s\n", "ft_ls", strerror(errno));
	return (errno);
}
