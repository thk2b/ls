/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:28:46 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 16:40:51 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include "file.h"

int		main(int argc, const char **argv)
{
	struct s_opts	*opts;

	(void)argc;
	opts = get_opts(argc, argv);
	return (b_ls(opts, argv + argc - opts->nfiles));
}
