/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_inorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:49:12 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/18 20:03:28 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_inorder(t_btree *root, void *ctx,
	void (*f)(void *ctx, void*))
{
	if (root == NULL)
		return ;
	ft_btree_preorder(root->left, ctx, f);
	f(ctx, root->data);
	ft_btree_preorder(root->right, ctx, f);
}
