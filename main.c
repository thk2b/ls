/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:28:46 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 12:07:42 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include "file.h"

int		main(int argc, char **argv)
{
	struct s_opts	*opts;
	int				nflags;
	int				nfiles;

	(void)argc;
	nflags = 0;
	opts = get_opts(&nflags, argv);
	nfiles = argc - 1 - nflags;
	return (b_ls(opts, nfiles, argv + nflags));
}
