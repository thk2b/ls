/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:03:57 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/18 16:48:56 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include "file.h"
#include "libft/libft.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/stat.h>

static char	*get_perms(struct stat *s)
{
	char	*str;

	if ((str = ft_strnew(11)) == NULL)
		return (NULL);
	str[0] = S_ISDIR(s->st_mode) ? 'd' : '-';
	str[0] = S_ISLNK(s->st_mode) ? 'l' : str[0];
	str[1] = s->st_mode & S_IRUSR ? 'r' : '-';
	str[2] = s->st_mode & S_IWUSR ? 'w' : '-';
	str[3] = s->st_mode & S_IXUSR ? 'x' : '-';
	str[4] = s->st_mode & S_IRGRP ? 'r' : '-';
	str[5] = s->st_mode & S_IWGRP ? 'w' : '-';
	str[6] = s->st_mode & S_IXGRP ? 'x' : '-';
	str[7] = s->st_mode & S_IROTH ? 'r' : '-';
	str[8] = s->st_mode & S_IWOTH ? 'w' : '-';
	str[9] = s->st_mode & S_IXOTH ? 'x' : '-';
	str[10] = '\0';
	return (str);
}

static char	*get_uname(struct stat *s)
{
	struct passwd *pw;

	if ((pw = getpwuid(s->st_uid)) == NULL)
		return (NULL);
	return (ft_strdup(pw->pw_name));
}

static char	*get_gname(struct stat *s)
{
	struct group *grp;

	if ((grp = getgrgid(s->st_gid)) == NULL)
		return (NULL);
	return (ft_strdup(grp->gr_name));
}

static char	*get_time(struct stat *s)
{
	char	*str;

	if ((str = ctime(&s->st_mtime)) == NULL)
		return (NULL);
	return (ft_strdup(ft_strsub(str, 4, ft_strlen(str) - 5)));
}

const char	*render(struct s_file *file, struct stat *s)
{
	char	*sections[8];
	char	*str;
	int		i;

	sections[7] = NULL;
	if ((sections[0] = get_perms(s)) == NULL)
		error(file->name);
	sections[1] = ft_itoa(s->st_nlink);
	if ((sections[2] = get_uname(s)) == NULL)
		error(file->name);
	if ((sections[3] = get_gname(s)) == NULL)
		error(file->name);
	sections[4] = ft_itoa(s->st_size);
	if ((sections[5] = get_time(s)) == NULL)
		error(file->name);
	if ((sections[6] = ft_strdup((char*)file->name)) == NULL)
		error(file->name);
	str = ft_strvjoin((const char**)sections, "  ");
	i = 0;
	while (i < 8)
		free(sections[i++]);
	return (str);
}
