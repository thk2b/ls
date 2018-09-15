/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:29:19 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 11:38:02 by tkobb            ###   ########.fr       */
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

void	b_ls(const char *dirname);

#endif
