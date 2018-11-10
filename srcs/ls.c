/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:16:36 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/09 22:21:16 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <btree.h>
#include <ls.h>
#include <opts.h>
#include <file.h>
#include <libft.h>
#include <error.h>
#include <ft_printf.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void		traverse(t_btree *root, void *v_opts, t_btree_fn f)
{
	t_opts	*opts;

	opts = (t_opts*)v_opts;
	if (opts->sort_rev)
		btree_back_inorder(root, (void*)opts, f);
	else
		btree_inorder(root, (void*)opts, f);
}

void		ls_file(void *v_opts, void *v_file)
{
	t_opts	*opts;
	t_file	*file;

	opts = (t_opts*)v_opts;
	file = (t_file*)v_file;
	ft_printf("%s\n", file->repr);
}

static void	ls_dot(t_opts *opts)
{
	t_file *file;

	if ((file = get_file(opts, ft_strdup("."), ft_strdup("."))) == NULL)
		return ((void)error("."));
	ls_dir((void*)opts, (void*)file);
	free_file((void*)opts, (void*)file);
	return ;
}

void		ls(t_opts *opts, char **filenames)
{
	t_btree		*files;
	t_btree		*dirs;
	t_file		*file;
	int			i;

	files = NULL;
	dirs = NULL;
	if (opts->nfiles == 0)
		return ((void)ls_dot(opts));
	i = 0;
	while (i < opts->nfiles)
	{
		file = get_file(opts, ft_strdup(filenames[i]), ft_strdup(filenames[i]));
		if (file == NULL)
			continue ;
		else if (file->is_dir)
			btree_add(&dirs, (void*)opts, (void*)file, cmp_files);
		else
			btree_add(&files, (void*)opts, (void*)file, cmp_files);
		i++;
	}
	traverse(files, (void*)opts, ls_file);
	btree_free(files, (void*)opts, free_file);
	traverse(dirs, (void*)opts, ls_dir);
	btree_free(dirs, (void*)opts, free_file);
}
