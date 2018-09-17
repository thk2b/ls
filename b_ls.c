/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:52:33 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 12:07:47 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "btree.h"
#include "file.h"
#include "b_ls.h"
#include <dirent.h>
#include <limits.h>
#include <sys/stat.h>

static int	(*g_cmp) (void*, void*);
static void	(*g_traverse) (t_btree *root, void *ctx, void(*f)(void *ctx, void *data));

static char	*path_join(char *dst, const char *base, const char *file)
{
	ft_memset(dst, 0, ft_strlen(base) + ft_strlen(file) + 2);
	ft_strcpy(dst, base);
	ft_strcat(dst, "/");
	ft_strcat(dst, file);
	return (dst);
}

static void	b_ls_dir(void *ctx, void *data)
{
	struct s_opts	*opts;
	struct s_file	*dir_data;
	t_btree			*tree;
	DIR				*dir;
	struct dirent	*child;
	struct s_file	*child_data;
	char			path[PATH_MAX];

	opts = (struct s_opts*)ctx;
	dir_data = (struct s_file*)data;
	if ((dir = opendir(dir_data->name)) == NULL)
		return ((void)error(dir_data->name));
	while ((child = readdir(dir)))
	{
		if((child_data = get_file(opts, path_join(path, dir_data->name, child->d_name))) == NULL)
			return ((void)error(path));
		// recursive: if child is a dir, call this fn with the file & don't add it to the tree
		btree_add(&tree, (void*)child_data, g_cmp);
	}
	g_traverse(tree, (void*)opts, print_file);
}

int			b_ls(struct s_opts *opts, size_t nfiles, const char **filenames)
{
	size_t			i;
	struct s_file	*file;
	t_btree			*filetree;
	t_btree			*dirtree;

	filetree = NULL;
	dirtree = NULL;
	g_cmp = opts->sort == SORT_NAME ? cmp_name : cmp_time;
	g_traverse = opts->rev ? btree_in_back_order : btree_in_order;
	if (nfiles == 0)
	{
		if((file = get_file(opts, ".")) == NULL)
			return (error("."));
		b_ls_dir(opts, file);
		return (0);
	}
	i = 0;
	while (i < nfiles)
	{
		if((file = get_file(opts, filenames[i])) == NULL)
			error(filenames[i]);
		btree_add(file->is_dir ? &dirtree : &filetree, (void*)file, g_cmp);
		i++;
	}
	if (filetree != NULL)
		g_traverse(filetree, opts, print_file);
	if (dirtree != NULL)
		g_traverse(dirtree, opts, b_ls_dir);
	return (0);
}
