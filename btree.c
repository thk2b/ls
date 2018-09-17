/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:13:07 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/17 11:48:45 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_btree	*btree_new(void *data)
{
	t_btree *node;

	if ((node = (t_btree*)malloc(sizeof(t_btree))) == NULL)
		return (NULL);
	node->right = NULL;
	node->left = NULL;
	node->data = data;
	return (node);
}

t_btree	*btree_add(t_btree **root, void *data, int (*cmp)(void*, void*))
{
	t_btree	**curr;

	if (*root == NULL)
		return (*root = btree_new(data));
	curr = root;
	while (*curr != NULL)
		if (cmp(data, (*curr)->data) > 0)
			curr = &(*curr)->right;
		else
			curr = &(*curr)->left;
	return (*curr = btree_new(data));
}

void	btree_in_order(t_btree *root, void *ctx, void (*f)(void*, void*))
{
	if (root == NULL)
		return ;
	btree_in_order(root->left, ctx, f);
	f(ctx, root->data);
	btree_in_order(root->right, ctx, f);
}

void	btree_in_back_order(t_btree *root, void *ctx, void (*f)(void*, void*))
{
	if (root == NULL)
		return ;
	btree_in_back_order(root->right, ctx, f);
	f(ctx, root->data);
	btree_in_back_order(root->left, ctx, f);
}

void	btree_free(t_btree *root)
{
	if (root == NULL)
		return ;
	btree_free(root->right);
	free(root);
	btree_free(root->left);
}
