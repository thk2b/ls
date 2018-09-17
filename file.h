/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:15:32 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 10:17:28 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# include <time.h>

struct			s_file
{
	const char	*name;
	time_t		timestamp;
	const char	*repr;
};

int				cmp_name(void*, void*);
int				cmp_time(void*, void*);
void			print_file(void*);

#endif
