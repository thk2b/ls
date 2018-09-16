/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 09:28:46 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 20:39:04 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

int		main(int argc, char **argv)
{
	struct s_opts	*opts;

	opts = get_opts(argc, (const char **)argv);
	if (argc == 1)
		b_ls(opts, ".");
	return (0);
}
