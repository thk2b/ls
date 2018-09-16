/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:03:57 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 22:08:39 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_ls.h"

static char	*get_perms(struct stat *s)
{
	
}

static char *get_uname(struct stat *s)
{

}

static char *get_gname(struct stat *s)
{
	
}

static char *get_time(struct stat *s)
{
	
}

const char *render(struct s_file *file, struct stat *s)
{
	char *sections[8];
	
	sections[8] = NULL;
	sections[0] = get_perms(s);
	sections[1] = atoi(s->st_nlink);
	sections[2] = get_uname(s);
	sections[3] = get_gname(s);
	sections[4] = s->st_size;
	sections[5] = get_time(s);
	sections[6] = file->name;
	return (strv_join(sections));
}
