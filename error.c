/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:07:09 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/23 14:07:25 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <printf.h>
#include <errno.h>
#include <string.h>

int		error(char *filename)
{
	if (filename)
		printf("%s: %s: %s\n", "b_ls", filename, strerror(errno));
	else
		printf("%s: %s\n", "b_ls", strerror(errno));
	return (errno);
}
