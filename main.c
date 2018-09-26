/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:09:26 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/25 18:37:21 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"
#include "opts.h"
#include "error.h"
#include <stdlib.h>
#include <errno.h>

int		main(int ac, char **av)
{
	t_opts	*opts;

	if ((opts = get_opts(ac, av)) == NULL)
		return (error(NULL));
	b_ls(opts, av + (ac - opts->nfiles));
	free(opts);
	return (errno);
}
