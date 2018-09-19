/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_postorder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 19:54:00 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/18 20:01:42 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_postorder(t_btree *root, void *ctx,
	void (*f)(void *ctx, void*))
{
	if (root == NULL)
		return ;
	ft_btree_preorder(root->left, ctx, f);
	ft_btree_preorder(root->right, ctx, f);
	f(ctx, root->data);
}
