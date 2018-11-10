/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:26:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/10 00:27:32 by tkobb            ###   ########.fr       */
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

static char	get_file_type(mode_t m)
{
	if (S_ISREG(m))
		return ('-');
	if (S_ISDIR(m))
		return ('d');
	if (S_ISLNK(m))
		return ('l');
	if (S_ISFIFO(m))
		return ('p');
	if (S_ISSOCK(m))
		return ('s');
	if (S_ISCHR(m))
		return ('c');
	if (S_ISBLK(m))
		return ('b');
	return ('-');
}

static void	set_stk(char *stk, mode_t m)
{
	stk[0] = m & S_ISUID ? 'S' : '-';
	stk[1] = m & S_ISGID ? 'S' : '-';
	stk[2] = m & S_ISVTX ? 'T' : '-';
}

char		*perms(mode_t m)
{
	char	*s;
	char	type;
	char	stk[3];

	type = get_file_type(m);
	set_stk(stk, m);
	MCK(ft_asprintf(&s, "%c%c%c%c%c%c%c%c%c%c",
		type,
		m & S_IRUSR ? 'r' : '-',
		m & S_IWUSR ? 'w' : '-',
		m & S_IXUSR ? 'x' : stk[0],
		m & S_IRGRP ? 'r' : '-',
		m & S_IWGRP ? 'w' : '-',
		m & S_IXGRP ? 'x' : stk[1],
		m & S_IROTH ? 'r' : '-',
		m & S_IWOTH ? 'w' : '-',
		m & S_IXOTH ? 'x' : stk[2]), NULL);
	s[10] = '\0';
	return (s);
}

char		*user(uid_t i)
{
	struct passwd *p;

	if ((p = getpwuid(i)) == NULL)
	{
		error(NULL);
		return (NULL);
	}
	return (p->pw_name);
}

char		*group(gid_t i)
{
	struct group *g;

	if ((g = getgrgid(i)) == NULL)
	{
		error(NULL);
		return (NULL);
	}
	return (g->gr_name);
}

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
