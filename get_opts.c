/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:01:33 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 16:39:42 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include "opts.h"
#include <stdlib.h>

static struct s_opts	*opts_new(void)
{
	struct s_opts	*opts;

	if ((opts = (struct s_opts*)malloc(sizeof(struct s_opts))) == NULL)
		return (NULL);
	opts->all = 0;
	opts->nfiles = 0;
	opts->rev = 0;
	opts->l = 0;
	opts->recursive = 0;
	opts->sort = SORT_NAME;
	return (opts);
}

struct s_opts			*get_opts(int ac, const char **av)
{
	struct s_opts	*opts;
	size_t			opti;
	size_t			flagi;

	if ((opts = opts_new()) == NULL)
		error("b_ls");
	flagi = 1;
	while (av[flagi] && av[flagi][0] == '-')
	{
		opti = 1;
		while (av[flagi][opti])
		{
			if (av[flagi][opti] == 'a')
				opts->all = 1;
			else if (av[flagi][opti] == 'l')
				opts->l = 1;
			else if (av[flagi][opti] == 't')
				opts->sort = SORT_TIME;
			else if (av[flagi][opti] == 'r')
				opts->rev = 1;
			else if (av[flagi][opti] == 'R')
				opts->recursive = 1;
			if (av[flagi][opti] == '-')
			{
				return (opts);
			}
			opti++;
		}
		flagi++;
	}
	opts->nfiles = ac - flagi;
	return (opts);
}
