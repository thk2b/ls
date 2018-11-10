/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:27:12 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/10 00:08:53 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_UTILS_H
# define RENDER_UTILS_H
# include <sys/stat.h>
# include "file.h"

char	*perms(mode_t m);
char	*user(uid_t i);
char	*group(gid_t i);
char	*get_time(time_t *t);
char	*get_link(t_file *file, struct stat *st);
char	*maj_min(dev_t dev);

#endif
