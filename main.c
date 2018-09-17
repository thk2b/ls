/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:28:46 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 10:10:40 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

int		main(int argc, char **argv)
{
	struct s_opts	*opts;
	int				nflags;
	int				nfiles;
	int				i;
	t_btree			*filetree;
	t_btree			*dirtree;

	(void)argc;
	filetree = NULL;
	nflags = 0;
	opts = get_opts(&nflags, argv);
	nfiles = argc - 1 - nflags;
	if (nfiles == 0)
		return (b_ls_dir(opts, "."));
	i = nflags + 1;
	while (i < argc)
		b_ls(&filetree, opts, argv[i++]);
	if (filetree != NULL)
		
	return (0);
}
