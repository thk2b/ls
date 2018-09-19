/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_backpostorder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:54:47 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/18 20:02:20 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_backpostorder(t_btree *root, void *ctx,
	void (*f)(void *ctx, void*))
{
	if (root == NULL)
		return ;
	ft_btree_preorder(root->left, ctx, f);
	ft_btree_preorder(root->right, ctx, f);
	f(ctx, root->data);
}
