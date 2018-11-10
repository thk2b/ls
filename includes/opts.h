/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:20:33 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/25 14:32:46 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTS_H
# define OPTS_H

enum			e_sort
{
	SORT_NAME, SORT_TIME
};

typedef struct	s_opts
{
	enum e_sort	sort;
	int			nfiles;
	short		sort_rev;
	short		show_long;
	short		recursive;
	short		show_all;
	short		show_dir_header;
}				t_opts;

t_opts			*get_opts(int ac, char **av);

#endif
