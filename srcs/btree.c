/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:12:23 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/25 18:04:55 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdlib.h>

t_btree	*btree_new(void *data)
{
	t_btree	*root;

	if ((root = (t_btree*)malloc(sizeof(t_btree))) == NULL)
		return (NULL);
	root->left = NULL;
	root->right = NULL;
	root->data = data;
	return (root);
}

void	btree_add(t_btree **root, void *ctx, void *data,
	t_btree_cmpfn cmp)
{
	t_btree	**nodep;

	nodep = root;
	while (*nodep)
	{
		if (cmp(ctx, data, (*nodep)->data) > 0)
			nodep = &(*nodep)->right;
		else
			nodep = &(*nodep)->left;
	}
	*nodep = btree_new(data);
}

void	btree_inorder(t_btree *root, void *ctx,
	t_btree_fn f)
{
	if (root == NULL)
		return ;
	btree_inorder(root->left, ctx, f);
	f(ctx, root->data);
	btree_inorder(root->right, ctx, f);
}

void	btree_back_inorder(t_btree *root, void *ctx,
	t_btree_fn f)
{
	if (root == NULL)
		return ;
	btree_back_inorder(root->right, ctx, f);
	f(ctx, root->data);
	btree_back_inorder(root->left, ctx, f);
}

void	btree_free(t_btree *root, void *ctx,
	t_btree_freefn del)
{
	if (root == NULL)
		return ;
	btree_free(root->left, ctx, del);
	btree_free(root->right, ctx, del);
	del(ctx, root->data);
	free(root);
}
