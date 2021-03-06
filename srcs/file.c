/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:34:37 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/10 21:47:03 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file.h>
#include <error.h>
#include <libft.h>
#include <render.h>
#include <stdlib.h>
#include <sys/stat.h>

t_file		*get_file(t_opts *opts, char *name, char *path)
{
	t_file		*file;
	struct stat	buf;

	if ((file = (t_file*)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	if (opts->show_long ? lstat(path, &buf) : stat(path, &buf) == -1)
	{
		error(path);
		return (NULL);
	}
	file->name = name;
	file->path = path;
	file->time = buf.st_mtimespec;
	file->size = buf.st_size;
	file->is_dir = S_ISDIR(buf.st_mode);
	file->blocks = buf.st_blocks;
	if (opts->show_long)
		file->repr = pre_render_file_long(opts, file, &buf);
	else
		file->repr = file->name;
	return (file);
}

int			cmp_files(void *v_opts, void *v_file1, void *v_file2)
{
	t_opts	*opts;
	t_file	*file1;
	t_file	*file2;
	int		cmp;

	opts = (t_opts*)v_opts;
	file1 = (t_file *)v_file1;
	file2 = (t_file *)v_file2;
	if (opts->sort & SORT_SIZE)
	{
		if ((cmp = file2->size - file1->size) != 0)
			return (cmp);
	}
	else if (opts->sort & SORT_TIME)
	{
		if ((cmp = file2->time.tv_sec - file1->time.tv_sec))
			return (cmp);
		else if ((cmp = file2->time.tv_nsec - file1->time.tv_nsec))
			return (cmp);
	}
	return (ft_strcmp(file1->name, file2->name));
}

void		free_file(void *ctx, void *v_file)
{
	t_file	*file;

	(void)ctx;
	file = (t_file*)v_file;
	if (file->name != file->repr)
		free(file->repr);
	free(file->name);
	free(file->path);
	free(file);
}

void		free_file_only(void *ctx, void *v_file)
{
	t_file	*file;

	(void)ctx;
	file = (t_file*)v_file;
	if (file->is_dir)
		return ;
	if (file->name != file->repr)
		free(file->repr);
	file = (t_file*)v_file;
	free(file->name);
	free(file->path);
	free(v_file);
}
