/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:53:06 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/10 00:24:21 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>
#include <render.h>
#include <error.h>
#include <render_utils.h>
#include <libft.h>
#include <ft_printf.h>
#include <sys/stat.h>

static int	pre_render_file(char **s, t_file *file,
	struct stat *statbuf, char *perms)
{
	char	*link;

	link = get_link(file, statbuf);
	MCK(ft_asprintf(s, "%s  %d %s  %s %lld %s %s%s",
		perms, statbuf->st_nlink,
		user(statbuf->st_uid), group(statbuf->st_gid),
		statbuf->st_size,
		get_time(&file->time),
		file->name, link), 1);
	free(link);
	return (0);
}

static int	pre_render_device(char **s, t_file *file, struct
	stat *statbuf, char *perms)
{
	char	*link;
	char	*mj;

	mj = maj_min(statbuf->st_rdev);
	link = get_link(file, statbuf);
	MCK(ft_asprintf(s, "%s  %d %s  %s %s %s %s%s",
		perms, statbuf->st_nlink,
		user(statbuf->st_uid), group(statbuf->st_gid),
		mj,
		get_time(&file->time),
		file->name, link), 1);
	free(mj);
	free(link);
	return (0);
}

char		*pre_render_file_long(t_file *file, struct stat *statbuf)
{
	char	*s;
	char	*p;
	mode_t	m;

	m = statbuf->st_mode;
	p = perms(m);
	s = NULL;
	if (S_ISBLK(m) || S_ISCHR(m))
		pre_render_device(&s, file, statbuf, p);
	else
		pre_render_file(&s, file, statbuf, p);
	free(p);
	return (s);
}
