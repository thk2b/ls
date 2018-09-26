/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:33:55 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/23 18:03:40 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <stdlib.h>

int		ft_strcmp(const char *s, const char *t);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strcjoin(const char *s, char sep, const char *t);

#endif
