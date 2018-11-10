/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:20:33 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/10 00:38:17 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTS_H
# define OPTS_H
# define SORT_TIME 1
# define SORT_SIZE 2

typedef struct	s_opts
{
	char		sort;
	int			nfiles;
	short		sort_rev;
	short		show_long;
	short		recursive;
	short		show_all;
	short		show_dir_header;
	short		full_time;
}				t_opts;

t_opts			*get_opts(int ac, char **av);

#endif
