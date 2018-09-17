/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:52:33 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 11:06:23 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "btree.h"
#include "file.h"
#include "b_ls.h"
#include <sys/stat.h>

static int	(*g_cmp) (void*, void*);
static void	(*g_traverse) (t_btree *root, void(*f)(void *ctx, void *data));

int		b_ls(struct s_opts *opts, size_t nfiles, const char **filenames)
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
		traverse(filetree, opts, b_ls_file);
	if (dirtree != NULL)
		traverse(dirtree, opts, b_ls_dir);
	return (0);
}
