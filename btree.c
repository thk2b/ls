/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:13:07 by tkobb             #+#    #+#             */
/*   Updated: 2018/09/15 20:39:25 by tkobb            ###   ########.fr       */
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

void	btree_in_order(t_btree *root, void (*f)(void*))
{
	if (root == NULL)
		return ;
	btree_in_order(root->left, f);
	f(root->data);
	btree_in_order(root->right, f);
}

void	btree_in_back_order(t_btree *root, void (*f)(void*))
{
	if (root == NULL)
		return ;
	btree_in_back_order(root->right, f);
	f(root->data);
	btree_in_back_order(root->left, f);
}

void	btree_free(t_btree* root)
{
	if (root == NULL)
		return ;
	btree_free(root->right);
	free(root);
	btree_free(root->left);
}
/*
#include <string.h>
#include <stdio.h>

int	cmp(void* a, void* b)
{
	return (strcmp((char*)a, (char*)b));
}

void	print(void* s)
{
	printf("%s\n", (char*)s);
}

int main(void)
{
	t_btree *root;
	char s[] = "abc";
	char s1[] = "aac";
	char d[] = "xyz";
	char t[] = "mno";

	root = NULL;
	btree_add(&root, (void*)s, cmp);
	btree_add(&root, (void*)d, cmp);
	btree_add(&root, (void*)t, cmp);
	btree_add(&root, (void*)s1, cmp);
	btree_in_order(root, print);
	btree_in_back_order(root, print);
	btree_free(root);
}
*/
