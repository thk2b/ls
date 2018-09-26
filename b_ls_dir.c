/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 19:16:00 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/25 19:29:39 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include "btree.h"
#include "b_ls.h"
#include "opts.h"
#include "file.h"
#include "lib.h"
#include "error.h"
#include <stdlib.h>
#include <dirent.h>
#include <printf.h>
#include <sys/stat.h>

static int		should_recurse(t_file *file, t_opts *opts)
{
	if (file->is_dir == 0 || opts->recursive == 0)
		return (0);
	if (file->name[0] == '.')
	{
		if (file->name[1] == 0 || file->name[1] == '.')
			return (0);
		return (opts->show_all);
	}
	return (opts->recursive);
}

static blkcnt_t	get_files(t_file *dir, t_opts *opts,
	t_btree **tree, t_btree **rtree)
{
	DIR				*std_dir;
	struct dirent	*ent;
	t_file			*file;
	char			*path;
	blkcnt_t		blocks;

	blocks = 0;
	if ((std_dir = opendir(dir->path)) == NULL)
		return (error(dir->path) && 0);
	while ((ent = readdir(std_dir)) != NULL)
	{
		if (ent->d_name[0] == '.' && opts->show_all == 0)
			continue ;
		if ((path = ft_strcjoin(dir->path, '/', ent->d_name)) == NULL)
			return (error(NULL) && 0);
		if ((file = get_file(opts, ft_strdup(ent->d_name), path)) == NULL)
			continue ;
		btree_add(tree, opts, (void*)file, cmp_files);
		if (should_recurse(file, opts))
			btree_add(rtree, opts, (void*)file, cmp_files);
		if (opts->show_long)
			blocks += file->blocks;
	}
	closedir(std_dir);
	return (blocks);
}

void			b_ls_dir(void *v_opts, void *v_dir)
{
	t_btree			*tree;
	t_btree			*rtree;
	t_opts			*opts;
	blkcnt_t		blocks;

	opts = (t_opts*)v_opts;
	tree = NULL;
	rtree = NULL;
	blocks = get_files((t_file*)v_dir, opts, &tree, &rtree);
	if (opts->show_dir_header)
		printf("\n%s:\n", ((t_file*)v_dir)->path);
	if (opts->show_long)
		printf("total %lld\n", blocks);
	if (opts->recursive)
	{
		traverse(tree, v_opts, b_ls_file);
		opts->show_dir_header = 1;
		traverse(rtree, v_opts, b_ls_dir);
		btree_free(rtree, v_opts, free_file_only);
		btree_free(tree, v_opts, free_file);
		return ;
	}
	traverse(tree, v_opts, b_ls_file);
	btree_free(tree, v_opts, free_file);
}
