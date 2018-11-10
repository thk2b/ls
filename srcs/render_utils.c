/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:26:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/09 20:50:39 by tkobb            ###   ########.fr       */
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
	char s[11];
	char type;

	type = '-';
	if (S_ISDIR(m))
		type = 'd';
	else if (S_ISLNK(m))
		type = 'l';
	ft_snprintf(s, 11, "%c%c%c%c%c%c%c%c%c%c",
		type,
		m & S_IRUSR ? 'r' : '-',
		m & S_IWUSR ? 'w' : '-',
		m & S_IXUSR ? 'x' : '-',
		m & S_IRGRP ? 'r' : '-',
		m & S_IWGRP ? 'w' : '-',
		m & S_IXGRP ? 'x' : '-',
		m & S_IROTH ? 'r' : '-',
		m & S_IWOTH ? 'w' : '-',
		m & S_IXOTH ? 'x' : '-');
	s[10] = 0;
	return (ft_strdup(s));
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
	size_t	len;

	s = NULL;
	if (!S_ISLNK(st->st_mode))
		return (ft_strdup(""));
	if (readlink(file->path, (char*)&name, PATH_MAX) == -1)
	{
		error(file->path);
		return (NULL);
	}
	len = ft_snprintf(s, 0, " -> %s", name);
	if ((s = (char*)malloc((len + 1 * sizeof(char)))) == NULL)
		return (NULL);
	ft_snprintf(s, len + 1, " -> %s", name);
	return (s);
}
