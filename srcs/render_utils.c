/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:26:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/09 21:59:05 by tkobb            ###   ########.fr       */
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

char	*perms(mode_t m)
{
	char *s;
	char type;

	type = '-';
	if (S_ISDIR(m))
		type = 'd';
	else if (S_ISLNK(m))
		type = 'l';
	MCK(ft_asprintf(&s, "%c%c%c%c%c%c%c%c%c%c",
		type,
		m & S_IRUSR ? 'r' : '-',
		m & S_IWUSR ? 'w' : '-',
		m & S_IXUSR ? 'x' : '-',
		m & S_IRGRP ? 'r' : '-',
		m & S_IWGRP ? 'w' : '-',
		m & S_IXGRP ? 'x' : '-',
		m & S_IROTH ? 'r' : '-',
		m & S_IWOTH ? 'w' : '-',
		m & S_IXOTH ? 'x' : '-'), NULL);
	s[10] = '\0';
	return (s);
}

char	*user(uid_t i)
{
	struct passwd *p;

	if ((p = getpwuid(i)) == NULL)
	{
		error(NULL);
		return (NULL);
	}
	return (p->pw_name);
}

char	*group(gid_t i)
{
	struct group *g;

	if ((g = getgrgid(i)) == NULL)
	{
		error(NULL);
		return (NULL);
	}
	return (g->gr_name);
}

char	*get_time(time_t *t)
{
	char *s;

	s = ctime(t);
	s[ft_strlen(s) - 1] = '\0';
	return (s);
}

char	*get_link(t_file *file, struct stat *st)
{
	char	*s;
	char	name[PATH_MAX];

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
