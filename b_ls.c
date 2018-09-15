/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:33:31 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 11:50:59 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

static char	*get_file_perms(struct stat *s)
{
	char	*perms;
	char	*p;

	if((perms = (char*)malloc(11 * sizeof(char))) == NULL)
		return (NULL);
	p = perms;
	*p++ = S_ISDIR(s->st_mode) ? 'd' : '-';
	*p++ = (s->st_mode & S_IRUSR) ? 'r' : '-';
	*p++ = (s->st_mode & S_IWUSR) ? 'w' : '-';
	*p++ = (s->st_mode & S_IXUSR) ? 'x' : '-';
	*p++ = (s->st_mode & S_IRGRP) ? 'r' : '-';
	*p++ = (s->st_mode & S_IWGRP) ? 'w' : '-';
	*p++ = (s->st_mode & S_IXGRP) ? 'x' : '-';
	*p++ = (s->st_mode & S_IROTH) ? 'r' : '-';
	*p++ = (s->st_mode & S_IWOTH) ? 'w' : '-';
	*p++ = (s->st_mode & S_IXOTH) ? 'x' : '-';
	*p = '\0';
	return (perms);
}

static void	print_long_info(const char *path)
{
	struct stat	s;

	if(stat(path, &s) == -1)
		return (void)printf("%s: stat: %s\n", path, strerror(errno));
	printf("%s\n", get_file_perms(&s));
}

void	b_ls(const char *filename)
{
	DIR	*dir;
	struct dirent	*ent;
	char	path[PATH_MAX];

	if((dir = opendir(filename)) == NULL)
		return (void)printf("%s: %s\n", filename, strerror(errno));
	
	while ((ent = readdir(dir)))
	{
		print_long_info(strcat(strcat(strcpy(path, filename), "/"), ent->d_name));
	}
}
