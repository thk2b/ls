/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:03:57 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/16 10:38:52 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

static char	*get_perms(struct stat *s)
{
	char	*str;

	if ((str = (char*)malloc(11 * sizeof(char))) == NULL)
		return (NULL);
	str[0] = S_ISDIR(s->st_mode) ? 'd' : '-';
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

static char *get_uname(struct stat *s)
{
	struct passwd *pw;

	if ((pw = getpwuid(s->st_uid)) == NULL)
		return (NULL);
	return (strdup(pw->pw_name));
}

static char *get_gname(struct stat *s)
{
	struct group *grp;

	if ((grp = getgrgid(s->st_gid)))
		return (NULL);
	return (strdup(grp->gr_name));
}

static char *get_time(struct stat *s)
{
	return (strdup("time"));
}

const char strv_join(const char	**strv)
{
	size_t	len;
	size_t	vi;
	char	*str;

	len = 0;
	vi = 0;
	while (strv[vi])
		len += strlen(strv[vi++]) + 1;
	vi = 0;
	if ((str = (char*)malloc(len + 1 * sizeof(char))) == NULL)
		return (NULL);
	while (strv[vi])
	{
		strcat(str, strv[vi]);
		strcat(str, " ");
		free(strv[vi++]);
	}
	str[len] = '\0';
	return (str);
}

const char *render(struct s_file *file, struct stat *s)
{
	char *sections[8];
	
	sections[8] = NULL;
	sections[0] = get_perms(s);
	sections[1] = atoi(s->st_nlink);
	sections[2] = get_uname(s);
	sections[3] = get_gname(s);
	sections[4] = s->st_size;
	sections[5] = get_time(s);
	sections[6] = file->name;
	return (strv_join(sections));
}
