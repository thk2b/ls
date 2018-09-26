/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:27:06 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/25 18:19:02 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "opts.h"
# include <time.h>
# include <sys/stat.h>

typedef struct	s_file
{
	char		*name;
	char		*path;
	time_t		time;
	char		*repr;
	short		is_dir;
	blkcnt_t	blocks;
	blkcnt_t	in_blocks;
}				t_file;

t_file			*get_file(t_opts *opts, char *name, char *path);
int				cmp_files(void *v_ctx, void *v_file1, void *v_file2);
void			free_file(void *ctx, void *v_file);
void			free_file_only(void *ctx, void *v_file);

#endif
