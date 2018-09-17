/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:15:32 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 10:43:29 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include "b_ls.h"
# include "opts.h"
# include <time.h>

struct			s_file
{
	const char	*name;
	time_t		timestamp;
	const char	*repr;
	int			is_dir;
};

int				cmp_name(void*, void*);
int				cmp_time(void*, void*);
void			print_file(void*);
struct s_file	*get_file(struct s_opts *opts, const char *path);

#endif