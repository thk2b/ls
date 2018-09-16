/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:01:33 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/16 15:26:44 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include <stdlib.h>

static struct s_opts	*opts_new()
{
	struct s_opts	*opts;
	
	if ((opts = (struct s_opts*)malloc(sizeof(struct s_opts))) == NULL)
		return (NULL);
	opts->all = 0;
	opts->rev = 0;
	opts->l = 0;
	opts->recursive = 0;
	opts->sort = SORT_NAME;

	return (opts);
}

#include <stdio.h>
static void print_opts(struct s_opts *o)
{
	printf("all: %d\n", o->all);
	printf("long: %d\n", o->l);
	printf("recursive: %d\n", o->recursive);
	printf("rev: %d\n", o->rev );
	printf("time: %d\n", o->sort == SORT_TIME);
	printf("name: %d\n\n", o->sort == SORT_NAME);
}

struct s_opts	*get_opts(int *nflags, char **av)
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
				*nflags = flagi;
				return (opts);
			}
			opti++;
		}
		flagi++;
	}
	*nflags = flagi - 1;
//	print_opts(opts);
	(void)print_opts;
	return (opts);
}
