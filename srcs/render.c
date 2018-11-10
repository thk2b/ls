/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:53:06 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/09 22:00:38 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>
#include <render.h>
#include <error.h>
#include <render_utils.h>
#include <libft.h>
#include <ft_printf.h>
#include <sys/stat.h>

char		*pre_render_file_long(t_file *file, struct stat *statbuf)
{
	char	*s;
	char	*link;
	char	*p;

	link = get_link(file, statbuf);
	p = perms(statbuf->st_mode);
	s = NULL;
	MCK(ft_asprintf(&s, "%s  %d %s  %s %lld %s %s%s",
		p, statbuf->st_nlink,
		user(statbuf->st_uid), group(statbuf->st_gid),
		statbuf->st_size, get_time(&file->time),
		file->name, link), NULL);
	free(p);
	free(link);
	return (s);
}
