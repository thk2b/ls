/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:28:46 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/16 15:20:41 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

int		main(int argc, char **argv)
{
	struct s_opts	*opts;
	int				nflags;
	int				nfiles;
	int				i;
	
	(void)argc;
	nflags = 0;
	opts = get_opts(&nflags, argv);
	nfiles = argc - 1 - nflags;
	if (nfiles == 0)
		return (b_ls(opts, "."));
	i = nflags + 1;
	while (i < argc)
		b_ls(opts, argv[i++]);
	return (0);
}
