/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:58:27 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/16 14:22:45 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

int		error(const char *filename)
{
	if (filename == NULL)
		printf("%s\n", strerror(errno));
	else
		printf("%s: %s\n", filename, strerror(errno));
	return (1);
}
