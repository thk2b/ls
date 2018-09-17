/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 18:23:51 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 15:45:30 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H
# include "stdlib.h"

typedef struct	s_btree
{
	struct s_btree	*right;
	struct s_btree	*left;
	void			*data;
}				t_btree;

t_btree			*btree_new(void *data);
t_btree			*btree_add(t_btree **root, void *data, void *ctx, int (*cmp)(void *ctx, void *a, void *b));
void			btree_in_order(t_btree *root, void *ctx, void (*f)(void* ctx, void *data));
void			btree_in_back_order(t_btree *root, void *ctx, void (*f)(void *ctx, void *data));
void			btree_free(t_btree *root);

#endif
