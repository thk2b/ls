/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:33:31 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 13:47:16 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

static void	print_file_perms(struct stat *s)
{
	printf("%c%c%c%c%c%c%c%c%c%c  ",
		S_ISDIR(s->st_mode) ? 'd' : '-',
		(s->st_mode & S_IRUSR) ? 'r' : '-',
		(s->st_mode & S_IWUSR) ? 'w' : '-',
		(s->st_mode & S_IXUSR) ? 'x' : '-',
		(s->st_mode & S_IRGRP) ? 'r' : '-',
		(s->st_mode & S_IWGRP) ? 'w' : '-',
		(s->st_mode & S_IXGRP) ? 'x' : '-',
		(s->st_mode & S_IROTH) ? 'r' : '-',
		(s->st_mode & S_IWOTH) ? 'w' : '-',
		(s->st_mode & S_IXOTH) ? 'x' : '-'
	);
}

static void	print_uname(struct stat *s)
{
	struct passwd *pw;

	pw = getpwuid(s->st_uid);
	printf("%s  ", pw->pw_name);
}

static void	print_gname(struct stat *s)
{
	struct group *gr;

	gr = getgrgid(s->st_gid);
	printf("%s  ", gr->gr_name);
}

static void	print_time(struct stat *s)
{
	struct tm	*time;
	char		st[20];
	
	time = localtime(&s->st_mtimespec.tv_sec);
	strftime(st, 20, "%b %d %R", time);
	printf("%s ", st);
}

static void	print_long_info(const char *dirname, const char *filename)
{
	struct stat	s;
	char		path[PATH_MAX];
	
	strcat(strcat(strcpy(path, dirname), "/"), filename);
	if(stat(path, &s) == -1)
		return (void)printf("%s: stat: %s\n", path, strerror(errno));
	print_file_perms(&s);
	printf("%d  ", s.st_nlink);
	print_uname(&s);
	print_gname(&s);
	printf("%5lld  ", s.st_size);
	print_time(&s);
	printf("%s ", filename);
	printf("\n");
}

void	b_ls(const char *filename)
{
	DIR	*dir;
	struct dirent	*ent;

	if((dir = opendir(filename)) == NULL)
		return (void)printf("%s: %s\n", filename, strerror(errno));
	
	while ((ent = readdir(dir)))
	{
		print_long_info(filename, ent->d_name);
	}
}
