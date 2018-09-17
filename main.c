/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:28:46 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 15:28:27 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include "file.h"

#include <stdio.h>
int		main(int argc, const char **argv)
{
	struct s_opts	*opts;
	int				nflags;
	int				nfiles;

	(void)argc;
	nflags = 0;
	opts = get_opts(&nflags, argv);
	nfiles = argc - 1 - nflags;
	printf("nflags=%d, nfiles=%d, files[0]=%s\n", nflags, nfiles, *(argv+nflags));
	return (b_ls(opts, nfiles, argv + nflags + 1));
}
