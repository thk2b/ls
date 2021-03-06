/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:26:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/10 22:40:52 by tkobb            ###   ########.fr       */
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
	char	upcase;

	upcase = m & S_IXUSR ? 0 : 'A' - 'a';
	stk[0] = m & S_ISUID ? upcase + 's' : '-';
	stk[1] = m & S_ISGID ? upcase + 's' : '-';
	stk[2] = m & S_ISVTX ? upcase + 't' : '-';
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
