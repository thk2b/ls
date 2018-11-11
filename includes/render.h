/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:51:23 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/10 21:43:05 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "file.h"
# include <sys/stat.h>

void	render_file(t_file *file);
char	*pre_render_file_long(t_opts *opts, t_file *file, struct stat *statbuf);

#endif
