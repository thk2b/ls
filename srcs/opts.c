/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:25:19 by tkobb             #+#    #+#             */
/*   Updated: 2018/11/10 21:48:51 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <opts.h>
#include <stdlib.h>

t_opts		*opts_new(void)
{
	t_opts	*opts;

	if ((opts = (t_opts*)malloc(sizeof(t_opts))) == NULL)
		return (NULL);
	opts->show_long = 0;
	opts->sort = 0;
	opts->sort_rev = 0;
	opts->recursive = 0;
	opts->show_all = 0;
	opts->show_dir_header = 0;
	opts->full_time = 0;
	return (opts);
}

static void	set_opts(t_opts *opts, char c)
{
	if (c == 'l')
		opts->show_long = 1;
	else if (c == 't')
		opts->sort |= SORT_TIME;
	else if (c == 'r')
		opts->sort_rev = 1;
	else if (c == 'R')
		opts->recursive = 1;
	else if (c == 'a')
		opts->show_all = 1;
	else if (c == 'T')
		opts->full_time = 1;
	else if (c == 'S')
		opts->sort |= SORT_SIZE;
	else
	{
		ft_dprintf(2, "illegal option -- %c\n\
		usage: b_ls [-altRSTr] [file ...]\n", c);
		exit(1);
	}
}

t_opts		*get_opts(int ac, char **av)
{
	t_opts	*opts;
	int		i;
	int		j;

	if ((opts = opts_new()) == NULL)
		return (NULL);
	i = 1;
	j = 1;
	while (av[i] && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
			set_opts(opts, av[i][j++]);
		i++;
	}
	opts->nfiles = ac - i;
	opts->show_dir_header = opts->nfiles > 1;
	return (opts);
}
