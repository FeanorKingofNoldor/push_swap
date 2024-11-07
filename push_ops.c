/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuthmay <mhuthmay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:03:15 by mhuthmay          #+#    #+#             */
/*   Updated: 2024/11/05 13:03:32 by mhuthmay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *dst, t_stack *src)
{
	t_node	*node_to_push;

	if (!src || !src->head)
		return ;
	node_to_push = src->head;
	src->head = src->head->next;
	if (src->head)
		src->head->prev = NULL;
	else
		src->tail = NULL;
	src->size--;
	node_to_push->next = dst->head;
	node_to_push->prev = NULL;
	if (dst->head)
		dst->head->prev = node_to_push;
	else
		dst->tail = node_to_push;
	dst->head = node_to_push;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putendl_fd("pb", 1);
}
