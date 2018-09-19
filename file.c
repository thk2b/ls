/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:18:31 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/18 22:14:25 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "opts.h"
#include "file.h"
#include <sys/stat.h>

int					cmp_files(void *ctx, void *d1, void *d2)
{
	struct s_file	*f1;
	struct s_file	*f2;
	struct s_opts	*opts;
	int				cmp;

	f1 = (struct s_file*)d1;
	f2 = (struct s_file*)d2;
	opts = (struct s_opts*)ctx;
	cmp = 0;
	if (opts->sort == SORT_TIME)
		cmp = (int)f2->timestamp - (int)f1->timestamp;
		if (cmp != 0)
			return (cmp);
	return (ft_strcmp(f1->path, f2->path));
}

void				print_file(void *ctx, void *vfile)
{
	struct s_file	*file;
	struct s_opts	*opts;
	opts = (struct s_opts*)ctx;
	file = (struct s_file*)vfile;
	ft_putstr(file->repr);
	ft_putchar('\n');
	if (file->is_dir && opts->recursive)
		return ;
	dealloc_file(file);
	free(vfile);
}

struct s_file	*get_file(struct s_opts *opts, const char *name, const char *path)
{
	struct s_file	*file;
	struct stat		st;

	if ((file = (struct s_file*)malloc(sizeof(struct s_file))) == NULL)
		return (NULL);
	file->path = ft_strdup(path);
	if (stat(path, &st) == -1)
		return (NULL);
	file->is_dir = S_ISDIR(st.st_mode);
	file->name = ft_strdup(name);
	file->timestamp = st.st_mtime;
	if (opts->l)
		file->repr = render(file, &st);
	else
		file->repr = file->name;
	return (file);
}

void			dealloc_file(struct s_file *file)
{
	if (file->repr != file->name)
		free((char*)file->repr);
	free((char*)file->name);
	free((char*)file->path);
}
