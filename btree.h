/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:03:17 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/25 18:17:35 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

typedef struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*data;
}				t_btree;

typedef int		(*t_btree_cmpfn)(void *ctx, void*, void*);
typedef void	(*t_btree_fn)(void *ctx, void*);
typedef void	(*t_btree_freefn)(void *ctx, void*);

t_btree			*btree_new(void *data);
void			btree_add(t_btree **root, void *ctx, void *data,
	t_btree_cmpfn cmp);
void			btree_inorder(t_btree *root, void *ctx,
	t_btree_fn f);
void			btree_back_inorder(t_btree *root, void *ctx,
	t_btree_fn f);
void			btree_free(t_btree *root, void *ctx,
	t_btree_freefn f);

#endif
