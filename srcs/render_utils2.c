/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 00:53:13 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/10 00:53:41 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <render_utils.h>
#include <ft_printf.h>
#include <error.h>
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <limits.h>
#include <grp.h>
#include <sys/types.h>

char		*get_time(time_t *t)
{
	char *s;

	s = ctime(t);
	s[ft_strlen(s) - 1] = '\0';
	return (s);
}

char		*get_link(t_file *file, struct stat *st)
{
	char	*s;
	char	name[PATH_MAX];

	ft_bzero(name, PATH_MAX);
	s = NULL;
	if (!S_ISLNK(st->st_mode))
		return (ft_strdup(""));
	if (readlink(file->path, (char*)&name, PATH_MAX) == -1)
	{
		error(file->path);
		return (NULL);
	}
	MCK(ft_asprintf(&s, " -> %s", name), NULL);
	return (s);
}

char		*maj_min(dev_t dev)
{
	char	*s;

	s = NULL;
	ft_asprintf(&s, "%3d, %3d", major(dev), minor(dev));
	return (s);
}
