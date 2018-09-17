/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:18:31 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 11:33:23 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "file.h"
#include <sys/stat.h>

int				cmp_name(void *f1, void *f2)
{
	return (ft_strcmp(((const struct s_file*)f1)->name,
		((const struct s_file*)f2)->name));
}

int				cmp_time(void *f1, void *f2)
{
	int	cmp;

	cmp = ((struct s_file*)f2)->timestamp -
		((struct s_file*)f1)->timestamp;
	if (cmp == 0)
		return (cmp_name(f2, f1));
	return (cmp);
}

void				print_file(void *ctx, void *vfile)
{
	struct s_file	*file;

	(void)ctx;
	file = (struct s_file*)vfile;
	ft_putstr(file->repr ? file->repr : file->name);
	ft_putchar('\n');
	free(vfile);
}

struct s_file	*get_file(struct s_opts *opts, const char *path)
{
	struct s_file	*file;
	struct stat		st;

	if (file = ((struct s_file*)malloc(sizeof(struct s_file))) == NULL)
		return (NULL);
	file->name = path;
	if (stat(path, &st) == -1)
		return (error(path));
	file->repr = NULL;
	file->timestamp = st.st_mtime;
	if (opts->l)
		file->repr = render(file, &st);
	return (file);
}
