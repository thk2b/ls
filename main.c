/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:28:46 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 20:58:18 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

int		main(int argc, char **argv)
{
	struct s_opts	*opts;

	opts = get_opts(argc, argv);
	if (argc == 1)
		b_ls(opts, ".");
	++argv;
	while (*argv)
		b_ls(opts, *argv++);
	return (0);
}
