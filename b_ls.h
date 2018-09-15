/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:29:19 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 13:28:55 by tkobb            ###   ########.fr       */
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

void	b_ls(const char *dirname);

#endif
