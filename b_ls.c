/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:56:41 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 15:12:11 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

static int	cmp_name(const struct s_file *f1,
	const struct s_file *s2)
{

}

static int	cmp_time(const struct s_file *s1,
	const struct s_file *s2)
{

}

int		b_ls(struct s_opts *opts, const char *filename)
{
	DIR	*dir;
	struct dirent	*ent;
	struct s_file	*file;
	t_btree	*root;
	static int (*cmp) (const struct s_file *s1, const struct s_file *s2);

	if((dir = opendir(filename)) == NULL)
		return (error(filename));
	while ((ent = readdir(dir)))
	{
		file = file_new(filename, ent);
		btree_add(&root, (void*)file, cmp);
	}
}
