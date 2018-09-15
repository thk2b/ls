/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:33:31 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 09:54:25 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

void	b_ls(const char *filename)
{
	DIR	*dir;
	struct dirent	*ent;

	dir = opendir(filename);
	while ((ent = readdir(dir)))
	{
		printf("%s\n", ent->d_name);
	}
}
