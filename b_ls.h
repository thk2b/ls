/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:18:53 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/25 19:17:45 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LS_H
# define B_LS_H
# include "opts.h"
# include "btree.h"

# define ALLOC_CHECK(p) if((p) == NULL) return (-1)

void	b_ls(t_opts *opts, char **filename);
void	b_ls_file(void *opts, void *file);
void	b_ls_dir(void *opts, void *dir);
void	traverse(t_btree *root, void *v_opts, t_btree_fn f);

#endif
