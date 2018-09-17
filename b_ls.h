/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:29:19 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 11:58:29 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LS_H
# define B_LS_H
# include "btree.h"
# include "file.h"
# include "opts.h"
# include <errno.h>
# include <stdlib.h>
# include <sys/stat.h>

int				error(const char *filename);
int				b_ls(struct s_opts *opts, size_t nfiles, const char **filename);

#endif
