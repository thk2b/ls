/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:29:19 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 22:09:24 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LS_H
# define B_LS_H
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

enum	e_sort_flags
{
	SORT = 0x0,
	SORT_NAME = 0x1,
	SORT_TIME = 0x2,
	SORT_REV = 0x4,
};

struct	s_opts
{
	unsigned int	sort;
	unsigned int	l;
	unsigned int	all;
	unsigned int	recursive;
};

struct	s_file
{
	const char	*name;
	time_t		timestamp;
	const char	*repr;
};

int				error(const char *filename);
struct s_opts	*get_opts(int ac, char **av);
const char		*render(struct s_file *file, struct stat *s);
int				b_ls(struct s_opts *opts, const char *filename);

#endif
