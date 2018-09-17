/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:15:32 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 15:25:26 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "b_ls.h"
# include "opts.h"
# include <time.h>
# include <sys/stat.h>

struct			s_file
{
	const char	*name;
	const char	*path;
	time_t		timestamp;
	const char	*repr;
	int			is_dir;
};

int				cmp_name(void*, void*);
int				cmp_time(void*, void*);
void			print_file(void *ctx, void *data);
const char		*render(struct s_file *file, struct stat *s);
struct s_file	*get_file(struct s_opts *opts, const char *name, const char *path);
void			dealloc_file(struct s_file *file);

#endif
