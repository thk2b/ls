/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:01:33 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 20:38:32 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

struct s_opts	*get_opts(int ac, const char **av)
{
	struct s_opts	*opts;
	
	(void)ac;
	(void)av;
	if ((opts = (struct s_opts*)malloc(sizeof(struct s_opts))) == NULL)
		return (NULL);
	opts->all = 0;
	opts->l = 0;
	opts->recursive = 0;
	opts->sort = SORT_NAME;
	return (opts);
}
