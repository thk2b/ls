/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:56:41 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/16 13:41:14 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include "btree.h"

static int	cmp_name(void *f1, void *f2)
{
	return (strcmp(((const struct s_file*)f1)->name,
		((const struct s_file*)f2)->name));
}

static int	cmp_time(void *f1, void *f2)
{
	int	cmp;

	cmp = ((struct s_file*)f2)->timestamp -
		((struct s_file*)f1)->timestamp;
	if (cmp == 0)
		return (cmp_name(f2, f1));
	return (cmp);
}

static void	print_file(void *vfile)
{
	struct s_file *file;
	file = (struct s_file*)vfile;
	printf("%s\n", file->repr ? file->repr : file->name);
	
	free(vfile);
}


static char	*path_join(char *dst, const char *base, const char *file)
{
	strcpy(dst, base);
	strcat(dst, "/");
	strcat(dst, file);
	return (dst);
}

static int (*g_cmp) (void *s1, void *s2);

static struct s_file *file_new(void)
{
	return ((struct s_file*)malloc(sizeof(struct s_file)));
}

int			b_ls(struct s_opts *opts, const char *filename)
{
	DIR				*dir;
	char			path[PATH_MAX];
	struct dirent	*ent;
	struct s_file	*file;
	struct stat		st;
	t_btree			*root;

	g_cmp = opts->sort & SORT_NAME ? cmp_name : cmp_time;
	if((dir = opendir(filename)) == NULL)
		return (error(filename));
	while ((ent = readdir(dir)))
	{
		if((file = file_new()) == NULL)
			return (1);
		if (stat(path_join(path, filename, ent->d_name), &st) == -1)
			return (1);
		file->name = ent->d_name;
		file->repr = NULL;
		file->timestamp = st.st_mtime;
		if (opts->l)
			file->repr = render(file, &st);
		btree_add(&root, (void*)file, g_cmp);
	}
	if (opts->sort & SORT_REV)
		btree_in_back_order(root, print_file);
	else
		btree_in_order(root, print_file);
	btree_free(root);
	closedir(dir);
	return (0);
}
