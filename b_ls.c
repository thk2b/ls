/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:56:41 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 19:20:37 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include "bree.h"

static int	cmp_name(const struct s_file *f1,
	const struct s_file *s2)
{
	return (strcmp(f1->name, f2->name));
}

static int	cmp_time(const struct s_file *f1,
	const struct s_file *f2)
{
	return (f1->timestamp < f2->timestamp);
}

static void	print_file(struct s_file *file)
{
	printf("%s\n", file->repr ? file->repr : file->name);
}

static char	*path_join(char *dst, const char *base, const char *file)
{
	memset((char*)dst, 0);
	strcpy(dst, base);
	strcat(dst, "/");
	strcat(dst, file);
	return (dst);
}

static int (*cmp) (const struct s_file *s1, const struct s_file *s2);

int			b_ls(struct s_opts *opts, const char *filename)
{
	DIR	*dir;
	char			path[PATH_MAX];
	struct dirent	*ent;
	struct s_file	*file;
	struct stat		stat;
	t_btree	*root;

	cmp = cmp_name;
	if((dir = opendir(filename)) == NULL)
		return (error(filename));
	while ((ent = readdir(dir)))
	{
		if((file = file_new()) == NULL)
			return (1);
		if ((stat = stat(path_join(path, base, file))))
			return (1);
		file->name = ent->d_name;
		file->timestamp = stat->st_mtime;
		btree_add(&root, (void*)file, cmp);
	}
	btree_inorder(root);
	btree_free(root);
	return (0);
}
