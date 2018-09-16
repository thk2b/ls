/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:56:41 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 20:37:25 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include "btree.h"

static int	cmp_name(void *f1,
	void *f2)
{
	return (strcmp(((const struct s_file*)f1)->name,
		((const struct s_file*)f2)->name));
}

/*static int	cmp_time(void *f1,
	void *f2)
{
	return (((struct s_file*)f1)->name >
		((struct s_file*)f2)->name);
}*/

static void	print_file(void *vfile)
{
	struct s_file *file;
	file = (struct s_file*)vfile;
	printf("%s\n", file->repr ? file->repr : file->name);
}

static char	*path_join(char *dst, const char *base, const char *file)
{
	memset((char*)dst, 0, strlen(dst));
	strcpy(dst, base);
	strcat(dst, "/");
	strcat(dst, file);
	return (dst);
}

static int (*cmp) (void *s1, void *s2);

static struct s_file *file_new(void)
{
	return ((struct s_file*)malloc(sizeof(struct s_file)));
}

int			b_ls(struct s_opts *opts, const char *filename)
{
	DIR	*dir;
	char			path[PATH_MAX];
	struct dirent	*ent;
	struct s_file	*file;
	struct stat		st;
	t_btree	*root;

	(void)opts;
	cmp = cmp_name;
	if((dir = opendir(filename)) == NULL)
		return (error(filename));
	while ((ent = readdir(dir)))
	{
		if((file = file_new()) == NULL)
			return (1);
		if (stat(path_join(path, filename, ent->d_name), &st) == -1)
			return (1);
		file->name = ent->d_name;
		file->timestamp = st.st_mtime;
		btree_add(&root, (void*)file, cmp);
	}
	btree_in_order(root, print_file);
	btree_free(root);
	return (0);
}
