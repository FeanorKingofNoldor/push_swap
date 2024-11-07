/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuthmay <mhuthmay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:46:07 by mhuthmay          #+#    #+#             */
/*   Updated: 2024/11/05 13:47:08 by mhuthmay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_count(int size)
{
	int	chunks;

	if (size <= 10)
		chunks = 2;
	else if (size <= 50)
		chunks = 2;
	else if (size <= 100)
		chunks = 5;
	else
		chunks = 5;
	return (chunks);
}

static void	handle_b_organization(t_stack *a, t_stack *b)
{
	int	max_b;
	int	pushing_val;

	if (b->size < 2)
	{
		pb(a, b);
		return ;
	}
	max_b = get_max(b);
	pushing_val = a->head->value;
	if (pushing_val > b->head->value && pushing_val < max_b)
	{
		pb(a, b);
		rb(b);
		return ;
	}
	else if (pushing_val < b->head->value
		&& b->head->value > b->head->next->value)
	{
		pb(a, b);
		sb(b);
		return ;
	}
	pb(a, b);
}

void	optimize_push(t_stack *a, t_stack *b, int pos)
{
	if (pos <= a->size / 2)
	{
		while (pos--)
			ra(a);
	}
	else
	{
		while (pos++ < a->size)
			rra(a);
	}
	handle_b_organization(a, b);
}

void	smart_rotate_b(t_stack *b, int target)
{
	int		pos;
	t_node	*current;
	int		i;

	pos = 0;
	current = b->head;
	i = 0;
	while (current)
	{
		if (current->value == target)
			pos = i;
		i++;
		current = current->next;
	}
	if (pos <= b->size / 2)
	{
		while (pos--)
			rb(b);
	}
	else
	{
		while (pos++ < b->size)
			rrb(b);
	}
}
