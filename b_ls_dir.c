/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:56:41 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 10:31:26 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include "btree.h"
#include "file.h"
#include "libft/libft.h"
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <limits.h>
#include <time.h>

static char	*path_join(char *dst, const char *base, const char *file)
{
	ft_memset(dst, 0, ft_strlen(base) + ft_strlen(file) + 2);
	ft_strcpy(dst, base);
	ft_strcat(dst, "/");
	ft_strcat(dst, file);
	return (dst);
}

static int	(*g_cmp) (void *s1, void *s2);

int			b_ls_dir(struct s_opts *opts, const char *dirname)
{
	DIR				*dir;
	char			path[PATH_MAX];
	struct dirent	*ent;
	struct s_file	*file;
	struct stat		st;
	t_btree			*root;

	ft_bzero(path, PATH_MAX);
	g_cmp = opts->sort == SORT_TIME ? cmp_time : cmp_name;
	if ((dir = opendir(dirname)) == NULL)
		return (error(dirname));
	while ((ent = readdir(dir)))
	{
		if ((file = file_new()) == NULL)
			return (1);
		if (ent->d_name[0] == '.' && opts->all == 0)
		{
			free(file);
			continue ;
		}
		if (stat(path_join(path, dirname, ent->d_name), &st) == -1)
		{
			error(ent->d_name);
			continue ;
		}
		file->name = ent->d_name;
		file->repr = NULL;
		file->timestamp = st.st_mtime;
		if (opts->l)
			file->repr = render(file, &st);
		btree_add(&root, (void*)file, g_cmp);
	}
	if (opts->rev)
		btree_in_back_order(root, print_file);
	else
		btree_in_order(root, print_file);
	btree_free(root);
	closedir(dir);
	return (0);
}
