/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:40:22 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 15:00:07 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTS_H
# define OPTS_H

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

struct s_opts	*get_opts(int *ac, const char **av);

#endif
