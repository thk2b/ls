/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:52:33 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/22 20:56:48 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "btree.h"
#include "file.h"
#include "b_ls.h"
#include <dirent.h>
#include <limits.h>
#include <sys/stat.h>
#include <stdio.h>

static void	traverse(t_btree *root, void *ctx, void(*f)(void *ctx, void *data))
{
	if (((struct s_opts *)ctx)->rev)
		return btree_in_back_order(root, ctx, f);
	return btree_in_order(root, ctx, f);
}

static void	b_ls_dir(void *ctx, void *data)
{
	struct s_opts	*opts;
	struct s_file	*dir_data;
	t_btree			*tree;
	t_btree			*recursive_tree;
	DIR				*dir;
	struct dirent	*child;
	struct s_file	*child_data;

	tree = NULL;
	recursive_tree = NULL;
	opts = (struct s_opts*)ctx;
	dir_data = (struct s_file*)data;
	if ((dir = opendir(dir_data->path)) == NULL)
		return ((void)error(dir_data->path));
	if (opts->nfiles > 1 || (dir_data->is_dir && opts->recursive && ft_strcmp(dir_data->name, ".")))
	{
		ft_putchar('\n');
		ft_putstr(dir_data->path);
		ft_putstr(":\n");
	}		
	while ((child = readdir(dir)))
	{
		if (opts->all == 0 && child->d_name[0] == '.')
			continue ;
		if((child_data = get_file(opts, ft_strdup(child->d_name), ft_strcjoin(dir_data->path, '/', child->d_name))) == NULL)
		{
			(void)error("child path goes here");
			continue ;
		}
		if (opts->recursive && child_data->is_dir && child_data->name[0] != '.')
			btree_add(&recursive_tree, (void*)child_data, (void*)opts, cmp_files);
		btree_add(&tree, (void*)child_data, (void*)opts, cmp_files);
	}
	closedir(dir);
	traverse(tree, (void*)opts, print_file);
	btree_free(tree);
	if (recursive_tree)
	{
		traverse(recursive_tree, (void*)opts, b_ls_dir);
		btree_free(recursive_tree);
	}
	dealloc_file(dir_data);
	free(dir_data);
}

int			b_ls(struct s_opts *opts, const char **filenames)
{
	size_t			i;
	struct s_file	*file;
	t_btree			*filetree;
	t_btree			*dirtree;

	filetree = NULL;
	dirtree = NULL;
	if (opts->nfiles == 0)
	{
		if((file = get_file(opts, ft_strdup("."), ft_strdup("."))) == NULL)
			return (error("."));
		b_ls_dir(opts, file);
		return (0);
	}
	i = 0;
	while (i < opts->nfiles)
	{
		if((file = get_file(opts, ft_strdup(filenames[i]), ft_strdup(filenames[i]))) == NULL)
			error(filenames[i]);
		else
			btree_add(file->is_dir ? &dirtree : &filetree, (void*)file, (void*)opts, cmp_files);
		i++;
	}
	if (filetree != NULL)
	{
		traverse(filetree, (void*)opts, print_file);
		btree_free(filetree);
	}
	if (dirtree != NULL)
	{
		traverse(dirtree, (void*)opts, b_ls_dir);
		btree_free(dirtree);
	}
	return (0);
}
