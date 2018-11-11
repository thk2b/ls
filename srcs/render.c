/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:53:06 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/10 21:55:36 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>
#include <render.h>
#include <error.h>
#include <render_utils.h>
#include <libft.h>
#include <ft_printf.h>
#include <sys/stat.h>

static int	pre_render_file(t_opts *opts, char **s, t_file *file,
	struct stat *statbuf)
{
	char	*link;
	char	*p;
	
	p = perms(statbuf->st_mode);
	link = get_link(file, statbuf);
	MCK(ft_asprintf(s, "%s  %d %s  %s %lld %.*s %s%s",
		p, statbuf->st_nlink,
		user(statbuf->st_uid), group(statbuf->st_gid),
		statbuf->st_size,
		opts->full_time ? 15 : 12, get_time(&file->time.tv_sec),
		file->name, link), 1);
	free(p);
	free(link);
	return (0);
}

static int	pre_render_device(t_opts *opts, char **s, t_file *file,
	struct stat *statbuf)
{
	char	*link;
	char	*mj;
	char	*p;
	
	p = perms(statbuf->st_mode);
	mj = maj_min(statbuf->st_rdev);
	link = get_link(file, statbuf);
	MCK(ft_asprintf(s, "%s  %d %s  %s %s %.*s %s%s",
		p, statbuf->st_nlink,
		user(statbuf->st_uid), group(statbuf->st_gid),
		mj,
		opts->full_time ? 15 : 12, get_time(&file->time.tv_sec),
		file->name, link), 1);
	free(p);
	free(mj);
	free(link);
	return (0);
}

char		*pre_render_file_long(t_opts *opts, t_file *file, struct stat *statbuf)
{
	char	*s;
	mode_t	m;

	m = statbuf->st_mode;
	if (S_ISBLK(m) || S_ISCHR(m))
		pre_render_device(opts, &s, file, statbuf);
	else
		pre_render_file(opts, &s, file, statbuf);
	return (s);
}
