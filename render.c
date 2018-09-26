/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:53:06 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/25 18:35:35 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "file.h"
#include "render.h"
#include "error.h"
#include "render_utils.h"
#include <printf.h>
#include <sys/stat.h>

char		*pre_render_file_long(t_file *file, struct stat *statbuf)
{
	char	*s;
	int		len;
	char	*link;
	char	*p;

	link = get_link(file, statbuf);
	p = perms(statbuf->st_mode);
	s = NULL;
	len = snprintf(s, 0, "%s  %d %s  %s %lld %s %s%s",
		p, statbuf->st_nlink,
		user(statbuf->st_uid), group(statbuf->st_gid),
		statbuf->st_size, get_time(&file->time),
		file->name, link);
	if ((s = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	snprintf(s, len + 1, "%s  %d %s  %s %lld %s %s%s",
		p, statbuf->st_nlink,
		user(statbuf->st_uid), group(statbuf->st_gid),
		statbuf->st_size, get_time(&file->time),
		file->name, link);
	free(p);
	free(link);
	return (s);
}
