/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:29:19 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 10:17:23 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LS_H
# define B_LS_H
# include "btree.h"
# include "file.h"
# include <errno.h>
# include <sys/stat.h>

enum	e_sort_flags
{
	SORT_NAME,
	SORT_TIME
};

struct			s_opts
{
	enum e_sort_flags	sort;
	unsigned int		rev;
	unsigned int		l;
	unsigned int		all;
	unsigned int		recursive;
};

int				error(const char *filename);
struct s_opts	*get_opts(int *ac, char **av);
const char		*render(struct s_file *file, struct stat *s);
int				b_ls(t_btree **filetree, struct s_opts *opts, const char *filename);
int				b_ls_dir(struct s_opts *opts, const char *filename);

#endif
