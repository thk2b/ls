/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:52:33 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 11:40:29 by tkobb            ###   ########.fr       */
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

static int	b_ls_file(void *ctx, void *data)
{
	struct s_opts	*opts;
	struct s_file	*dir_data;

	opts = (struct s_opts*)ctx;
	dir_data = (struct s_file*)data;
	
}

static int	b_ls_dir(void *ctx, void *data)
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
		return (error(dir_data->name));
	while ((child = readdir(dir)))
	{
		if((child_data = get_file(opts, path_join(dir_data->name, child->d_name))) == NULL)
			return (error(path));
		// recursive: if child is a dir, call this fn with the file & don't add it to the tree
		btree_add(&tree, (void*)child_data, g_cmp);
	}
	g_traverse(tree, (void*)opts, print_file);
	return (0);
}

int			b_ls(struct s_opts *opts, size_t nfiles, const char **filenames)
{
	int				i;
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
		if (file->is_dir)
			return (b_ls_dir(opts, file));
		return (b_ls_file(opts, file));
	}
	while (i < nfiles)
	{
		if((file = get_file(opts, filenames[i])) == NULL)
			error(filenames[i]);
		btree_add(file->is_dir ? &dirtree : &filetree, (void*)file, g_cmp);
	}
	if (filetree != NULL)
		traverse(filetree, opts, print_file);
	if (dirtree != NULL)
		traverse(dirtree, opts, b_ls_dir);
	return (0);
}
